/*
** fonction2.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
** 
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
** 
** Started on  Tue Feb 14 09:18:14 2012 benjamin lehellaye
** Last update Thu Mar  1 17:23:51 2012 benjamin lehellaye
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

char	*get_path(char **env)
{
  int i;

  i = 0;
  while (my_strcmp(env[i], "PATH") != 0 && env[i] != NULL)
    i++;
  return (env[i] + 5);
}

char	*concate(char *s1, char *s2)
{
  char	*s_out;
  int	i;
  int	k;

  i = 0;
  k = 0;
  s_out = malloc((my_strlen(s1) + my_strlen(s2) + 1) * sizeof(*s_out));
  while (s1[i])
    s_out[k++] = s1[i++];
  s_out[k++] = '/';
  i = 0;
  while (s2[i] && s2[i] != ' ' && s2[i] != '\n')
    s_out[k++] = s2[i++];
  s_out[k] = 0;
  return (s_out);
}

char	*my_access(char **tab, char *path, char *buf)
{
  int	i;
  int	fd;

  i = 0;
  while (tab[i] && (fd != 0))
    {
      path = concate(tab[i++], buf);
      fd = access(path, X_OK);
    }
  if (fd == 0)
    return (path);
  return (0);
}
