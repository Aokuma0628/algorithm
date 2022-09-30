#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 2,
  NUM_COUNT = 100,
  MAX_LEN = 10000,
};


static int split_str2int(
  char   *str,
  int     num,
  char   *del,
  int    *split
)
{
  int   i   = 0;
  char *tmp = str;
  char *ptr = NULL;
  char *end = NULL;
  int   val = 0;

  if (!str || !split || num < 0) {
    return NG;
  }

  tmp = strtok_r(tmp, del, &ptr);
  for (i = 0; i < num; i++) {
    val = strtol(tmp, &end, 10);
    if (*end != '\0' && *end != '\n') {
      return NG;
    }
    split[i] = val;
    tmp = strtok_r(NULL, del, &ptr);
  }

  return OK;
}

static int compar(
  const void *n1,
  const void *n2
)
{
  int a1 = *(int *)n1;
  int a2 = *(int *)n2;

  if (a1 > a2) {
    return -1;
  }
  else if (a1 < a2) {
    return 1;
  }
  else {
    return 0;
  }
}



static int main_logic(
  int n,
  int *a
)
{
  int i;
  int total = 0;

  qsort(a, n, sizeof(int), compar);

  for (i = 0; i < n; i++) {
    if (i % 2 == 0) {
      total += a[i];
    }
    else {
      total -= a[i];
    }
  }

  printf("%d", total);

  return OK;
}


int main(void)
{
  int   i;
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int   num[NUM_COUNT] = { 0 };
  char *tmp = NULL;
  int   count = 0;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

  count = strtol(str[0], NULL, 10);
  split_str2int(str[1], count, " ", num);

  main_logic(count, num);

  return 0;
}