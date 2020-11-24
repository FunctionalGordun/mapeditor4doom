#include "../include/map.h"

int	pixel_range2(t_map *map, int x, int y)
{
	t_nod *nod;

	nod = map->nod;
	if (!nod)
		return(0);
	while (nod)
	{
		if (abs(nod->x2 - x) < 10 && abs(nod->y2 - y) < 10)
			return(1);
		nod = nod->nxt;
	}
	return(0);
}

int	pixel_range1(t_map *map, int x, int y)
{
	t_nod *nod;

	nod = map->nod;
	if (!nod)
		return(0);
	while (nod)
	{
		if (abs(nod->x1 - x) < 10 && abs(nod->y1 - y) < 10)
			return(1);
		nod = nod->nxt;
	}
	return(0);
}

void	find_remove(t_map *map, int x, int y)
{
	t_nod *tmp;

	tmp = map->nod;
	while(tmp)
	{
		if (pixel_range1(map, x, y))
			map->nod->removeflag1++;
		if (pixel_range2(map, x, y))
			map->nod->removeflag2++;
		tmp = tmp->nxt;
	}
}

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
			if (color_range(map, x, y) && interface_click(map, x, y))
			{
				find_remove(map, x - map->z_x, y - map->z_y);
				printf("remove!\n");
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