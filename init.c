#include "init.h"

#define SCREEN_WIDTH 640
#define SCREEN_HEIGHT 480

enum keypresses
{
	KEY_LEFT,
	KEY_RIGHT,
};

int init(SDL_Window **window, SDL_Renderer **renderer)
{
	int imgFlags = IMG_INIT_PNG;

	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		fprintf(stderr, "Cannot initialize SDL: %s\n", SDL_GetError());
		return 0;
	}

	*window = SDL_CreateWindow("Tom & Jerry funny animations", SDL_WINDOWPOS_UNDEFINED,
				SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
	
	if (*window == NULL)
	{
		fprintf(stderr, "Cannot create window: %s\n", SDL_GetError());
		return 0;
	}

	*renderer = SDL_CreateRenderer(*window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (*renderer == NULL)
	{
		fprintf(stderr, "Cannot create renderer: %s\n", SDL_GetError());
		return 0;
	}

	if ((IMG_Init(imgFlags) & imgFlags) == 0)
	{
		fprintf(stderr, "Cannot initialize image: %s\n", IMG_GetError());
		return 0;
	}

	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048 ) < 0)
	{
		fprintf(stderr, "Cannot initialize SDL_mixer: %s\n", Mix_GetError());
		return 0;
	}

	return 1;
}

//int loadMedia(SDL_Surface *image[])	/* And that's how ya do it, bois */
//{
	/*image[KEY_LEFT] = SDL_LoadBMP("./media/preview.bmp");
	image[KEY_RIGHT] = IMG_Load("./media/preview.png");

	if (image[KEY_LEFT] == NULL || image[KEY_RIGHT] == NULL)
	{
		fprintf(stderr, "Cannot load preview.bmp or preview.png: %s\n", SDL_GetError());
		return 0;
	}*/

	

//	return 1;
//}

void endSession(SDL_Window **window, SDL_Surface **image)
{
	SDL_FreeSurface(*image);
	*image = NULL;
	SDL_DestroyWindow(*window);
	*window = NULL;
	SDL_Quit();
}
