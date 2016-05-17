/*
** env.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb 11 12:27:24 2016 Aurélien
** Last update Sat Feb 13 11:16:34 2016 Aurélien
*/

#include "my.h"

void            disp_env_inlist(t_list *list)
{
  while (list != NULL)
    {
      my_printf("%s\n", (char *)list->data);
      list = list->next;
    }
}

char		*my_envmatch(char *str, t_list *list)
{
  int		j;
  int		count;

  while (list != NULL)
    {
      j = 0;
      count = 0;
      while (((char *)list->data)[j] && ((char *)list->data)[j] == str[j])
	{
	  if (((char *)list->data)[j] == str[j])
	    count++;
	  if (count == my_strlen(str) && count == strlen_egal((char*)list->data))
	      return ((char*)list->data);
	  j++;
	}
      list = list->next;
    }
  return (NULL);
}

t_list		*put_in_list(char **env)
{
  t_list	*list;

  list = NULL;
  while (*env)
    {
      list = add_elem_inlist(list, (void*)*env);
      env++;
    }
  return (list);
}

void		make_setenv(t_list *list, char *name, char *path)
{
  char		*buff;

  if ((buff = my_envmatch(name, list)) == NULL)
    {
      buff = my_strcat(name, my_strcat("=\0", path));
      list = add_elem_inlist(list, (void*)buff);
    }
  else
    {
      while (my_match(buff, (char*)list->data) == -1)
	list = list->next;
      list->data = (void*)my_strcat(name, my_strcat("=\0", path));
    }
}

void		make_unsetenv(t_list *list, char *name)
{
  while (my_match(my_envmatch(name, list), (char*)list->next->data) == -1)
    list = list->next;
  list->next = list->next->next;
}
