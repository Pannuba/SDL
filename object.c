#include "object.h"
#include <stdio.h>

void initialize(SDL_Renderer *renderer, Object *object, char* path)
{
	object->texture = NULL;
	object->loadedSurface = IMG_Load(path);

	if (object->loadedSurface == NULL)
	{
		fprintf(stderr, "Cannot load %s: %s\n", path, SDL_GetError());
		return;
	}

	object->texture = SDL_CreateTextureFromSurface(renderer, object->loadedSurface);

	object->width = object->loadedSurface->w;
	object->height = object->loadedSurface->h;

	object->posX = 0;
	object->posY = 0;
}

void render(Object *object, SDL_Renderer *renderer)
{
	SDL_Rect rect = {object->posX, object->posY, object->width, object->height};
	SDL_RenderCopy(renderer, object->texture, NULL, &rect);	//erect lol
}