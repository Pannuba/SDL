#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#ifndef FOTO_H
#define FOTO_H

typedef struct foto
{
	SDL_Surface *immagine;
	int posX;
	int posY;
} Foto;

void initialize(Foto *foto);

void handleEvent(Foto *foto, SDL_Surface **currentSurface);


#endif