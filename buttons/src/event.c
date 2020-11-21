#include "../include/map.h"

void img_click()
{
	
}

void	events(t_map *map)
{
	int x = 0;
	int y = 0;
	SDL_Event event;
	int done = 0;

	while ((!done) && SDL_WaitEvent(&event))
	{
		if (event.type == SDL_QUIT)
			done = 1;
		if (event.type == SDL_KEYDOWN)
		{
			pkey((unsigned char)event.key.keysym.sym, map);
		}
		if (event.type == SDL_KEYUP)
		{
			ukey((unsigned char)event.key.keysym.sym, map);
		}
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&x, &y);
			mkey(event.button.button, x, y, map);
			draw(map); ///123
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			// mmove(event.motion.x, event.motion.y, mp);
		}
		
	}
}