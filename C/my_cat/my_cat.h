/*
** my_cat.h for my_cat.h in /Users/laxa/Documents/C/my_cat/egloff_j
** 
** Made by Julien EGLOFF
** Login   <laxa>
** 
** Started on  Mon Jun 16 10:15:06 2014 Julien EGLOFF
** Last update Thu Jun 26 12:13:25 2014 Julien EGLOFF
*/

#ifndef __MY_CAT_H__
# define __MY_CAT_H__

# define BUFFER_SIZE 4096

typedef struct	s_opt
{
  int		e;
  int		b;
  int		n;
  int		stdin;
}		t_opt;

/* xfopen.c */
FILE		*xfopen(const char *filename, const char *mode);
/* xfclose.c */
int		xfclose(FILE *stream);
/* main.c */
void		cat_error(char c);
t_opt   	init_struct(int ac, char **av);
t_opt		check_stdin(int ac, char **av, t_opt opt);
/* cat_stdin.c */
void		cat_stdin(t_opt opt);
void		print_spaces(int line);
void		print_line(int *line);
/* cat_file.c */
void		cat_file(t_opt opt, FILE *file);

#endif /* __MY_CAT__ */
