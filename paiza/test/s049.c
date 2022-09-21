#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 4,
  MAX_LEN = 64,
};

int split_str2int(
  char   *str,
  int     num,
  char    del,
  int    *split
)
{
  int   i   = 0;
  char *tmp = str;
  char *end = NULL;

  if (!str || !split) {
    return NG;
  }

  while(1) {
    int val = strtol(tmp, &end, 10);
    split[i] = val;

    i++;
    if(*end == '\0' || i >= num) {
      break;
    }

    tmp = end;
    tmp++;
    end = NULL;
  }

  return OK;
}


static void main_logic(
  int32_t n,
  int32_t x,
  int32_t f,
  int32_t s
)
{
  int32_t line = 0;
  int32_t hour = 0;
  int32_t proc = x;
  bool    now_sleep = false;

  while (line < n) {

    if (proc <= (s / 3) && (n - line) > proc) {
      proc = (proc + s) > x ? x : (proc + s);
      hour += 3;
      continue;
    }

    line += proc;
    proc -= f;
    hour++;
  } 

  printf("%d\n", hour);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   num[NUM_COUNT] = {{ 0 }};
  char     *tmp = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, NUM_COUNT, " ", num);

  main_logic(num[0], num[1], num[2], num[3]);

  return 0;
}