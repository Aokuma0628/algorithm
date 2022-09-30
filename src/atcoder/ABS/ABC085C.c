#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 1,
  NUM_COUNT = 2,
  MAX_LEN = 32,
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

static int main_logic(
  int num,
  int amount
)
{
  int i, j;

  for (i = 0; i <= num; i++) {
    for (j = 0; i + j <= num; j++) {
      if (10000 * i + 5000 * j + 1000 * (num - i - j) == amount) {
          goto l_find;
      }
    } 
  }

  printf("%d %d %d", -1, -1, -1);
  return OK;

l_find:
  printf("%d %d %d", i, j, num - (i + j));

  return OK;
}


int main(void)
{
  int   i;
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int   num[NUM_COUNT] = { 0 };
  char *tmp = NULL;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }
  split_str2int(str[0], NUM_COUNT, " ", num);

  main_logic(num[0], num[1]);

  return 0;
}