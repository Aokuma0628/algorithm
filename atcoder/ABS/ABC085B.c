#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 101,
  NUM_COUNT = 101,
  MAX_LEN = 8,
};

static int compar(
  const void *n1,
  const void *n2
)
{
  int a1 = *(int *)n1;
  int a2 = *(int *)n2;

  if (a1 > a2) {
    return 1;
  }
  else if (a1 < a2) {
    return -1;
  }
  else {
    return 0;
  }
}



static int main_logic(
  int count,
  int *arr
)
{
  int i;
  int length = 0;
  int num = 0;

  qsort(arr, count, sizeof(int), compar);

  for (i = 0; i < count; i++) {
    if (length < arr[i]) {
      length = arr[i];
      num++;
    }
  }

  printf("%d", num);

  return OK;
}


int main(void)
{
  int   i;
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int   num[NUM_COUNT] = { 0 };
  char *tmp = NULL;
  char *ptr = NULL;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    num[i] = strtol(str[i], &ptr, 10);
    if (*ptr != '\0' && *ptr != '\n') {
      printf("[%d]err=%c\n", i, *ptr);
      return NG;
    }
    (void)tmp;
  }

  main_logic(num[0], &num[1]);

  return 0;
}