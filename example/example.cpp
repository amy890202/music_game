#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "SDL.h" // Using SDL
#include "SDL2_gfxPrimitives.h" // Using SDL2_gfx
#include "SDL_mixer.h" // Using SDL2_mixer
// Screen dimension constants
const int WIDTH = 1600;
const int HEIGHT = 1000;
// Numbers of Fischinger components
const int WNUM = 16;
const int HNUM = 11;
struct Fischinger
{
	bool activate; // true: selected by user, false: deselected by user
	bool runActivate; // true: playing tone, false: not playing tone
	int w; // width
	int h; // height
	char tonePath[100]; // path of tone file
	Mix_Chunk *tone; // tone
	//Mix_Music *tone;
	// for visual effect
	bool effectActivate; // true: playing effect
	int r; // radius of effect
	int alpha; // alpha channel
	int cr, cg, cb; // colors of r, g ,b
};
int initSDL(); // Starts up SDL and creates window
void closeSDL(); // Frees media and shuts down SDL
void drawFischinger(SDL_Renderer *renderer, Fischinger fcg[HNUM][WNUM]);
Uint32 runPlay(Uint32 interval, void *param);
Uint32 runEffect(Uint32 interval, void *param);
void mouseHandleEvent(SDL_Event *e, Fischinger fcg[HNUM][WNUM]);
SDL_Window *window = NULL; // The window we'll be rendering to
SDL_Renderer *renderer = NULL; // The window renderer
// array of Fischinger components
Fischinger fcg[HNUM][WNUM];
int initSDL()
{
	// Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) != 0)
	{
		// Error Handling
		printf("SDL_Init failed: %s\n", SDL_GetError());
		return 1;
	}
	// Create window
	// SDL_WINDOWPOS_UNDEFINED: Used to indicate that you don't care what the window position is.
	window = SDL_CreateWindow("OOP SDL Tutorial", 50, 50, WIDTH, HEIGHT, SDL_WINDOW_SHOWN);
	if (window == NULL)
	{
		printf("SDL_CreateWindow failed: %s\n", SDL_GetError());
		SDL_Quit();
		return 2;
	}
	// Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 8, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		return 5;
	}
	// Create renderer
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED |
		SDL_RENDERER_PRESENTVSYNC);
	if (renderer == NULL)
	{
		SDL_DestroyWindow(window);
		printf("SDL_CreateRenderer failed: %s\n", SDL_GetError());
		SDL_Quit();
		return 6;
	}
	return 0;
}
void closeSDL()
{
	// Free the sound effects
	for (int i = 0; i < HNUM; i++)
	{
		for (int j = 0; j < WNUM; j++)
		{
			//Mix_FreeMusic(fcg[i][j].tone);
			Mix_FreeChunk(fcg[i][j].tone);
		}
	}
	// Destroy renderer
	// Destroy window
	// Quit Image subsystem
	// Quit SDL subsystems
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	// Shutdown subsystem
	Mix_Quit();
	SDL_Quit();
}
// Draw visual music on renderer according to parameters of Fischinger components
// 1. Draw basic components or activate components or runActivate components according to
//activate / runActivate status of Fischinger components
// 2. Draw visual effects according to effectActivate status of Fischinger components
void drawFischinger(SDL_Renderer *renderer, Fischinger fcg[HNUM][WNUM])
{
	for (int i = 0; i < HNUM; i++)
		for (int j = 0; j < WNUM; j++)
		{
			if (fcg[i][j].activate == true)
			{
			
				filledCircleRGBA(renderer, WIDTH / WNUM * j, HEIGHT / HNUM * i, fcg[i][j].r, fcg[i][j].cr, fcg[i][j].cg, fcg[i][j].cb, fcg[i][j].alpha);//8
			}
			else if (fcg[i][j].runActivate == true)
			{
				filledCircleRGBA(renderer, WIDTH / WNUM * j, HEIGHT / HNUM * i, fcg[i][j].r, fcg[i][j].cr, fcg[i][j].cg, fcg[i][j].cb, fcg[i][j].alpha);//8
			}
			else
			{
				circleRGBA(renderer, WIDTH / WNUM * j, HEIGHT / HNUM * i, fcg[i][j].r, fcg[i][j].cr, fcg[i][j].cg, fcg[i][j].cb, fcg[i][j].alpha);//8
			}

		}


}
// Timer callback function
// 1. Update runActivate status of Fischinger components
// 2. Play tone and update effectActivate status according to active status of Fischinger components
//Uint32 runPlay(Uint32 interval, void *param)
//{
	/* implement it */
