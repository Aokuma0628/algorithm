#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 2,
  NUM_COUNT = 200,
  MAX_LEN = 10 * 200,
};


int split_str2int(
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


int main(void)
{
  int i;
  char str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int num[NUM_COUNT] = { 0 };
  char *tmp = NULL;
  int count = 0;
  int ope = 0;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

  count = strtol(str[0], NULL, 10);
  split_str2int(str[1], count, " ", num);
  while (1) {
    for (i = 0; i < count; i++) {
      if (num[i] % 2 != 0) {
        break;
      }
      num[i] = num[i] / 2;
    }
    if (i < count) {
      break;
    }
    ope++;
  }
  printf("%d", ope);

  return 0;
}