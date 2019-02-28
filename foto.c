#include "foto.h"
#include <stdio.h>

void initialize(Foto *foto)
{
	foto->texture = NULL;
	foto->loadedSurface = IMG_Load("./media/codice.png");

	if (foto->loadedSurface == NULL)
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
		*currentSurface = foto->loadedSurface;
}

void render(Foto *foto, SDL_Renderer *renderer)
{
	SDL_Rect rect = { 100, 200, 300, 400 };
	foto->texture = SDL_CreateTextureFromSurface(renderer, foto->loadedSurface);
	SDL_RenderCopy(renderer, foto->texture, NULL, &rect);	//erect lol
}