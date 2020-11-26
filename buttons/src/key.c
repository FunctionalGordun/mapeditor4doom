#include "../include/map.h"

void	find_remove(t_map *map, int x, int y)
{
	t_nod *tmp;

	tmp = map->nod;
	while(tmp)
	{
		if ((tmp->x1 + map->z_x) == x || (tmp->y1 + map->z_x) == y ||
		(tmp->x2 + map->z_x) == x || (tmp->y2 + map->z_x) == y)
			tmp->removeflag = 1;
		tmp = tmp->nxt;
	}
}

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
	printf("%d\n", key);
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