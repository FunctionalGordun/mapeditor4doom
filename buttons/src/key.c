#include "../include/map.h"

int		mkey(int key, int x, int y, t_map *map)
{
	if (key == 1)
	{
		if (map->inter_tex[6]->active)
		{
			wall_editor(map, x, y);
		}
		if (map->inter_tex[8]->active)
		{
			if (pix_range(map, x, y) && interface_click(map, x, y))
			{
				printf("Click!\n");
			}
		}
		
	}
	SDL_UpdateWindowSurface(map->win);
	return (0);
}

int		pkey(int key, t_map *map)
{
	if (key == 225)
	{
		map->sh = 1;
	}
	if (key == 82)
	{
		map->z_y -= 3;
		map->y_clck -= 3;
	}
	if (key == 81)
	{
		map->z_y += 3;
		map->y_clck += 3;
	}
	if (key == 79)
	{
		map->z_x += 3;
		map->x_clck += 3;
	}
	if (key == 80)
	{
		map->z_x -= 3;
		map->x_clck -= 3;
	}
	if (key == 27)
	{
		exit(1);
	}
	// printf("%d\n", key);
	//draw_grid(map);
	// draw(map);
	return (0);
}

int		ukey(int key, t_map *map)
{
	if (key == 225)
		map->sh = 0;
	return (0);
}