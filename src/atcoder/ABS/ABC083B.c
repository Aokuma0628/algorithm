#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 1,
  NUM_COUNT = 3,
  MAX_LEN = 20,
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


static int calc_digits_sum(
  int val
)
{
  int sum = 0;

  while(val != 0) {
    sum += val % 10;
    val /= 10;
  }

  return sum;
}

static int main_logic(
  int n,
  int a,
  int b
)
{
  int i;
  int sum = 0;
  int total = 0;

  for (i = 1; i <= n; i++) {
    sum = calc_digits_sum(i);
    if (sum >= a && sum <= b) {
      total += i;
    }
  }

  printf("%d", total);

  return OK;
}


int main(void)
{
  int i;
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  int   num[NUM_COUNT] = { 0 };
  char *tmp = NULL;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

  split_str2int(str[0], NUM_COUNT, " ", num);

  main_logic(num[0], num[1], num[2]);

  return 0;
}