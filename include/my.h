/*
** my.h for my_h_ in /home/bauer_b/rendu/Piscine_C_infinadd/include
** 
** Made by Aurélien BAUER
** Login   <bauer_b@epitech.net>
** 
** Started on  Mon Oct 26 19:04:41 2015 Aurélien BAUER
** Last update Sat Feb 13 12:24:07 2016 Aur�lien
*/

#ifndef MY_H_
# define MY_H_

#include <sys/wait.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <pwd.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>

typedef struct	s_list
{
  void		*data;
  struct s_list *next;
}		t_list;

/*
***
fonction lib
***
*/

int		my_power_it(int nb, int power);
void		my_putchar(char c);
char		my_putnbr(int nbr);
int		my_putstr(char *str);
int		my_strlen(char *str);
int		my_nbrlen(int nbr);
char		*my_revstr(char *str);
int		my_put_unsignednbr(unsigned int nbr);
int		my_printf(const char *str, ...);
int		put_convert_to_nbase(unsigned int nbr, int base, char b);
int		put_convert_to_oct(char rest);
int		maj_S(const char *str);
int		make_d_i(int nbr);
int		make_c(int c);
int		make_s(char *str);
int		make_u(unsigned int nbr);
int		make_p(long long nbr);
int		my_getnbr(char  *str);
int		my_nbrlen_array(int *array);
char		*my_clchar_in_str(char *str, char car);
char		*my_strcat(char *data, char *add);
char		*uint_to_char(unsigned int nbr);
int		fs_open_file(char *filepath);
void		fs_understand_return_of_read(int fd, char *buffer, int size);
char		*get_next_line(const int fd);
char		**my_str_to_wordtab(char *str);
char		**my_str_to_wordtab(char *str);
char		*my_strcpy(char *str, char *dest);
t_list          *add_elem_inlist(t_list *list, void *data);
t_list          *suppr_elem_list(t_list *list, int nb_elem);

/*
***
mysh.c
***
*/
int             f_execv(char **tab, t_list *list);
void            setun_env(char **tab, t_list *list);
void            unset_env(char **tab, t_list *list);
void            mysh(struct stat *buf, t_list *list, char *buff);

/*
***
env.c
***
*/
void            disp_env_inlist(t_list *list);
t_list		*put_in_list(char **env);
void		make_setenv(t_list *list, char *name, char *path);
char            *my_envmatch(char *str, t_list *list);
void            make_unsetenv(t_list *list, char *name);

/*
***
anex_fonction
***
*/
int		strlen_egal(char *str);
int             my_match(char *str, char *str2);
int             my_len_array(char **tab);
char            *erreur_fonct(char *tab);
char		*path_home(char *str);

/*
***
cd.c
***
*/
char		*f_pwd();
void		cd_env(t_list *list);
int             if_cd(char *path, t_list *list);
int             if_cd_less(char *path, t_list *list);
int             make_path(char* path, t_list *list);

/*
***
pass_env_exec
***
*/
char            **pass_env_exec(t_list *list);

#endif /* !MY_H_ */
