#include "../include/map.h"

int change_floor_inter(t_map *map)
{
	draw_img(map, &(t_info){WIDTH/2 - 115, 5, 330, 100}, map->inter_tex[16]);
	draw_img(map, &(t_info){WIDTH/2 + 20, 10, 70, 20}, map->floorsky_tex[0]);
	if (map->floorsky_tex[0]->active == 1)
		fonts_classic(map, "floor", &(t_info){WIDTH/2 + 40, 14, 0, 0}, SANBYBROWNFONT);
	else
		fonts_classic(map, "floor", &(t_info){WIDTH/2 + 40, 14, 0, 0}, WHITEFONT);
	draw_img(map, &(t_info){WIDTH/2 + 20, 30, 70, 20}, map->floorsky_tex[0]);
	if (map->floorsky_tex[0]->active == 2)
		fonts_classic(map, "celing", &(t_info){WIDTH/2 + 40, 34, 0, 0}, SANBYBROWNFONT);
	else
		fonts_classic(map, "celing", &(t_info){WIDTH/2 + 40, 34, 0, 0}, WHITEFONT);
	//fonts_classic(map, "celing", &(t_info){WIDTH/2 + 40, 34, 0, 0}, WHITEFONT);
	draw_img(map, &(t_info){WIDTH/2 + 120, 60, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "SAVE", &(t_info){WIDTH/2 + 130, 65, 0, 0}, WHITEFONT);
	draw_img(map, &(t_info){WIDTH/2 - 100, 60, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "CANCEL", &(t_info){WIDTH/2 - 95, 65, 0, 0}, WHITEFONT);
	if (map->floorsky_tex[0]->active == 1)
		return(1);
	else if (map->floorsky_tex[0]->active == 2)
		return (2);
	else
		return (0);
}

int checknod(t_map *map, int x, int y)
{
	t_nod *n;

	n = map->nod;
	while (n)
	{
		if ((n->x1 == x && n->y1 == y) || (n->x2 == x && n->y2 == y))
			return (1);
		n = n->nxt;
	}
	return (0);
}

void	get_floor_cordi(t_map *map, int x, int y)
{
	if (checknod(map, x, y))
	{
		printf("ok\n");
		bigdot(map, x, y, HOTPINK);
	}
	// if (map->click == 0 && interface_click(map, x, y))
	// {
	// 	map->click = 1;
	// 	if (checknod(map, x, y))
	// 	{
	// 		printf("ok\n");
	// 		bigdot(map, x, y, HOTPINK);
	// 	}
	// }
	// else if (interface_click(map, x, y))
	// {
	// 	map->click = 0;
	// 	if (checknod(map, x, y))
	// 	{
	// 		printf("ok2\n");
	// 		bigdot(map, x, y, HOTPINK);
	// 	}
	// }
}

void	get_floor_cord(t_map *map, int x, int y)
{
	if (map->click == 0 && interface_click(map, x, y) && range_click(&(t_info){x, y, WIDTH / 2 - 115, 5}, 330, 100))
	{
		map->click = 1;
		map->floor_x = x - map->z_x;
		map->floor_y = y - map->z_y;
	}
	else if (interface_click(map, x, y) && range_click(&(t_info){x, y, WIDTH / 2 - 115, 5}, 330, 100))
	{
		map->click = 0;
		changer(map, x - map->z_x, y - map->z_y);
	}
}

void open_floor_win(t_map *map)
{
	int tmp;

	tmp = 0;
	//flooor(map);
	if (map->inter_tex[16]->active == 3)
	{
		map->validflag = change_floor_inter(map);
		//map->validflag = draw_changer_texture(map);
	}
	if (map->inter_tex[16]->active == 4)
	{
		if (map->validflag == 1)
			findfloornod(map);
		else if (map->validflag == 2)
			findceilingnod(map);
	}
}


void	flooor(t_map *map)
{
	int i_tmp;
	int j_tmp;
	int n;
	int o;

	n = 0;
	o = 0;
	i_tmp = abs(map->tmpfloor_x - map->floor_x) / 5;
	j_tmp = abs(map->tmpfloor_y - map->floor_y) / 5;
	if (map->inter_tex[16]->active == 3)
	{
		while (o < abs(map->tmpfloor_y - map->floor_y) - j_tmp)
		{
			n = 0;
			while (n < abs(map->tmpfloor_x - map->floor_x) - i_tmp)
			{
				draw_img2(map, &(t_info){map->floor_x + map->z_x + n, map->floor_y + map->z_y + o, i_tmp, j_tmp}, map->floorsky_tex[map->index_tex]);
				n += i_tmp;
			}
			o += j_tmp;
		}
	}
}

void findfloornod(t_map *map)
{
	int w;
	int h;
	t_nod *n;

	n = map->nod;
	w = map->tmpfloor_x - map->floor_x;
	h = map->tmpfloor_y - map->floor_y;
	while (n)
	{
		if ((n->x1 >= map->floor_x && n->x1 <= map->tmpfloor_x) && (n->y1 >= map->floor_y && n->y1 <= map->tmpfloor_y) &&
		(n->x2 >= map->floor_x && n->x2 <= map->tmpfloor_x) && (n->y2 >= map->floor_y && n->y2 <= map->tmpfloor_y))
		{
			n->texture->floor_name = "floor";
			n->texture->floor_name = ft_strjoin(n->texture->floor_name, ft_itoa(map->index_tex));
			n->texture->floor_name = ft_strjoin(n->texture->floor_name, ".png");
		}
		n = n->nxt;
	}
}
