/*
** find_biggest_square.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Wed Dec  2 12:40:27 2015 Aurélien
** Last update Sat Dec 26 15:51:55 2015 Aurélien
*/

char    **load_2d_arr_from(char *filepath, int nb_rows, int nb_cols);

typedef struct          s_doncube
{
  int                   x;
  int			y;
  int			size;
}                       t_doncube;

int	find_biggest_square(char **map, int size_map, t_doncube donne_cube)
{
  int   i;
  int   j;
  int	ret;

  i = donne_cube.x - 1;
  j = donne_cube.y - 1;
  ret = 1;
  donne_cube.size = 0;
  while (ret == 1 && donne_cube.size != size_map - 1)
    {
      donne_cube.size++;
      while (++i < (donne_cube.y + donne_cube.size))
	{
	  while(++j < (donne_cube.x + donne_cube.size))
	    {
	      if (map[i][j] == 'o')
		ret = 0;
	    }
	  j = donne_cube.x - 1;
	}
      i = donne_cube.y - 1;
    }
  return (donne_cube.size - 1);
}
