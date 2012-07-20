/*This source code copyrighted by Lazy Foo' Productions (2004-2009) and may not
be redestributed without written permission.*/

//The headers
#include "SDL/SDL.h"
#include <string>

#include "Utils.h"

#define WIDTH  	1024
#define HEIGHT  768
#define DEPTH   32
#define FPS     60

//Globals
bool g_bEndGame = false;
SDL_Surface *g_pScreen = NULL;
//End of Globals

int Initialize() {
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
    SDL_WM_SetCaption( "Hello World", NULL );
}
void Render() {

}

void HandleInput() {

}

void Update() {

}

void Release() {

}


int main(int argc, char *argv[]) {


	int startticks = 0, fpsticks = 0;

	Initialize();

	do {

		startticks = SDL_GetTicks();

		HandleInput();

		Update(/*SDL_GetTicks()-startticks*/ );

		Render();

		fpsticks = SDL_GetTicks() - startticks;

		if(fpsticks < 1000/FPS) {

			SDL_Delay((1000/FPS-fpsticks));

		}

	} while( !g_bEndGame );

	Release();

    return EXIT_SUCCESS;
}
