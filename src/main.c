#include "../include/map.h"

void i_error()
{
	printf("error");
	exit(1);
}

int writedown_map(t_map *map)
{
	t_nod *n;
	int strl;
	int maxlen;
	char *buffer;

	n = map->nod;
	int fd;

	if ((fd=open("./maps/test.txt", O_WRONLY))==-1)
	{
		printf ("Cannot open file.\n");
		exit(1);
	}
	while (n)
	{
		if (n->texture->texture_name != NULL)
			printf("texture name: %s\n", n->texture->texture_name);
		// if (n->texture->type_name != NULL)
		// 	printf("name: %s\n", n->texture->type_name);
		maxlen = ft_strlen(ft_itoa((int)n->x1)) + ft_strlen(ft_itoa((int)n->y1)) + ft_strlen(ft_itoa((int)n->x2)) + ft_strlen(ft_itoa((int)n->y2)) + 4;
		if (n->texture->texture_name != NULL)
			maxlen += ft_strlen(n->texture->texture_name) + 1;
		if (n->texture->type_name != NULL)
			maxlen += ft_strlen(n->texture->type_name) + 1;
		// printf("maxlen: %d\n", maxlen);
		buffer = malloc(sizeof(char *) * (maxlen));
		if (n->texture->type_name != NULL)
		{
			buffer = n->texture->type_name;
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, ft_itoa((int)n->x1));
		}
		else
			buffer = ft_itoa((int)n->x1);
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y1));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->x2));
		buffer = ft_strjoin(buffer, " ");
		buffer = ft_strjoin(buffer, ft_itoa((int)n->y2));
		if (n->texture->texture_name != NULL)
		{
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, n->texture->texture_name);
		}
		buffer = ft_strjoin(buffer, "\n");
		if(write(fd, buffer, maxlen) != maxlen)
			printf("error\n");
		free(buffer);
		//printf("x1: %d, y1: %d, x2: %d, y2: %d\n", n->x1, n->y1, n->x2, n->y2);
		n = n->nxt;
	}
	close(fd);
	return (0);
}

int main(int ac, char **av)
{
	t_map *map;
	unsigned int t;
	unsigned int t1;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if(!init_all(map))
		i_error();
	draw(map);
	SDL_UpdateWindowSurface(map->win);

	if (events(map) == 1)
	{
		if (valid_map(map))
			writedown_map(map);
	}
	SDL_DestroyWindow(map->win);
	SDL_Quit();
	return (0);
}
