/*
** pass_env_exec.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Sat Feb 13 12:04:13 2016 Aurélien
** Last update Sat Feb 13 12:26:47 2016 Aurélien
*/

#include "my.h"

int		len_list(t_list *list)
{
  int		i;

  i = 0;
  while (list != NULL)
    {
      list = list->next;
      i++;
    }
  return (i);
}

char		**alloc_env(t_list *list, char **env)
{
  if ((env = malloc(sizeof(char*) * len_list(list) + 1)) == NULL)
    exit(1);
}

char		**pass_env_exec(t_list *list)
{
  char		**env;
  int		i;

  i = 0;
  env = alloc_env(list, env);
  while (list != NULL)
    {
      env[i] = (char*)list->data;
      i++;
      list = list->next;
    }
  return (env);
}
