/*
** mysh.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Thu Feb  4 10:41:11 2016 Aurélien
** Last update Sat Feb 13 12:06:52 2016 Aurélien
*/

#include "my.h"

int		f_execv(char **tab, t_list *list)
{
  pid_t		cpid;
  int		status;

  cpid = fork();
  if (cpid == 0)
    execve(tab[0], tab, pass_env_exec(list));
  while (waitpid(cpid, &status, 0) == 1);
  return (0);
}

void		setun_env(char **tab, t_list *list)
{
  if (my_len_array(tab) >= 3)
    make_setenv(list, tab[1], tab[2]);
  else
    my_printf("USAGE: setenv [name] [value]\n");
}

void		unset_env(char **tab, t_list *list)
{
  if (my_len_array(tab) >= 2)
    make_unsetenv(list, tab[1]);
  else
    my_printf("USAGE: unsetenv [name]\n");
}

void		mysh(struct stat *buf, t_list *list, char *buff)
{
  char		**tab;

  tab = my_str_to_wordtab(buff);
  if (my_match(tab[0], "env") != -1)
    disp_env_inlist(list);
  else if (my_match(tab[0], "setenv") != -1)
    setun_env(tab, list);
  else if (my_match(tab[0], "unsetenv") != -1)
    unset_env(tab, list);
  else if (my_match(tab[0], "exit") != -1)
    exit (0);
  else if (my_match(tab[0], "cd") != -1)
    make_path(tab[1], list);
  else
    {
      if (stat(tab[0], buf) == -1)
	tab[0] = my_strcat("/bin/", tab[0]);
      if (stat(tab[0], buf) == -1)
	my_printf("mysh: %s : commande introuvable\n", erreur_fonct(tab[0]));
      else
	f_execv(tab, list);
    }
  free(tab);
}

int		main(int argn, char **argv, char **env)
{
  struct stat	*buf;
  char		*buffer;
  t_list	*list;

  list = NULL;
  list = put_in_list(env);
  if ((buf = malloc(sizeof(struct stat) * 1)) == NULL)
    return (0);
  while (1)
    {
      my_printf("$>");
      if ((buffer = get_next_line(0)) == NULL)
	return (0);
      mysh(buf, list, buffer);
    }
}
