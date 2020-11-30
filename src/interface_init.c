#include "../include/map.h"

void init_texture(SDL_Surface *tex, unsigned char **s, unsigned char *pixb, int *strb)
{
	*s = (unsigned char*)(tex->pixels);
	*pixb = (tex->format->BytesPerPixel);
	*strb = (tex->pitch);
}

int		init_all(t_map *map)
{
	SDL_Init(SDL_INIT_EVERYTHING);
	IMG_Init(IMG_INIT_JPG|IMG_INIT_PNG);
	if (!(map->win = SDL_CreateWindow("Mapeditor", 200, 200, WIDTH, HEIGHT, SDL_WINDOW_SHOWN)))
		return (0);
	init_interface(map);
	map->z_x = WIDTH / 2;
	map->z_y = HEIGHT / 2;
	map->click = 0;
	map->nod = NULL;
	map->wclick = 25;
	return (1);
}

void	get_inter_textures(t_map *map)
{
	map->inter_tex[0]->img = SDL_GetWindowSurface(map->win);
	init_texture(map->inter_tex[0]->img, &(map->inter_tex[0]->s),
	 &(map->inter_tex[0]->pixb), &(map->inter_tex[0]->strb));
	map->inter_tex[1]->img = IMG_Load("/textures/interface/panel.png");
	map->inter_tex[2]->img = IMG_Load("/textures/interface/panelin.png");
	map->inter_tex[3]->img = IMG_Load("/textures/interface/blocks.png");
	map->inter_tex[4]->img = IMG_Load("/textures/interface/texture.png");
	map->inter_tex[5]->img = IMG_Load("/textures/interface/objects.png");
	map->inter_tex[6]->img = IMG_Load("/textures/interface/walltool.png");
	map->inter_tex[7]->img = IMG_Load("/textures/interface/cursortool.png");
	map->inter_tex[8]->img = IMG_Load("/textures/interface/removetool.png");
	map->inter_tex[9]->img = IMG_Load("/textures/interface/widgetspanel.png");
	map->inter_tex[10]->img = IMG_Load("/textures/interface/plusbtn.png");
	map->inter_tex[11]->img = IMG_Load("/textures/interface/minusbtn.png");
}

void	malloc_interface(t_map *map)
{
	int i;

	i = -1;
	while (++i < 12)
		map->inter_tex[i] = (t_image *)malloc(sizeof(t_image));
	get_inter_textures(map);
	i = 0;
	while (++i < 12)
	{
		map->inter_tex[i]->img = SDL_ConvertSurfaceFormat(map->inter_tex[i]->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->inter_tex[i]->img, &(map->inter_tex[i]->s), &(map->inter_tex[i]->pixb), &(map->inter_tex[i]->strb));
		map->inter_tex[i]->active = 0;
	}
	map->inter_tex[3]->active = 1;
	map->inter_tex[6]->active = 1;
}

void	get_block_textures(t_map *map)
{
	map->block_tex[0]->img = IMG_Load("/textures/texture/square.png");
	map->block_tex[1]->img = IMG_Load("/textures/texture/pentagon.png");
	map->block_tex[2]->img = IMG_Load("/textures/texture/hexagon.png");
	map->block_tex[3]->img = IMG_Load("/textures/texture/octagon.png");
}

void	malloc_block_texture(t_map *map)
{
	int i;

	i = -1;
	map->remove = malloc(sizeof(t_removeinfo*)); ///
	map->remove->x = malloc(sizeof(int *) * 10); /// 
	map->remove->y = malloc(sizeof(int *) * 10); ////
	while (++i < 4)
		map->block_tex[i] = (t_image *)malloc(sizeof(t_image));
	get_block_textures(map);
	i = -1;
	while (++i < 4)
	{
		map->block_tex[i]->img = SDL_ConvertSurfaceFormat(map->block_tex[i]->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->block_tex[i]->img, &(map->block_tex[i]->s), &(map->block_tex[i]->pixb), &(map->block_tex[i]->strb));
		map->block_tex[i]->active = 0;
	}
}


void	init_interface(t_map *map)
{
	malloc_interface(map);
	malloc_block_texture(map);
}