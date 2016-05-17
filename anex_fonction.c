/*
** anex_fonction.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb 11 18:17:57 2016 Aurélien
** Last update Sat Feb 13 13:22:21 2016 Aurélien
*/

#include "my.h"

int		strlen_egal(char *str)
{
  int		i;

  i = 0;
  while (str[i] != '=' && str[i])
    i++;
  if (str[i] == '\0')
    return (-1);
  else
    return (i);
}

int             my_match(char *str, char *str2)
{
  int           i;

  i = 0;
  if (my_strlen(str) != my_strlen(str2))
    return (-1);
  while (str[i])
    {
      if (str[i] != str2[i])
	return (-1);
      i++;
    }
  return (0);
}

int		my_len_array(char **tab)
{
  int		i;

  i = 0;
  while (tab[i] != NULL)
    i++;
  return (i);
}

char		*erreur_fonct(char *tab)
{
  int		i;
  int		count;

  i = 0;
  count = 0;
  while (count < 2)
    {
      if (*tab == '/')
	count++;
      tab++;
    }
  return (tab);
}

char		*path_home(char *str)
{
  while (*str != '=' && *str)
    str++;
  str++;
  return (str);
}
