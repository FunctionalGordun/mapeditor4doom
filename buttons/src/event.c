#include "../include/map.h"

int interface_click(t_map *map, int x, int y)
{
	
	if ((x > 0 &&  x < 300) && y > 0 && y < 800)
		return(0);
	return(1);
}

void section_click(t_map *map, int x, int y)
{
	if ((x > 80 &&  x < 80 + map->inter_tex[6]->img->w) && y > 60 && y < 60 + map->inter_tex[6]->img->h)
		edit_tool(map, 6);
	if ((x > 130 &&  x < 130 + map->inter_tex[7]->img->w) && y > 60 && y < 60 + map->inter_tex[7]->img->h)
		edit_tool(map, 7);
	if ((x > 180 &&  x < 180 + map->inter_tex[8]->img->w) && y > 60 && y < 60 + map->inter_tex[8]->img->h)
		edit_tool(map, 8);
}

void	mouse_icon(t_map *map, int x, int y)
{
	draw_img(map, 9, x - 5, y - 20, 15, 15);
}

int	pixel_used(t_map *map, int x, int y, int r_g_b)
{
	int pixel;

	pixel = (x * map->inter_tex[0]->pixb) + (y * map->inter_tex[0]->strb);
	return (map->inter_tex[0]->s[r_g_b + pixel]);
}
int pix_range(t_map *map, int x, int y) /////////////////хуйня
{
	if (pixel_used(map, x, y, 1) == 255 ||
	pixel_used(map, x+1, y+1, 1) == 255 ||
	pixel_used(map, x+2, y+2, 1) == 255 ||
	pixel_used(map, x+3, y+3, 1) == 255 ||
	pixel_used(map, x+4, y+4, 1) == 255 ||
	pixel_used(map, x-1, y-1, 1) == 255 ||
	pixel_used(map, x-1, y-1, 1) == 255 ||
	pixel_used(map, x-2, y-2, 1) == 255 ||
	pixel_used(map, x-3, y-3, 1) == 255 ||
	pixel_used(map, x-4, y-4, 1) == 255)
		return (1);
	return(0);
}

int		mmove(int x, int y, t_map *map, SDL_Event event)
{
	if (map->sh == 0)
	{
		int x1 = (x - map->z_x);
		int y1 = (y - map->z_y);
		find_coord(map, &x1, &y1);
	}
	if (map->inter_tex[8]->active)
	{
		if (pix_range(map, x, y) && interface_click(map, x, y)) /////////////////хуйня
			mouse_icon(map, x, y);
	}
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
		if (event.type == SDL_KEYUP)
			ukey((unsigned char)event.key.keysym.sym, map);
		if (event.type == SDL_MOUSEBUTTONDOWN)
		{
			SDL_GetMouseState(&x, &y);
			mkey(event.button.button, x, y, map);
			section_click(map, x, y);
			draw(map);
		}
		if (event.type == SDL_MOUSEMOTION)
		{
			draw(map);
			mmove(event.motion.x, event.motion.y, map, event);
			SDL_UpdateWindowSurface(map->win);
		}
		
	}
}