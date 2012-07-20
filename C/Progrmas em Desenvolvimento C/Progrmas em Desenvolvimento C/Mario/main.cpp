/*This source code copyrighted by Lazy Foo' Productions (2004-2009) and may not
be redestributed without written permission.*/

//The headers
#include <cstdlib>
#include <iostream>
#include "SDL/SDL.h"
#include <SDL/SDL_image.h>
#include <string>
#include <vector>

#include "Utils.h"

using namespace std;

#define WIDTH  	1024
#define HEIGHT  768
#define DEPTH   32
#define FPS     60

//Globals
bool g_bEndGame = false;
SDL_Surface *g_pScreen = NULL;
SDL_Surface *g_pEntity = NULL;
vector <SDL_Rect> m_vRect;
//End of Globals

int Initialize()
{
    //Initialize all SDL subsystems
    if( SDL_Init( SDL_INIT_EVERYTHING ) == -1 )
    {
        return 1;
    }

    //Set up the screen
    g_pScreen = SDL_SetVideoMode( WIDTH, HEIGHT, DEPTH, SDL_HWSURFACE | SDL_DOUBLEBUF );

    //If there was an error in setting up the screen
    if( g_pScreen == NULL )
    {
        return 1;
    }

    //Set the window caption
    SDL_WM_SetCaption( "WiLL", NULL );

}
void Render()
{
    SDL_FillRect(g_pScreen,&g_pScreen->clip_rect,SDL_MapRGB(g_pScreen->format,0x00,0x00,0x00));

    g_pEntity = LoadIMG("mario.bmp");

    if (g_pEntity==NULL)
    {
        cerr<<"LoadIMG error" << endl;
        exit(-13);
}

    for(int i = 0; i < g_pEntity->w/24;i++){
				SDL_Rect r;
				r.x = i*37,5;
				r.y = 0;
				r.w = 37,5;
				r.h = 24;
				m_vRect.push_back(r);
			}



    apply_surface(5,5,g_pEntity,g_pScreen,&m_vRect[4]);

    if(SDL_Flip(g_pScreen)== -1)
    {
        cerr<<"Flip error" << endl;
        exit(-12);
    }
}

void HandleInput()
{

}

void Update()
{

}

void Release()
{
	SDL_FreeSurface(g_pScreen);
	SDL_FreeSurface(g_pEntity);
}


int main(int argc, char *argv[])
{


    int startticks = 0, fpsticks = 0;

    Initialize();

    do
    {

        startticks = SDL_GetTicks();

        HandleInput();

        Update(/*SDL_GetTicks()-startticks*/ );

        Render();

        fpsticks = SDL_GetTicks() - startticks;

        if(fpsticks < 1000/FPS)
        {

            SDL_Delay((1000/FPS-fpsticks));

        }

    }
    while( !g_bEndGame );

    Release();

    return EXIT_SUCCESS;
}
