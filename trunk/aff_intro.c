/*
** affichage.c for minishell2 in /home/lehell_b//Documents/local/projets/semestre2/minishell2
**
** Made by benjamin lehellaye
** Login   <lehell_b@epitech.net>
**
** Started on  Tue Feb  7 17:15:13 2012 benjamin lehellaye
** Last update Tue Mar 27 14:44:15 2012 kevin boucher
*/

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

void	clean_window()
{
  my_putstr("\033[H\033[2J");
  start_mysh();
}
