
#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "minishell2.h"

char 	**my_command_env(char *buf, char **cpenv)
{
  if (buf[0] == 'e' && buf[1] == 'n' && buf[2] == 'v')
    aff_environ(cpenv);
  return (cpenv);
}

void	aff_environ(char **cpenv)
{
  int i;

  i = 0;
  while (cpenv[i])
      my_putstr(cpenv[i++]);
}

char	**cp_environ(char **env, char **cpenv)
{
  int i;
  int j;

  i = 0;
  j = 0;
  cpenv = malloc(80 * sizeof (*env));
  while (env[i])
    {
      cpenv[i] = malloc(my_strlen(env[i]) * sizeof (**env));
      cpenv[j] = env[i];
      i++;
      j++;
    }
  return (cpenv);
}
