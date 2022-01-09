#pragma once
#ifndef SCREEN_H_
#define SCREEN_H_
#include<SDL.h>

namespace vaibhav {
	class Screen
	{
	public:
		const static int SCREEN_WIDTH = 1200;
		const static int SCREEN_HEIGHT = 1000;
	private:
		SDL_Window *m_window;
		SDL_Renderer *m_renderer;
		SDL_Texture *m_texture;
		Uint32 *m_buffer1;
		Uint32 *m_buffer2;
	public:
		Screen();
		bool init();
		void setPixel(int x, int y, Uint8 red, Uint8 blue, Uint8 green);
		void update();
		bool processEvents();
		void close();
		void boxBlur();
	};
}

#endif