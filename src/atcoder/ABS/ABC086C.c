#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 100010,
  NUM_COUNT = 3,
  MAX_LEN = 32,
  FALSE = 0,
  TRUE = 1,
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

  if (!str || !split || num < 0) {
    return NG;
  }

  tmp = strtok_r(tmp, del, &ptr);
  for (i = 0; i < num; i++) {
    char *end = NULL;
    int val = strtol(tmp, &end, 10);

    if (*end != '\0' && *end != '\n') {
      return NG;
    }
    split[i] = val;
    tmp = strtok_r(NULL, del, &ptr);
  }

  return OK;
}

static int main_logic(
  int count,
  int num[][NUM_COUNT]
)
{
  int i;
  int pt = 0;
  int px = 0;
  int py = 0;

  if (!num) {
    return NG;
  }

  for (i = 0; i < count; i++) {
    int ti = num[i][0];
    int xi = num[i][1];
    int yi = num[i][2];

    int dt = ti - pt;
    int dist = abs(xi - px) + abs(yi - py);

    if (dt < dist) {
      printf("No");
      return NG;
    }

    if (dt % 2 != dist % 2) {
      printf("No");
      return NG;
    }

    pt = ti;
    px = xi;
    py = yi;
  }

  printf("Yes");

  return OK;
}


int main(void)
{
  int   i;
  char  str[MAX_LEN] = { 0 };
  int   num[INPUT_ROW_COUNT][NUM_COUNT] = { { 0 } };
  int   count = 0;
  char *tmp = NULL;

  tmp = fgets(str, MAX_LEN, stdin);
  count = strtol(str, NULL, 10);

  for (i = 0; i < count; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", num[i]);
    (void)tmp;
  }

  main_logic(count, num);

  return 0;
}