//}

// Timer callback function
// 1. Update visual effects parameters according to effectActivate status of Fischinger components
// 2. Reset visual effects parameters of Fischinger components if the stop requirement of effect meets
//Uint32 runEffect(Uint32 interval, void *param)
//{
	/* implement it */
//}
// Mouse event handler
// Update activate status of Fischinger components when click on corresponding area of screen
void mouseHandleEvent(SDL_Event *e, Fischinger fcg[HNUM][WNUM])
{
	/* implement it */
}
// When using SDL, you have to use "int main(int argc, char* args[])"
// int main() and void main() are not allowed
static char tochar(int value)
{
	return 's0' + value;//This is the part i don't understand
}
int main(int argc, char* args[])
{
	// Initialize path of tone wave files
	/* implement it */
	for (int j = 0; j < WNUM; j++)
	{
		strcpy_s(fcg[0][j].tonePath, "../audio/c01.wav");
		strcpy_s(fcg[1][j].tonePath, "../audio/c02.wav");
		strcpy_s(fcg[2][j].tonePath, "../audio/c03.wav");
		strcpy_s(fcg[3][j].tonePath, "../audio/c04.wav");
		strcpy_s(fcg[4][j].tonePath, "../audio/c05.wav");
		strcpy_s(fcg[5][j].tonePath, "../audio/c06.wav");
		strcpy_s(fcg[6][j].tonePath, "../audio/c07.wav");
		strcpy_s(fcg[7][j].tonePath, "../audio/c08.wav");
		strcpy_s(fcg[9][j].tonePath, "../audio/c10.wav");
		strcpy_s(fcg[10][j].tonePath, "../audio/c011.wav");
		strcpy_s(fcg[8][j].tonePath, "../audio/c09.wav");

	}
		// Start up SDL and create window
	if (initSDL())
	{
		printf("Failed to initialize SDL!\n");
		return -1;
	}
	// Initialize all Fischinger components
	for (int i = 0; i < HNUM; i++)
		for (int j = 0; j < WNUM; j++)
		{
			fcg[i][j].activate = false; // true: selected by user, false: deselected by user
			fcg[i][j].runActivate = false; // true: playing tone, false: not playing tone
			fcg[i][j].w = WIDTH / WNUM * j; // width
			fcg[i][j].h = HEIGHT / HNUM * i; // height
		//	strcpy(fcg[i][j].tonePath , "../audio/c01.wav"); // path of tone file
			fcg[i][j].tone = Mix_LoadWAV(fcg[i][j].tonePath); // tone
			//music1 = Mix_LoadMUS("../audio/m01.wav");
			//Mix_Music *tone;
			// for visual effect
			fcg[i][j].effectActivate = false; // true: playing effect
			fcg[i][j].r = 2; // radius of effect
			fcg[i][j].alpha = 255; // alpha channel
			fcg[i][j].cr = 255;
			fcg[i][j].cg = 0;
			fcg[i][j].cb = 0; // colors of r, g ,b
		}

	// Settings of timer callback function
	/* implement it */
	bool quit = false; // Main loop flag
	SDL_Event e; // Event handler
	// While application is running
//	MouseState mouseState;
	//int mouseX, mouseY;
	while (!quit)
	{
		//mouseState = NONE;
		// Handle events on queue
		while (SDL_PollEvent(&e) != 0)
		{
			// User requests quit
			if (e.type == SDL_QUIT)
			{
				quit = true;
			}
			// call mouse event handler
			/* implement it */
		}
		// Clear screen
		SDL_SetRenderDrawColor(renderer, 0, 0, 0, 0xFF);
		SDL_RenderClear(renderer);
		// Draw visual music on renderer according to parameters of Fischinger components
		/* implement it */
		// Update screen
		SDL_RenderPresent(renderer);
	}
	//Free resources and close SDL
	closeSDL();
	return 0;
}