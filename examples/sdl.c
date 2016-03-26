#include <stdio.h>
#include <SDL2/SDL.h>
#include "ugui.h"

#define DISPLAY_COLS 240
#define DISPLAY_ROWS 340

uint32_t display[DISPLAY_COLS*DISPLAY_ROWS];

extern void ui_setup(void);
extern void ui_loop(void);

void PixelFunc(UG_S16 x, UG_S16 y, UG_COLOR c){
	display[(y*DISPLAY_COLS)+x] = (c<<8);
}

int main(int argc, char **argv){

	UG_GUI gui;

	UG_Init(&gui, PixelFunc, DISPLAY_COLS, DISPLAY_ROWS);
	UG_SelectGUI(&gui);

	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		fprintf(stderr, "Unable to initialize SDL: %s\n", SDL_GetError());
		return 1;
	}

	SDL_Window   * window = SDL_CreateWindow("uGUI simulator", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, DISPLAY_COLS, DISPLAY_ROWS, 0);
	SDL_Renderer * render = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
	SDL_Texture  * texture = SDL_CreateTexture(render, SDL_PIXELFORMAT_RGBA8888, SDL_TEXTUREACCESS_STATIC, DISPLAY_COLS, DISPLAY_ROWS);

	memset(display, 0x00, sizeof(uint32_t)*DISPLAY_COLS*DISPLAY_ROWS);

	ui_setup();

	SDL_UpdateTexture(texture, NULL, display, DISPLAY_COLS*sizeof(uint32_t));
	SDL_RenderCopy(render, texture, NULL, NULL);
	SDL_RenderPresent(render);

	while (1){

		SDL_Event event;

		for (; SDL_PollEvent(&event); ){
			switch(event.type){
				case SDL_MOUSEBUTTONDOWN:
					UG_TouchUpdate(event.button.x, event.button.y, TOUCH_STATE_PRESSED);
					break;
				case SDL_MOUSEBUTTONUP:
					UG_TouchUpdate(-1, -1, TOUCH_STATE_RELEASED);
					break;
				case SDL_QUIT:
					return 0;
				default:
					break;
			}
		}

		ui_loop();
		UG_Update();
		SDL_UpdateTexture(texture, NULL, display, DISPLAY_COLS*sizeof(uint32_t));
		SDL_RenderCopy(render, texture, NULL, NULL);
		SDL_RenderPresent(render);
		SDL_Delay(40);
	}
}
