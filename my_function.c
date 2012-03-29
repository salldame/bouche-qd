/*
** my_function.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
**
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
**
** Started on  Tue Feb 14 11:14:34 2012 benjamin lehellaye
** Last update Tue Mar 27 18:17:31 2012 kevin boucher
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

int	my_command_cd(char *path)
{
  char *buf;
  int i;
  int j;
  int var;

  i = 0;
  j = 3;
  buf = malloc(256);
  if (path[0] == 'c' && path[1] == 'd' && path[2] == '\n')
    chdir("/home/bouche_p/");
  else if (path[0] == 'c' && path[1] == 'd' && path[2] == ' ')
    {
      while (path[j] && path[j] != '\n')
	buf[i++] = path[j++];
      var = chdir(buf);
      if (var == -1)
	{
	  my_putstr(buf);
	  my_putstr(" : No such file or directory\n");
	}
      return (0);
    }
  return (1);
}
