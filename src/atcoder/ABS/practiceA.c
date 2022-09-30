#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  MAX_LEN = 100,
  INPUT_ROW_COUNT = 3,
  NUM_COUNT = 3,
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
  char buf[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int second[2] = { 0 };
  int first = 0;
  int sum = 0;
  char *tmp = NULL;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(buf[i], MAX_LEN, stdin);
  }

  first = strtol(buf[0], NULL, 10);
  split_str2int(buf[1], 2, " ", second);
  sum = first + second[0] + second[1];
  printf("%d %s", sum, buf[2]);

  return 0;
}