#include "object.h"
#include <stdio.h>

void initialize(SDL_Renderer *renderer, Object *object, char* path)
{
	object->texture = NULL;
	//object->collisionBox = NULL;
	object->loadedSurface = IMG_Load(path);

	if (object->loadedSurface == NULL)
	{
		fprintf(stderr, "Cannot load %s: %s\n", path, SDL_GetError());
		return;
	}

	object->texture = SDL_CreateTextureFromSurface(renderer, object->loadedSurface);

	object->width = object->loadedSurface->w;
	object->height = object->loadedSurface->h;

	object->posX = 0; //!!!!!!!!!!!! mettere in foto? o aggiongo parametri
	object->posY = 0;//!!!!!!!!!!!!

	object->collisionBox.w = object->width;		//se Rect * ->, altrimenti .
	object->collisionBox.h = object->height;
	object->collisionBox.x = object->posX;
	object->collisionBox.y = object->posY;
}

int checkCollision(Object *obj1, Object *obj2)
{
	int right1, right2, left1, left2, top1, top2, bottom1, bottom2; //mettere in object struct?
	
	left1 = obj1->posX;
	right1 = obj1->posX + obj1->width;
	top1 = obj1->posY;
	bottom1 = obj1->posY + obj1->height;

	left2 = obj2->posX;
	right2 = obj2->posX + obj2->width;
	top2 = obj2->posY;
	bottom2 = obj2->posY + obj2->height;

	if (bottom1 <= top2)
	{
		return 0;
	}

	if (top1 >= bottom2)
	{
		return 0;
	}

	if (right1 <= left2)
	{
		return 0;
	}

	if (left1 >= right2)
	{
		return 0;
	}

	return 1;
}

void render(Object *object, SDL_Renderer *renderer)
{
	SDL_Rect rect = {object->posX, object->posY, object->width, object->height};
	SDL_RenderCopy(renderer, object->texture, NULL, &rect);	//erect lol
}