#include "foto.h"

void handleEvent(Object *foto)
{
	const Uint8 *currentKeyStates = SDL_GetKeyboardState(NULL);
	
	if (currentKeyStates[SDL_SCANCODE_LEFT])
		foto->posX--;

	if (currentKeyStates[SDL_SCANCODE_RIGHT])
		foto->posX++;
	
	if (currentKeyStates[SDL_SCANCODE_UP])
		foto->posY--;

	if (currentKeyStates[SDL_SCANCODE_DOWN])
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