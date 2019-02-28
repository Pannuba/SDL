#include "foto.h"
#include <stdio.h>

void initialize(Foto *foto)
{
	foto->texture = NULL;
	foto->loadedSurface = IMG_Load("./media/mini.png");

	if (foto->loadedSurface == NULL)
	{
		fprintf(stderr, "Cannot load codice.png: %s\n", SDL_GetError());
		return;
	}

	foto->width = foto->loadedSurface->w;
	foto->height = foto->loadedSurface->h;

	foto->posX = 0;
	foto->posY = 0;
}

void handleEvent(Foto *foto, SDL_Surface **currentSurface)
{
	const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
	
	if (currentKeyStates[SDL_SCANCODE_LEFT])
	{
		foto->posX--;
		//*currentSurface = foto->loadedSurface; carico già in initialize
	}

	if (currentKeyStates[SDL_SCANCODE_RIGHT])
		foto->posX++;
	
	if (currentKeyStates[SDL_SCANCODE_UP])
		foto->posY--;

	if (currentKeyStates[SDL_SCANCODE_DOWN])
		foto->posY++;
}

void render(Foto *foto, SDL_Renderer *renderer)
{
	SDL_Rect rect = {foto->posX, foto->posY, foto->width, foto->height};
	foto->texture = SDL_CreateTextureFromSurface(renderer, foto->loadedSurface);
	SDL_RenderCopy(renderer, foto->texture, NULL, &rect);	//erect lol
}