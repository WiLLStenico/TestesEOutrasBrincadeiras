
/*
 * File:   Utils.h
 * Author: WiLL
 *
 * Created on 2 de Dezembro de 2010, 22:32
 */

#ifndef UTILS_H
#define	UTILS_H

#include "SDL/SDL.h"
#include "SDL/SDL_image.h"


SDL_Surface *LoadIMG( const char* arquivo){

    SDL_Surface* loadedImage = NULL;

    SDL_Surface* optimizedImage = NULL;

    loadedImage = IMG_Load(arquivo);

    if( loadedImage != NULL ){
        optimizedImage = SDL_DisplayFormat( loadedImage );

        SDL_FreeSurface( loadedImage );

        if( optimizedImage != NULL ){
			SDL_SetColorKey( optimizedImage, SDL_SRCCOLORKEY | SDL_ALPHA_TRANSPARENT | SDL_RLEACCEL, SDL_MapRGB( optimizedImage->format, 255,255,255/*0xFF, 0x00, 0xFF*/ ) );
		}
    }

    return optimizedImage;
}

SDL_Rect EntityArea(){

}

void apply_surface( int x, int y, SDL_Surface* source, SDL_Surface* destination, SDL_Rect* clip = NULL ) {

     SDL_Rect offset;

     offset.x = x;
     offset.y = y;

     SDL_BlitSurface( source, clip, destination, &offset );
}


#endif	/* UTILS_H */

