#include "fdf.h"

static void init_texture_renderer(t_window *win, int w, int h)
{
	if (!(win->img_ptr = (Uint32 *)ft_memalloc(sizeof(Uint32) * w * h)))
		exit(EXIT_FAILURE);
	win->image = SDL_CreateTexture(win->renderer, SDL_PIXELFORMAT_ARGB8888, SDL_TEXTUREACCESS_STREAMING, w, h);
}

void        init_window(t_window *window)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (!(window->window = SDL_CreateWindow("fdf", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
					WIN_X, WIN_Y, SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	if (!(window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED)))
		exit(EXIT_FAILURE);
	init_texture_renderer(window, WIN_X, WIN_Y);
}
/*
void        init_window2(t_window *window)
{
	SDL_Init(SDL_INIT_VIDEO);
	if (!(window->window = SDL_CreateWindow("config", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
											CONF_X, CONF_Y, SDL_WINDOW_SHOWN)))
		exit(EXIT_FAILURE);
	if (!(window->renderer = SDL_CreateRenderer(window->window, -1, SDL_RENDERER_ACCELERATED)))
		exit(EXIT_FAILURE);
	init_texture_renderer(window, CONF_X, CONF_Y);
}*/
