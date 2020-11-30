#include "../include/map.h"

int		mkey(int key, int x, int y, t_map *map)
{
	if (key == 1)
	{
		if (map->inter_tex[6]->active)
			wall_editor(map, x, y);
		if (map->inter_tex[8]->active)
		{
			int x1 = x;
			int y1 = y;
			find_coord(map, &x1, &y1);
			if (x1 != x || y1 != y)
				find_remove(map, x1, y1);
		}
		
	}
	SDL_UpdateWindowSurface(map->win);
	return (0);
}

int		pkey(int key, t_map *map)
{
	if (key == 27)
		exit(1);
	//printf("%d\n", key);
	return (0);
}