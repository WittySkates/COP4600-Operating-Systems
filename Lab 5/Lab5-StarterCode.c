#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>

int main()
{
  // We use 4 pipes
  // First pipe to send input string from parent
  // Second pipe to send concatenated string from child
  // Third pipe to send concat string from parent
  // Fourth pipe to send reversed string from child
  char fixed_str[] = " world";
  char input_str[100];
  pid_t p;
  p = fork();
  if (p < 0)
  {
    fprintf(stderr, "fork Failed" );
    return 1;
  }
  else if (p > 0)
  {
    // Parent process
    p = fork();

    if (p < 0)
    {
      fprintf(stderr, "fork Failed" );
      return 1;
    }
    else if (p > 0)
    {
    }
    else // child process
    {
      exit(0);
    }
  }
  else // child process
  {
    exit(0);
  }
}
