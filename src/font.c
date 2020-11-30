#include "../include/map.h"

int	struppercase(char *str)
{
	int i;

	while (str[i])
	{
		if (str[i] >= 65 && str[i] <= 90)
			return (1);
		i++;
	}
	return (0);
}

void fonts_classic(t_map *map, char *str, int x, int y)
{
	TTF_Font *font;
	int strlen;

	map->font = (t_image *)malloc(sizeof(t_image));
	strlen = ft_strlen(str);
	TTF_Init();
	SDL_Color White = {255, 255, 255};
	font = TTF_OpenFont("/textures/fonts/classic.ttf", 32);
	map->font->img = TTF_RenderText_Solid(font, str, White);
	map->font->img = SDL_ConvertSurfaceFormat(map->font->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->font->img,&(map->font->s), &(map->font->pixb), &(map->font->strb));
	if (struppercase(str))
		draw_img(map, &(t_info){x,y,strlen*10,strlen*4}, map->font);
	else
		draw_img(map, &(t_info){x,y,strlen*7,strlen*3}, map->font);
}

void fonts_doom(t_map *map, char *str, int x, int y)
{
	TTF_Font *font;
	int strlen;

	map->font = (t_image *)malloc(sizeof(t_image));
	strlen = ft_strlen(str);
	TTF_Init();
	SDL_Color White = {255, 255, 255};
	font = TTF_OpenFont("/textures/fonts/doom.ttf", 32);
	map->font->img = TTF_RenderText_Solid(font, str, White);
	map->font->img = SDL_ConvertSurfaceFormat(map->font->img, SDL_PIXELFORMAT_BGRA32, 0);
		init_texture(map->font->img,&(map->font->s), &(map->font->pixb), &(map->font->strb));
	if (struppercase(str))
		draw_img(map, &(t_info){x,y,strlen*12,strlen*5}, map->font);
	else
		draw_img(map, &(t_info){x,y,strlen*10,strlen*3}, map->font);
}

// void fonts(t_map *map, char *str, int x, int y)
// {
// 	TTF_Font *font;
// 	int strlen;

// 	strlen = ft_strlen(str);
// 	TTF_Init();
// 	SDL_Color White = {255, 255, 255};
// 	font = TTF_OpenFont("/textures/fonts/doom.ttf", 32);
// 	map->font->img = TTF_RenderText_Solid(font, str, White);
// 	map->font->img = SDL_ConvertSurfaceFormat(map->font->img, SDL_PIXELFORMAT_BGRA32, 0);
// 		init_texture(map->font->img,&(map->font->s), &(map->font->pixb), &(map->font->strb));
// 	if (struppercase(str))
// 		draw_img(map, 12, x, y, strlen * 12, strlen * 5);
// 	else
// 		draw_img(map, 12, x, y, strlen * 10, strlen * 3);
// }