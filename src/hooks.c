#include "../include/map.h"

int interface_click(t_map *map, int x, int y)
{
	if ((x > 0 &&  x < 300) && y > 0 && y < 800)
		return(0);
	return(1);
}

void tools_click(t_map *map, int x, int y)
{
	if ((x > 80 &&  x < 110) && y > 60 && y < 90)
		edit_tool(map, 6);
	else if ((x > 130 &&  x < 160) && y > 60 && y < 90)
		edit_tool(map, 7);
	else if ((x > 180 &&  x < 210) && y > 60 && y < 90)
		edit_tool(map, 8);
}

int widget_click(t_map *map, int x, int y)
{
	int tmp;

	tmp = map->wclick;
	if ((x > 70 && x < 95) && y > 140 && y < 165)
	{
		map->tmpclick = 1;
		map->wclick -= 3;
	}
	else if ((x > 195 && x < 220) && y > 140 && y < 165)
	{
		map->tmpclick = 1;
		map->wclick += 3;
	}
	if (map->wclick != tmp)
		return (0);
	return (1);
}

void section_click(t_map *map, int x, int y)
{
	if ((x > 20 &&  x < 90) && y > 20 && y < 50)
		edit_tool(map, 3);
	else if ((x > 110 &&  x < 180) && y > 20 && y < 50)
		edit_tool(map, 4);
	else if ((x > 200 &&  x < 270) && y > 20 && y < 50)
		edit_tool(map, 5);
	else if ((x > 120 && x < 180) && y > 758 && y < 788)
		map->inter_tex[24]->active = 1;
}

void blockterxture_click(t_map *map, int x, int y)
{
	if ((x > 65 && x < 115) && y > 250 && y < 300)
		edit_blocktexture(map, 0);
	else if ((x > 165 && x < 215) && y > 250 && y < 300)
		edit_blocktexture(map, 1);
	else if ((x > 65 && x < 115) && y > 320 && y < 370)
		edit_blocktexture(map, 2);
	else if ((x > 165 && x < 215) && y > 250 && y < 370)
		edit_blocktexture(map, 3);
}

void showup_lick(t_map *map, int x, int y)
{
	if ((x > 260 && x < 290) && y > 205 && y < 255)
	{
		map->showactive = 1;
		if (map->inter_tex[13]->active == 1)
			map->inter_tex[13]->active = 0;
		else
			map->inter_tex[13]->active = 1;
	}
	if ((x > 260 && x < 290) && y > 370 && y < 420)
	{
		map->showactive = 2;
		if (map->inter_tex[13]->active == 1)
			map->inter_tex[13]->active = 0;
		else
			map->inter_tex[13]->active = 1;
	}
}

void zerroother(t_map *map)
{
	int i;

	i = 0;
	while (++i < 19)
		map->wall_tex[i]->active = 0;
	i = 0;
	while (++i < 13)
		map->floorsky_tex[i]->active = 0;
	i = 0;
	while (++i < 4)
		map->liquid_tex[i]->active = 0;
}

void	edit_walltexture(t_map *map, int index)
{
	int i;

	i = 0;
	zerroother(map);
	while (++i < 19)
	{
		if (i == index)
			map->wall_tex[i]->active = 1;
		else
			map->wall_tex[i]->active = 0;
	}
}

void	edit_floortexture(t_map *map, int index)
{
	int i;

	i = 0;
	zerroother(map);
	while (++i < 13)
	{
		if (i == index)
			map->floorsky_tex[i]->active = 1;
		else
			map->floorsky_tex[i]->active = 0;
	}
}

void	edit_liquidtexture(t_map *map, int index)
{
	int i;

	i = 0;
	zerroother(map);
	while (++i < 4)
	{
		if (i == index)
			map->liquid_tex[i]->active = 1;
		else
			map->liquid_tex[i]->active = 0;
	}
}

void walltx_click(t_map *map, int x, int y)
{
	int i;
	int x_c;
	int y_c;

	i = 0;
	x_c = 20;
	y_c = 170;
	while (++i < 9)
	{
		if ((x > x_c && x < x_c + 50) && (y > y_c && y < y_c + 50))
			edit_walltexture(map, i);
		x_c += 60;
		if (i == 4)
		{
			x_c = 20;
			y_c = 230;
		}
	}
	x_c = 20;
	i = 8;
	while (++i < 19)
	{
		if ((x > 320 && x < 370) && (y > x_c && y < x_c + 50))
			edit_walltexture(map, i);
		x_c += 80;
	}
}

void floorskytx_click(t_map *map, int x, int y)
{
	int i;
	int x_c;
	int y_c;

	i = 0;
	x_c = 20;
	y_c = 340;
	while (++i < 9)
	{
		if ((x > x_c && x < x_c + 50) && (y > y_c && y < y_c + 50))
			edit_floortexture(map, i);
		x_c += 60;
		if (i == 4)
		{
			x_c = 20;
			y_c = 400;
		}
	}
	x_c = 20;
	i = 8;
	while (++i < 13)
	{
		if ((x > 320 && x < 370) && (y > x_c && y < x_c + 50))
			edit_floortexture(map, i);
		x_c += 80;
	}
}

void liquidtx_click(t_map *map, int x, int y)
{
	int i;
	int x_c;
	int y_c;

	i = 0;
	x_c = 20;
	y_c = 520;
	while (++i < 4)
	{
		if ((x > x_c && x < x_c + 50) && (y > y_c && y < y_c + 50))
			edit_liquidtexture(map, i);
		x_c += 90;
	}
}

void terxtures_click(t_map *map, int x, int y)
{
	showup_lick(map, x, y);
	walltx_click(map, x, y);
	floorskytx_click(map, x, y);
	liquidtx_click(map, x, y);
}

void change_texture_click(t_map *map, int x, int y)
{
	if ((x > WIDTH/2 - 125 && x < WIDTH/2 - 100) && (y > 50 && y < 70))
	{
		map->inter_tex[17]->active = 1;
		map->inter_tex[23]->active = 0;
	}
	if ((x > WIDTH/2 + 120 && x < WIDTH/2 + 170) && (y > 50 && y < 70))
	{
		map->inter_tex[17]->active = 0;
		map->inter_tex[23]->active = 1;
	}
	if ((x > WIDTH/2 - 10 && x < WIDTH/2 + 20) && (y > 3 && y < 38))
	{
		map->inter_tex[19]->active = 1;
		map->inter_tex[21]->active = 0;
	}
	if ((x > WIDTH/2 - 10 && x < WIDTH/2 + 20) && (y > 83 && y < 118))
	{
		map->inter_tex[19]->active = 0;
		map->inter_tex[21]->active = 1;
	}
}


int catch_click(t_map *map, int x, int y)
{

	section_click(map, x, y);
	tools_click(map, x, y);
	blockterxture_click(map, x, y);
	if (!widget_click(map, x, y))
		remove_blocks(map);
	if (map->inter_tex[4]->active == 1)
		terxtures_click(map, x, y);
	if (map->inter_tex[16]->active == 1)
		change_texture_click(map, x, y);
	if (map->inter_tex[24]->active == 1)
		return (1);
	else
		return (0);
	
}
