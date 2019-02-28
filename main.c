#include "init.h"
#include "foto.h"

#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME  (1000 / SCREEN_FPS)
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
	int seconds = 0, countedFrames = 0;
	float avgFPS = 0;
	
	if (init(&window, &screenSurface) == false)
	{
		fprintf(stderr, "Failed to initialize\n");
		return 0;
	}
	
	else
	{
		renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

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

			countedFrames++;
			seconds = SDL_GetTicks() / 1000;
			printf("%d\n", seconds);
			avgFPS = countedFrames / (float)seconds;	//creare file timer!
			printf("FPS: %f\n", avgFPS);

			if (avgFPS > 200000000)
				avgFPS = 0;

			handleEvent(&foto, &currentSurface);

			SDL_RenderClear(renderer);
			render(&foto, renderer);

			SDL_RenderPresent(renderer);

			/*countedFrames++;printf("ticks %d\n", SDL_GetTicks());
int ticks = SDL_GetTicks();
			if (ticks < SCREEN_TICKS_PER_FRAME)
				SDL_Delay(SCREEN_TICKS_PER_FRAME - ticks);*/
		}
	}

	endSession(&window, image);

	return 0;
}
