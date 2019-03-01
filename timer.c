#include <stdio.h>
#include <SDL2/SDL.h>
#include "timer.h"

#define SCREEN_FPS 60
#define SCREEN_TICKS_PER_FRAME  (1000 / SCREEN_FPS)

int seconds = 0, countedFrames = 0;
float avgFPS = 0;

void timer()
{
	countedFrames++;
	seconds = SDL_GetTicks() / 1000;
	printf("%d\n", seconds);
	avgFPS = countedFrames / (float)seconds;	//creare file timer!
	printf("FPS: %f\n", avgFPS);
		
		if (avgFPS > 2000)
			avgFPS = 0;
}


			/*countedFrames++;printf("ticks %d\n", SDL_GetTicks());
int ticks = SDL_GetTicks();								FILE TIMER
			if (ticks < SCREEN_TICKS_PER_FRAME)
				SDL_Delay(SCREEN_TICKS_PER_FRAME - ticks);*/