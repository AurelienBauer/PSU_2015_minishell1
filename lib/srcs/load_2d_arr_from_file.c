/*
** load_2d_arr_from_file.c for  in /home/aurelien/rendu/CPE_2015_BSQ_bootstrap
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Wed Dec  2 11:04:38 2015 Aurélien
** Last update Mon Dec  7 12:40:03 2015 Aurélien
*/

#include <stdlib.h>

char	**mem_allo_2d_array(int nb_rows, int nb_cols);
int	fs_open_file(char *filepath);
void    fs_understand_return_of_read(int fd, char *buffer, int size);

char	**d_to_2d_arr(char *buffer, int nb_rows, int nb_cols)
{
  char **ret;
  int	i;
  int	j;

  i = -1;
  j = -1;
  ret = mem_allo_2d_array(nb_rows, nb_cols);
  while (++i < nb_cols)
    {
      while (++j < nb_rows + 1)
	{
	  ret[i][j] = *buffer;
	  buffer++;
	}
      j = -1;
    }
  return (ret);
}

char	**load_2d_arr_from_file(char *filepath, int nb_rows, int nb_cols)
{
  int	fd;
  char	*buffer;
  char	**ret;
  if ((buffer = malloc(sizeof(char) * (nb_rows * nb_cols + nb_cols))) == NULL)
    return (0);
  if ((fd = fs_open_file(filepath)) == -1)
    return (0);
  fs_understand_return_of_read(fd, buffer, (nb_rows * nb_cols + nb_cols));
  return (ret = d_to_2d_arr(buffer, nb_rows, nb_cols));
}
