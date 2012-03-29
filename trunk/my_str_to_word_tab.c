/*
** my_str_to_word_tab.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
**
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
**
** Started on  Tue Feb 14 09:17:47 2012 benjamin lehellaye
** Last update Thu Mar 29 17:00:49 2012 kevin boucher
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

char	**my_str_to_wordtab(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  k = 0;
  tab = malloc(my_strlen(str) * sizeof(*tab));
  while (str[k])
    {
      j = 0;
      tab[i] = malloc(my_strlen(str) * sizeof(*tab[i]));
      while (str[k] != ':' && str[k] != 0)
	tab[i][j++] = str[k++];
      tab[i][j] = 0;
      if (str[k] != 0)
	k++;
      i++;
    }
  tab[i] = 0;
  return (tab);
}

char	**my_str_to_wordtab2(char *str)
{
  int	i;
  int	j;
  int	k;
  char	**tab;

  i = 0;
  k = 0;
  tab = malloc(my_strlen(str) * sizeof(*tab));
  while (str[k] != '\n')
    {
      j = 0;
      tab[i] = malloc(my_strlen(str) * sizeof(*tab[i]));
      while (str[k] != ' ' && str[k] != '\n')
	tab[i][j++] = str[k++];
      tab[i][j] = 0;
      if (str[k] == ' ')
	k++;
      i++;
    }
  return (tab);
}
