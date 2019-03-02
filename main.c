#include "init.h"
#include "object.h"
#include "timer.h"
#include "foto.h"
#include <SDL2/SDL_mixer.h>

#define TOTAL_KEYS 2

typedef enum {false, true} bool;

int main()
{
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Surface  *image[TOTAL_KEYS];
	SDL_Event event;
	Object fotoInt, fotoIf;

	Mix_Music *music = NULL;
	
	bool quit = false;
	
	if (!init(&window, &renderer))
	{
		fprintf(stderr, "Failed to initialize\n");
		return 0;
	}
	
	else
	{	
		music = Mix_LoadMUS("./media/music.mp3");
		Mix_PlayMusic(music, 1);
		initialize(renderer, &fotoInt, "./media/mini.png");
		initialize(renderer, &fotoIf, "./media/if.png");

		while (!quit)
		{
			if ((SDL_PollEvent(&event) != 0) && (event.type == SDL_QUIT))
				quit = true;				

			handleEvent(&fotoInt, SDL_SCANCODE_W, SDL_SCANCODE_S, SDL_SCANCODE_A, SDL_SCANCODE_D);
			handleEvent(&fotoIf, SDL_SCANCODE_UP, SDL_SCANCODE_DOWN, SDL_SCANCODE_LEFT, SDL_SCANCODE_RIGHT);

			SDL_RenderClear(renderer);
			render(&fotoInt, renderer);
			render(&fotoIf, renderer);

			SDL_RenderPresent(renderer);

			//timer();
		}
	}

	endSession(&window, image);

	return 0;
}
