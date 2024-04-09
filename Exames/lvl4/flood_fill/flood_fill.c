
  typedef struct  s_point
  {
    int           x;
    int           y;
  }               t_point;


void fill(char **tab, t_point size, t_point begin, int x, int y, char c)
{
		if (x < 0 || x >= size.x ||
			y < 0 || y >= size.x ||
			tab[begin.y][begin.x] == 'F' || tab[begin.y][begin.x] != c)
		{
			return ;
		}
		
		tab[begin.y][begin.x] = 'F';

			fill(tab, size, begin, x-1, y, c);
			fill(tab, size, begin, x + 1, y, c);
			fill(tab, size, begin, x, y - 1, c);
			fill(tab, size, begin, x, y + 1, c);

}

void  flood_fill(char **tab, t_point size, t_point begin)
{
	char c = tab[begin.y][begin.x];
	fill(tab, size, begin, begin.x, begin.y, c);
	return ;
}


#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}