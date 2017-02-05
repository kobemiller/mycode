#include <stdio.h>

int main()
{
  FILE *fp = NULL;
  unsigned int v_int1, v_int2;
  unsigned char v_c1[50], v_c2[50];

  fp = fopen("./config.ini", "r");
  if (NULL == fp)
  {
    printf("open config file error!\n");
    return -1;
  }

  fscanf(fp, "%s", v_c1);
  fscanf(fp, "%d", &v_int1);
  fscanf(fp, "%s", v_c2);
  fscanf(fp, "%d", &v_int2);

  printf("v_c1:%s\n", v_c1);
  printf("v_int1:%d\n", v_int1);
  printf("v_c2:%s\n", v_c2);
  printf("v_int2:%d\n", v_int2);

  return 0;
}
