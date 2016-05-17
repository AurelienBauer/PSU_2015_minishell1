/*
** my_getnbr.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Tue May 10 12:03:23 2016 Aurélien
** Last update Tue May 10 12:03:25 2016 Aurélien
*/

int	my_getnbr(char	*str)
{
  int	nb;
  int	i;
  int	signe;

  i = 0;
  nb = 0;
  while (str[i] < 48 || str[i] > 57)
    i = i + 1;
  while (str[i] > 47 && str[i] < 58)
    {
      nb = (nb * 10) + (str[i] - '0');
      if (str[i - 1] == '-')
	signe = 1;
      i = i + 1;
    }
  if (signe == 1)
    nb = nb * -1;
  return (nb);
}
