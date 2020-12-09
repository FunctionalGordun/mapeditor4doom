#include "../include/map.h"

int some_texture_active(t_map *map)
{
	int i;

	i = 0;
	while (++i < 19)
		if (map->wall_tex[i]->active == 1)
			return (1);
	i = 0;
	while (++i < 13)
		if (map->floorsky_tex[i]->active == 1)
			return (2);
	i = 0;
	while (++i < 4)
		if (map->liquid_tex[i]->active == 1)
			return (3);
	return (0);
}

int find_nod(t_map *map, int x, int y)
{
	t_nod *n;
	int i;

	i = 1;
	n = map->nod;
	if (n == NULL)
		return (0);
	while (n)
	{

		if ((n->x1 == map->change_x && n->y1 == map->change_y &&  n->x2 == x && n->y2 == y) ||
		(n->x1 == x && n->y1 == y &&  n->x2 == map->change_x && n->y2 == map->change_y))
			return (i);
		i++;
		n = n->nxt;
	}
	return (0);
}

void change_text_inter2(t_map *map)
{
	draw_line(map, &(t_info){WIDTH/2 - 100, 40, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 41, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 + 120, 40, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 + 120, 41, 0, 40}, (t_color){0,0,0});
	draw_img(map, &(t_info){WIDTH/2 + 80, 100, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "SAVE", &(t_info){WIDTH/2 + 90, 105, 0, 0}, WHITEFONT);
	draw_img(map, &(t_info){WIDTH/2 - 145, 100, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "CANCEL", &(t_info){WIDTH/2 - 142, 105, 0, 0}, WHITEFONT);
}

void change_text_inter(t_map *map)
{
	draw_img(map, &(t_info){WIDTH/2 - 165, 5, 330, 150}, map->inter_tex[16]);
	if (map->inter_tex[17]->active == 0)
		draw_img(map, &(t_info){WIDTH/2 - 10, 3, 30, 35}, map->inter_tex[17]);
	else
		draw_img(map, &(t_info){WIDTH/2 - 10, 3, 30, 35}, map->inter_tex[18]);
	if (map->inter_tex[19]->active == 0)
		draw_img(map, &(t_info){WIDTH/2 - 10, 83, 30, 35}, map->inter_tex[19]);
	else
		draw_img(map, &(t_info){WIDTH/2 - 10, 83, 30, 35}, map->inter_tex[20]);
	draw_line(map, &(t_info){WIDTH/2 - 100, 40, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 41, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 60, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 61, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 80, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 81, 220, 0}, (t_color){0,0,0});
	change_text_inter2(map);
}

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
void	save_texture(t_map *map, int index, int num)
{
	t_nod *n;

	n = map->nod;
	while (n)
	{
		if (n->index == map->index_wall)
		{
			n->texture->texture_name[num] = "wall";
			n->texture->texture_name[num] = ft_strjoin(n->texture->texture_name[num], ft_itoa(index));
			n->texture->texture_name[num] = ft_strjoin(n->texture->texture_name[num], ".png");
		}
		n = n->nxt;
	}
	
}

void open_texture_win(t_map *map)
{
	if (map->inter_tex[16]->active == 1)
	{
		change_text_inter(map);
		map->validflag = draw_changer_texture(map);
	}
	if (map->inter_tex[16]->active == 2 && map->validflag == 3)
	{
		save_texture(map, map->index_tex, 0);
		map->inter_tex[17]->active = 0;
		map->inter_tex[19]->active = 0;
		map->inter_tex[16]->active = 0;
	}
	else if (map->inter_tex[16]->active == 2 && map->validflag == 4)
	{
		save_texture(map, map->index_tex, 1);
		map->inter_tex[17]->active = 0;
		map->inter_tex[19]->active = 0;
		map->inter_tex[16]->active = 0;
	}
}

int	find_texture_name(char *str)
{
	int i;

	i = 0;
	if (ft_strlen(str) == 9)
		i = ft_atoi(&str[4]);
	else if (ft_strlen(str) == 10)
	{
		i = ft_atoi(&str[5]);
		i += 10;
	}
	return (i);
}

void	tmp_draw2(t_map *map, int w, int i, t_nod *nod)
{
	int tmp;

	if (nod->texture->texture_name[0] != NULL && map->inter_tex[17]->active == 0)
	{
		tmp = find_texture_name(nod->texture->texture_name[0]);
		w = WIDTH/2 - 100;
		i = -1;
		while (++i < 4)
		{
			draw_img(map, &(t_info){w, 40, 55, 20}, map->wall_tex[tmp]);
			w += 55;
		}
	}
	if (nod->texture->texture_name[1] != NULL && map->inter_tex[19]->active == 0)
	{
		tmp = find_texture_name(nod->texture->texture_name[1]);
		w = WIDTH/2 - 100;
		i = -1;
		while (++i < 4)
		{
			draw_img(map, &(t_info){w, 60, 55, 20}, map->wall_tex[tmp]);
			w += 55;
		}
	}
}

void	tmp_draw(t_map *map, int index, t_nod *nod)
{
	int c;
	int w;
	int i;
	int tmp;

	i = -1;
	tmp = 0;
	w = WIDTH/2 - 100;
	if (map->inter_tex[17]->active == 1)
		c = 40;
	else if (map->inter_tex[19]->active == 1)
		c = 60;
	if ((map->inter_tex[17]->active == 1 || map->inter_tex[19]->active == 1) && index != -1)
	{
		while (++i < 4)
		{
			draw_img(map, &(t_info){w, c, 55, 20}, map->wall_tex[index]);
			w += 55;
		}
	}
	tmp_draw2(map, w, i, nod);
}

int draw_changer_texture(t_map *map)
{
	t_nod *tmp;

	tmp = map->nod;
	while (tmp)
	{
		if (tmp->index == map->index_wall)
		{
			if (tmp->texture->texture_name[0] != NULL || tmp->texture->texture_name[1] != NULL)
					tmp_draw(map, -1, tmp);
			if (map->inter_tex[17]->active == 1)
			{
				tmp_draw(map, map->index_tex, tmp);
				return (3);
			}
			else if (map->inter_tex[19]->active == 1)
			{
				tmp_draw(map, map->index_tex, tmp);
				return (4);
			}
		}
		tmp = tmp->nxt;
	}
	return (0);
}




void	changer(t_map *map, int x, int y)
{
	int tmp;

	if (some_texture_active(map) == 1)
	{
		tmp = find_nod(map, x, y);
		if (tmp > 0)
		{
			map->index_wall = tmp;
			map->inter_tex[16]->active = 1;
		}
	}
	else if (some_texture_active(map) == 2)
	{
		map->tmpfloor_x = x;
		map->tmpfloor_y = y;
		map->showactive = 2;
		map->inter_tex[16]->active = 3;
	}
}

void	get_wall_cord(t_map *map, int x, int y)
{
	if (map->click == 0 && interface_click(map, x, y) && range_click(&(t_info){x, y, WIDTH / 2 - 165, 5}, 330, 150))
	{
		cursor(map, "/textures/interface/firstdot.png", 0, 16);
		map->click = 1;
		map->change_x = x;
		map->change_y = y;
		find_coord(map, &(map->change_x), &(map->change_y));
		map->change_x -= map->z_x;
		map->change_y -= map->z_y;
	}
	else if (interface_click(map, x, y) && range_click(&(t_info){x, y, WIDTH / 2 - 165, 5}, 330, 150))
	{
		map->click = 0;
		cursor(map, "/textures/interface/seconddot.png", 0, 16);
		find_coord(map, &x, &y);
		changer(map, x - map->z_x, y - map->z_y);
	}
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

void	change_texture(t_map *map, int x, int y)
{
	int wichone;

	wichone = some_texture_active(map);
	if (wichone == 1)
		get_wall_cord(map, x, y);
	if (wichone == 2)
		get_floor_cord(map, x, y);
}


void open_floor_win(t_map *map)
{
	int tmp;

	tmp = 0;
	flooor(map);
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

void findceilingnod(t_map *map)
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
			n->texture->ceiling_name = "floor";
			n->texture->ceiling_name = ft_strjoin(n->texture->ceiling_name, ft_itoa(map->index_tex));
			n->texture->ceiling_name = ft_strjoin(n->texture->ceiling_name, ".png");
		}
		n = n->nxt;
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

// void writedown_floor(t_map *map)
// {
// 	flooor(map);
// 	findfloornod(map);
// }


void	texture_block(t_map *map)
{
	draw_wall_textures(map);
	draw_showuppanel(map, 260, 205, 1);
	draw_floor_textures(map);
	draw_sky_textures(map);
	draw_liquid_textures(map);
	draw_small_panel_tex(map);
	open_texture_win(map);
	open_floor_win(map);
}