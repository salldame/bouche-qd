/*
** minishell2.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
**
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
**
** Started on  Tue Feb  7 15:56:34 2012 benjamin lehellaye
** Last update Mon Mar 26 16:08:54 2012 kevin boucher
*/

#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

char	*prompt()
{
  int	ret;
  char *buf;

  my_putstr(" $>");
  buf = malloc(256 * sizeof(*buf));
  if ((ret = read(0, buf, 256)) == -1)
    exit(0);
  buf[ret] = 0;
  return (buf);
}

void	check_exit(char *buf)
{
  if (my_strcmp(buf, "exit\n") == 0)
    exit(0);
}

void	process(char **bufpath, char **tab, char **cmd, char **env)
{
  int	s;
  int pid;

  if (bufpath[0][0] != '\n')
    {
      if (((bufpath[1] = my_access(tab, bufpath[1], bufpath[0])) == 0)
	  && (bufpath[0][0] != 'c' || bufpath[0][1] != 'd')
	  && (bufpath[0][0] != 'u' || bufpath[0][1] != 'n'))
	my_putstr("Command not found.\n");
      my_command_cd(bufpath[0]);
      env = my_command_env(bufpath[0], env);
      if ((my_access(tab, bufpath[1], bufpath[0]) != 0)
	  && (bufpath[0][0] != 'c' || bufpath[0][1] != 'd'))
	{
	  pid = fork();
	  if (pid == 0)
	    execve(bufpath[1], cmd, env);
	  else if (pid > 0)
	    waitpid(pid, &s, 0);
	}
    }
}

void	 minishell2(char **env)
{
  char *bufpath[2];
  char **tab;
  char **cmd;

  while (42)
    {
      bufpath[0] = prompt();
      check_exit(bufpath[0]);
      bufpath[1] = get_path(env);
      tab = my_str_to_wordtab(bufpath[1]);
      cmd = my_str_to_wordtab2(bufpath[0]);
      process(bufpath, tab, cmd, env);
    }
}

int	main(int ac, char **av, char **env)
{
  char	**cpenv;

  cpenv = NULL;
  signal(SIGINT, SIG_IGN);
  if (ac > 1 && av[1] == NULL)
    return (0);
  clean_window();
  cpenv = cp_environ(env, cpenv);
  minishell2(cpenv);
  return (0);
}
