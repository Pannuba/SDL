#ifndef INIT_H
#define INIT_H

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <SDL2/SDL_mixer.h>

int init(SDL_Window **window,  SDL_Renderer **renderer);

//int loadMedia(SDL_Surface *image[]);

void endSession(SDL_Window **window, SDL_Surface **image);

#endif
