#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  MAX_LEN = 10000,
  INPUT_ROW_COUNT = 1,
  NUM_COUNT = 2,
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
  int multi = 0;
  char *tmp = NULL;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
  }

  split_str2int(str[0], 2, " ", num);
  multi = num[0] * num[1];
  printf("%s", multi % 2 == 0 ? "Even" : "Odd");

  return 0;
}