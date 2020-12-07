#include "../include/map.h"

void	showtexture(t_map *map)
{
	int i;
	int y;

	i = 8;
	y = 20;
	while (++i < 19)
	{
		if (map->wall_tex[i]->active == 1)
			draw_img(map, &(t_info){320 - 10, y - 10, 70, 70}, map->inter_tex[15]);
		draw_img(map, &(t_info){320, y, 50, 50}, map->wall_tex[i]);
		y += 80;
	}
}

void	showfloorsky(t_map *map)
{
	int i;
	int y;

	i = 8;
	y = 20;
	while (++i < 13)
	{
		if (map->floorsky_tex[i]->active == 1)
			draw_img(map, &(t_info){320 - 10, y - 10, 70, 70}, map->inter_tex[15]);
		draw_img(map, &(t_info){320, y, 50, 50}, map->floorsky_tex[i]);
		y += 80;
	}
}


void showupcontent(t_map *map)
{
	int i;
	int y;

	i = 8;
	y = 20;
	if (map->showactive == 1)
	{
		draw_img(map, &(t_info){260, 205, 30, 50}, map->inter_tex[14]);
		showtexture(map);
	}
	// if (map->showactive == 2)
	// {
	// 	draw_img(map, &(t_info){260, 370, 30, 50}, map->inter_tex[14]);
	// 	showfloorsky(map);
	// }
}

void draw_showuppanel(t_map *map, int x, int y, int inx)
{
	if (map->inter_tex[13]->active == 1)
	{
		draw_img(map, &(t_info){305, 0, 80, 800}, map->inter_tex[12]);
		showupcontent(map);
	}
	else
		draw_img(map, &(t_info){x, y, 30, 50}, map->inter_tex[13]);
	
}

void draw_small_panel_tex(t_map *map)
{
	int i;

	i = 0;
	while (++i < 19)
		if (map->wall_tex[i]->active == 1 && map->inter_tex[13]->active == 0)
		{
			map->index_tex = i;
			draw_img(map, &(t_info){310, 770, 25, 25}, map->wall_tex[i]);
		}
	i = 0;
	while (++i < 13)
		if (map->floorsky_tex[i]->active == 1 && map->inter_tex[13]->active == 0)
			draw_img(map, &(t_info){310, 770, 25, 25}, map->floorsky_tex[i]);
	i = 0;
	while (++i < 4)
		if (map->liquid_tex[i]->active == 1 && map->inter_tex[13]->active == 0)
			draw_img(map, &(t_info){310, 770, 25, 25}, map->liquid_tex[i]);
}


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

void change_text_inter(t_map *map)
{
	draw_img(map, &(t_info){WIDTH/2 - 165, 5, 330, 150}, map->inter_tex[16]);
	(map->inter_tex[17]->active) == 1 ? draw_img(map, &(t_info){WIDTH/2 - 10, 3, 30, 35}, map->inter_tex[18]) : draw_img(map, &(t_info){WIDTH/2 - 10, 3, 30, 35}, map->inter_tex[17]);
	(map->inter_tex[19]->active) == 1 ? draw_img(map, &(t_info){WIDTH/2 - 10, 83, 30, 35}, map->inter_tex[20]) :draw_img(map, &(t_info){WIDTH/2 - 10, 83, 30, 35}, map->inter_tex[19]);
	draw_line(map, &(t_info){WIDTH/2 - 100, 40, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 41, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 60, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 61, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 80, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 81, 220, 0}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 40, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 - 100, 41, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 + 120, 40, 0, 40}, (t_color){0,0,0});
	draw_line(map, &(t_info){WIDTH/2 + 120, 41, 0, 40}, (t_color){0,0,0});
	draw_img(map, &(t_info){WIDTH/2 + 80, 100, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "SAVE", &(t_info){WIDTH/2 + 90, 105, 0, 0}, WHITEFONT);
	draw_img(map, &(t_info){WIDTH/2 - 145, 100, 65, 30}, map->floorsky_tex[0]);
	fonts_classic(map, "CANCEL", &(t_info){WIDTH/2 - 142, 105, 0, 0}, WHITEFONT);
}
void	save_texture(t_map *map, int index)
{
	t_nod *n;

	n = map->nod;
	while (n)
	{
		printf("index: %d wall_index: %d \n", n->index,  map->index_wall);
		if (n->index == map->index_wall)
		{
			n->texture->texture_name = "wall";
			n->texture->texture_name = ft_strjoin(n->texture->texture_name, ft_itoa(index));
			n->texture->texture_name = ft_strjoin(n->texture->texture_name, ".png");
		}
		n = n->nxt;
	}
	// if (index == 1)
	// 	map->nod->texture->texture_name = "wall0.png";
	// else if (index == 2)
	// 	map->nod->texture->texture_name = "wall1.png";
	
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
		printf("now u save the texture: %d\n", map->index_tex);
		save_texture(map, map->index_tex);
		map->inter_tex[16]->active = 0;
	}
}

int draw_changer_texture(t_map *map)
{
	int c;
	int w;
	int i;

	i = -1;
	if (map->inter_tex[17]->active == 1)
		c = 40;
	else if (map->inter_tex[19]->active == 1)
		c = 60;
	w = WIDTH/2 - 100;
	if (map->inter_tex[17]->active == 1 || map->inter_tex[19]->active == 1)
	{
		while (++i < 4)
		{
			draw_img(map, &(t_info){w, c, 55, 20}, map->wall_tex[map->index_tex]);
			w += 55;
		}
		return (3);
	}
	return (0);
}

void	changer(t_map *map, int x, int y)
{
	int tmp;

	tmp = find_nod(map, x, y);
	if (tmp > 0)
	{
		map->index_wall = tmp;
		printf("i nod: %d\n", map->index_wall);
		map->inter_tex[16]->active = 1;
		
	}
}

void	get_wall_cord(t_map *map, int x, int y)
{
	if (map->click == 0 && interface_click(map, x, y))
	{
		cursor(map, "/textures/interface/firstdot.png", 0, 16);
		map->click = 1;
		map->change_x = x;
		map->change_y = y;
		find_coord(map, &(map->change_x), &(map->change_y));
		map->change_x -= map->z_x;
		map->change_y -= map->z_y;
	}
	else if (interface_click(map, x, y))
	{
		map->click = 0;
		cursor(map, "/textures/interface/seconddot.png", 0, 16);
		find_coord(map, &x, &y);
		changer(map, x - map->z_x, y - map->z_y);
	}
}

void	change_texture(t_map *map, int x, int y)
{
	int wichone;

	wichone = some_texture_active(map);
	if (wichone == 1)
		get_wall_cord(map, x, y);
}

void	texture_block(t_map *map)
{
	draw_wall_textures(map);
	draw_showuppanel(map, 260, 205, 1);
	draw_floor_textures(map);
	draw_sky_textures(map);
	draw_liquid_textures(map);
	draw_small_panel_tex(map);
	open_texture_win(map);
}