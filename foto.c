#include "foto.h"
#include <stdio.h>

void initialize(Foto *foto)
{
	foto->immagine = IMG_Load("./media/codice.png");

	if (foto->immagine == NULL)
	{
		fprintf(stderr, "Cannot load codice.png: %s\n", SDL_GetError());
		return;
	}

	foto->posX = 0;
	foto->posY = 0;
}

void handleEvent(Foto *foto, SDL_Surface **currentSurface)
{/*
	switch (event->key.keysym.sym)
	{
		case SDLK_LEFT:
			printf("LEFT\n");
			*currentSurface = foto->immagine;
			break;
	}*/
	const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
	if (currentKeyStates[SDL_SCANCODE_LEFT])
		*currentSurface = foto->immagine;
}
