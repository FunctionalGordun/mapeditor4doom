#include "../include/map.h"

void i_error()
{
	printf("error");
	exit(1);
}

// int zvezd(int n)
// {
// 	if (n < 1)
// 		return (1);
// 	else if (n >= 1)
// 		return (2 +(zvezd(--n) + 2 + zvezd(n -= 2)));
// }

int main(int ac, char **av)
{
	// printf("len: %d\n", zvezd(35));
	t_map *map;
	unsigned int t;
	unsigned int t1;

	if (!(map = (t_map *)malloc(sizeof(t_map))))
		return (0);
	if(!init_all(map))
		i_error();
	draw(map);
	SDL_UpdateWindowSurface(map->win);

	events(map);
	SDL_DestroyWindow(map->win);
	SDL_Quit();
	return (0);
}
