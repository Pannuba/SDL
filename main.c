#include "init.h"
#include "foto.h"

#define TOTAL_KEYS 2

typedef enum {false, true} bool;

int main()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface *screenSurface, *currentSurface = NULL, *image[TOTAL_KEYS];
	SDL_Event event;
	Foto foto;
	initialize(&foto);
	bool quit = false;
	
	if (init(&window, &screenSurface) == false)
	{
		fprintf(stderr, "Failed to initialize\n");
		return 0;
	}
	
	else
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

		if (loadMedia(image) == false)
		{
			fprintf(stderr, "Failed to load media\n");
			return 0;
		}

		while (!quit)
		{
			while (SDL_PollEvent(&event) != 0)
			{
				if (event.type == SDL_QUIT)
					quit = true;				
			}

			handleEvent(&foto, &currentSurface);

			SDL_RenderClear(renderer);
			render(&foto, renderer);
			SDL_RenderPresent(renderer);
		}
	}

	endSession(&window, image);

	return 0;
}
