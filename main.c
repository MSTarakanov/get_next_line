#include "get_next_line.h"
#include <fcntl.h>

int main(int argc, char* argv[])
{
  int   fd;
  char  *line = NULL;

  if (argc == 1)
    fd = 0;
  else if (argc > 1)
  {
    argv++;
    while (*argv)
    {
      fd = open(*argv, O_RDONLY);
      while (get_next_line(fd, &line))
      {
        ft_putendl(line);
        free(line);
      }
      ft_putendl(line);
      free(line);
      close(fd);
      argv++;
    }
  }
}
