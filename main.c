#include "init.h"
#include "object.h"
#include "timer.h"

#define TOTAL_KEYS 2

typedef enum {false, true} bool;

int main()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *screenSurface, *image[TOTAL_KEYS];
	SDL_Event event;
	Object foto;
	
	bool quit = false;
	
	if (init(&window, &screenSurface) == false)
	{
		fprintf(stderr, "Failed to initialize\n");
		return 0;
	}
	
	else
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
		
		initialize(renderer, &foto, "./media/mini.png");

		while (!quit)
		{
			if ((SDL_PollEvent(&event) != 0) && (event.type == SDL_QUIT))
				quit = true;				

			handleEvent(&foto);

			SDL_RenderClear(renderer);
			render(&foto, renderer);

			SDL_RenderPresent(renderer);

			timer();
		}
	}

	endSession(&window, image);

	return 0;
}
