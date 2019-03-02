#ifndef OBJECT_H
#define OBJECT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

typedef struct object
{
	SDL_Surface *loadedSurface;
	SDL_Texture *texture;
	SDL_Rect collisionBox;
	int width;
	int height;
	int posX;
	int posY;
} Object;

void initialize(SDL_Renderer *renderer, Object *object, char* path);

int checkCollision(Object *obj1, Object *obj2);

void render(Object *object, SDL_Renderer *renderer);

#endif