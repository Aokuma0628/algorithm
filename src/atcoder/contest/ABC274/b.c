#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 2,
  INPUT_COUNT = 1000,
  MAX_LEN = 1020,
};


static int32_t split_str2int(
  char     *str,
  int32_t   num,
  char     *del,
  int32_t  *split
)
{
  int32_t i = 0;
  char *tmp = str;
  char *ptr = NULL;
  int32_t cnt = 0;

  if (!str || !split || num < 0) {
    return NG;
  }

  tmp = strtok_r(tmp, del, &ptr);
  for (i = 0; i < num; i++) {
    char *end = NULL;
    int32_t val = strtol(tmp, &end, 10);

    if (*end != '\0' && *end != '\n') {
      return NG;
    }
    split[i] = val;
    tmp = strtok_r(NULL, del, &ptr);
    cnt++;
    if (split[0] < cnt) return OK;
  }

  return OK;
}


static void main_logic(
  int32_t h,
  int32_t w,
  char str[][MAX_LEN]
)
{
  int32_t i,j;

  for (i = 0; i < w; i++) {
    int32_t cnt = 0;
    for (j = 0; j < h; j++) {
      if (str[j][i] == '#') cnt++;
    }
    if (i != 0) printf(" ");
    printf("%d", cnt);
  }

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   num[NUM_COUNT] = { 0 };
  char      str_arr[INPUT_COUNT][MAX_LEN] = {{ 0 }};
  char     *tmp       = NULL;
  int32_t   i;
  
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, NUM_COUNT, " ", num);


  for (i = 0; i < num[0]; i++) {
    tmp = fgets(str_arr[i], MAX_LEN, stdin);
  }

  main_logic(num[0], num[1], str_arr);

  return 0;
}