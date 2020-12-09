#include "../include/map.h"

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
		if (n->texture->floor_name != NULL)
			printf("floor name: %s\n", n->texture->floor_name);
		if (n->texture->ceiling_name != NULL)
			printf("ceiling name: %s\n", n->texture->ceiling_name);
		// if (n->texture->texture_name[1] != NULL)
		// 	printf("texture name: %s\n", n->texture->texture_name[1]);
		// if (n->texture->type_name != NULL)
		// 	printf("name: %s\n", n->texture->type_name);
		maxlen = ft_strlen(ft_itoa((int)n->x1)) + ft_strlen(ft_itoa((int)n->y1)) + ft_strlen(ft_itoa((int)n->x2)) + ft_strlen(ft_itoa((int)n->y2)) + 4;
		if (n->texture->texture_name[0] != NULL)
			maxlen += ft_strlen(n->texture->texture_name[0]) + 1;
		if (n->texture->texture_name[1] != NULL)
			maxlen += ft_strlen(n->texture->texture_name[1]) + 1;
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
		if (n->texture->texture_name[0] != NULL)
		{
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, n->texture->texture_name[0]);
		}
		if (n->texture->texture_name[1] != NULL)
		{
			buffer = ft_strjoin(buffer, " ");
			buffer = ft_strjoin(buffer, n->texture->texture_name[1]);
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