/*
** minishell2.h for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
**
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
**
** Started on  Tue Feb 14 09:33:15 2012 benjamin lehellaye
** Last update Tue Mar 27 14:30:30 2012 kevin boucher
*/

#ifndef	__MINISHELL2_H__

#define	__MINISHELL2_H__

void	clean_window();
void	start_mysh();
void	my_putchar(char c);
int	my_strlen(char *str);
void	my_putstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_strncmp(char *s1, char *s2, int len);
char	*get_path(char **env);
char	*concate(char *s1, char *s2);
char	*my_access(char **tab, char *path, char *buf);
char	*prompt();
void	check_exit(char *buf);
void	process(char **bufpath, char **tab, char **cmd, char **env);
void	minishell2(char **env);
int	main(int ac, char **av, char **env);
int	my_command_cd(char *path);
char	**my_str_to_wordtab(char *str);
char	**my_str_to_wordtab2(char *str);
char	**cp_environ(char **env, char **cpenv);
char	**my_command_env(char *buf, char **cpenv);
void	aff_environ(char **cpenv);
char	**cp_environ(char **env, char **cpenv);

#endif
