/*
** fonction.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
** 
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
** 
** Started on  Wed Feb  8 11:29:19 2012 benjamin lehellaye
** Last update Fri Mar  2 11:45:46 2012 benjamin lehellaye
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}

int	my_strlen(char *str)
{
  int	i;

  i = 0;
  while (str[i])
    i++;
  return (i);
}

void	my_putstr(char *str)
{
  write(1, str, my_strlen(str));
}

int	my_strncmp(char *s1, char *s2, int len)
{
  int i;

  i = 0;
  while (i < len)
    {
      if (s1[i] != s2[i])
	return (0);
      else
	i++;
    }
  return (1);
}

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (s2[i])
    {
      if (s1[i] != s2[i])
	return (1);
      i++;
    }
  return (0);
}
