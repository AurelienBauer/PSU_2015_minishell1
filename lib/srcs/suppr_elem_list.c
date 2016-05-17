/*
** suppr_elem_list.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1/lib/srcs
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Sat Feb 13 10:15:25 2016 Aurélien
** Last update Sat Feb 13 11:07:58 2016 Aurélien
*/

#include <stdlib.h>

typedef struct	s_list
{
  void		*data;
  struct s_list	*next;
}		t_list;

t_list		*suppr_elem_list(t_list *list, int nb_elem)
{
  while (--nb_elem > -1)
    list = list->next;
  list->next = NULL;
  return (list);
}
