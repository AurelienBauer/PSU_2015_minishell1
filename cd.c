/*
** cd.c for  in /home/aurelien/rendu/Cycle_PSU/PSU_2015_minishell1
** 
** Made by Aurélien
** Login   <aurelien.bauer@epitech.net>
** 
** Started on  Fri Feb 12 12:03:03 2016 Aurélien
** Last update Sat Feb 13 11:20:48 2016 Aurélien
*/

#include "my.h"

char		*f_pwd()
{
  char		*pwd;
  char		*buff;

  if ((buff = malloc(sizeof(char) * PATH_MAX + 1)) == NULL)
    exit(1);
  if ((pwd = getcwd(buff, PATH_MAX + 1)) == NULL)
    exit(1);
  return (pwd);
}

void		cd_env(t_list *list)
{
  make_setenv(list, "OLDPWD", path_home(my_envmatch("PWD", list)));
  make_setenv(list, "PWD", f_pwd());
}

int		if_cd(char *path, t_list *list)
{
   path = path_home(my_envmatch("HOME", list));
   if (chdir(path) != 0)
     return (0);
   else
     cd_env(list);
   return (0);
}

int		if_cd_less(char *path, t_list *list)
{
   path = path_home(my_envmatch("OLDPWD", list));
   my_printf("%s\n", path);
   if (chdir(path) != 0)
     return (0);
   else
     cd_env(list);
   return (0);
}

int             make_path(char* path, t_list *list)
{
  if (path == NULL)
    if_cd(path, list);
  else if (my_match(path, "-\0") != -1)
    if_cd_less(path, list);
  else
    {
      if (chdir(path) != 0)
	{
	  my_printf("mysh: cd: %s: Aucun fichier ou dossier de ce type\n", path);
	  return (0);
	}
      else
	cd_env(list);
    }
  return (0);
}
