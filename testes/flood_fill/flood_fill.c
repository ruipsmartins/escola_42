
  typedef struct  s_point
  {
    int		x;
    int		y;
	int		c_count;
	int		e_count;
	int		p_count;
  }               t_point;


void f_fill(char **tab, t_point *size, int row, int col)
{
    if (row < 0 || col < 0 || row >= size->y || col >= size->x)
        return;
    else if (tab[row][col] == 'F' || tab[row][col] == '1')
        return;
	else if (tab[row][col] == 'C')
		size->c_count ++;
	else if (tab[row][col] == 'P')
		size->p_count ++;
	else if (tab[row][col] == 'E')
		size->e_count ++;
    tab[row][col] = 'F';
	

    f_fill(tab, size, row - 1, col);
    f_fill(tab, size, row + 1, col);
    f_fill(tab, size, row, col - 1);
    f_fill(tab, size, row, col + 1);
	return;
}

void  flood_fill(char **tab, t_point *size, t_point begin)
{
    f_fill(tab, size, begin.y, begin.x);
}


#include <stdio.h>
#include <stdlib.h>
char **make_area(char **zone, int _x, int _y)
{
	char **area;
	area = (char **)malloc(sizeof(char *) * _y);
	for (int i = 0; i < _y; ++i)
	{
		area[i] = (char *)malloc(sizeof(char) * _x);
		for (int j = 0; j < _x; ++j)
			area[i][j] = zone[i][2 * j];
	}
	return (area);
}

int main(void)
{
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 P 0 C 0 0 C 1",
		"1 0 0 1 1 0 1 1",
		"1 0 0 C 1 0 C 1",
		"1 1 1 1 1 1 1 1",
	};
	t_point size  = {8, 5, 0, 0, 0};
	t_point begin = {2, 2, 0, 0, 0};

	char **area = make_area(zone, size.x, size.y);

	flood_fill(area, &size, begin);
	for (int y = 0; y < size.y; y++)
	{
		for (int x = 0; x < size.x; x++)
		{
			if (x != 0)
				printf(" ");
			printf("%c", area[y][x]);
		}
			free(area[y]);
		printf("\n");
	}
	printf("numero de C: %d de E: %d e de P:%d\n", size.c_count, size.e_count, size.p_count);
	free(area);
	return (0);
}