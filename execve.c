#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
  char *newargv[] = { "md5sum", "--check", "f1f2", NULL };  //参数最后一个必须是NULL
  char *newenv[] = { NULL };

  execve("/usr/bin/md5sum", newargv, newenv);
  printf("execve error!\n");  //execve只有在出错时才会返回
  return -1;
}
