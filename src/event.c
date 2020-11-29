#include "../include/map.h"

// int	pixel_used(t_map *map, int x, int y, int r_g_b)
// {
// 	int pixel;

// 	pixel = (x * map->inter_tex[0]->pixb) + (y * map->inter_tex[0]->strb);
// 	return (map->inter_tex[0]->s[r_g_b + pixel]);
// }
// int color_range(t_map *map, int x, int y) /////////////////хуйня
// {
// 	int i;
// 	int j;

// 	i = -1;
// 	j = -5;
// 	while (++i < 5 || ++j < 1)
// 	{
// 		if (pixel_used(map, x + i, y + i, 1) == 255 || pixel_used(map, x + j, y + j, 1) == 255 ||
// 		pixel_used(map, x + i, y + i, 2) == 255 || pixel_used(map, x + j, y + j, 2) == 255)
// 			return (1);
// 	}
// 	return(0);
// }

int		mmove(int x, int y, t_map *map, SDL_Event event)
{
	int x1 = x;
	int y1 = y;
	find_coord(map, &x1, &y1);
	draw(map);
	if (map->inter_tex[6]->active && interface_click(map, x, y))
	{
		if (x1 != x || y1 != y)
			bigdot(map, x1, y1, HOTPINK);
		cursor(map, "/textures/interface/editpic.png", 0, 16);
	}
	else if (map->inter_tex[8]->active)
		(x1 != x || y1 != y) ? cursor(map, "/textures/interface/deletic.png", 8, 8) : SDL_FreeCursor(map->cursor);
	else
		SDL_FreeCursor(map->cursor);
	return (0);
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
			pkey((unsigned char)event.key.keysym.sym, map);
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&x, &y);
			hexagon(map, x, y);
			mkey(event.button.button, x, y, map);
			section_click(map, x, y);
			draw(map);
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			//made_blocks(map);
			mmove(event.motion.x, event.motion.y, map, event);
			SDL_UpdateWindowSurface(map->win);
		}
		
	}
}