#include "../include/map.h"

int		mkey(int key, int x, int y, t_map *map)
{
	if (key == 1)
	{
		if (map->click == 0)
		{
			draw_point(map, x, y, RED);
			map->x_clck = x;
			map->y_clck = y;
			map->click = 1;
		}
		else
		{
			map->click = 0;
			add_node(map, x, y);
		}
		
	}
	// printf("%d\n", key);
	if (key == 3)
	{
		// draw_img(map, x, y, 20, 20);
	}
	// draw_grid(map);
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