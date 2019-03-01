#include "foto.h"

void handleEvent(Object *foto, Uint8 dir1, Uint8 dir2, Uint8 dir3, Uint8 dir4)
{
	const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
	
	if (currentKeyStates[dir3])
		foto->posX--;

	if (currentKeyStates[dir4])
		foto->posX++;
	
	if (currentKeyStates[dir1])
		foto->posY--;

	if (currentKeyStates[dir2])
		foto->posY++;
	
	if (currentKeyStates[SDL_SCANCODE_LEFT] && currentKeyStates[SDL_SCANCODE_LSHIFT])
		foto->posX = foto->posX - 8;

	if (currentKeyStates[SDL_SCANCODE_RIGHT] && currentKeyStates[SDL_SCANCODE_LSHIFT])
		foto->posX = foto->posX + 8;
	
	if (currentKeyStates[SDL_SCANCODE_UP] && currentKeyStates[SDL_SCANCODE_LSHIFT])
		foto->posY = foto->posY - 8;

	if (currentKeyStates[SDL_SCANCODE_DOWN] && currentKeyStates[SDL_SCANCODE_LSHIFT])
		foto->posY = foto->posY + 8;
}