#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 3,
  MAX_LEN = 64,
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
  }

  return OK;
}


static int32_t sort_func(
  void *a,
  void *b
)
{
  int32_t val_a = *(int32_t *)a;
  int32_t val_b = *(int32_t *)b;

  if (val_a > val_b) {
    return -1;
  }
  else {
    return 1;
  }
}


static void main_logic(
  int32_t price,
  int32_t coin[]
)
{
  int32_t num = 0;
  int32_t min_num = 9999;
  int32_t i, j;
  
  if (!coin) return ;

  qsort(coin, NUM_COUNT, sizeof(int32_t), sort_func);

  for (i = price / coin[0]; i >= 0; i--) {
    int32_t remain = price - (coin[0] * i);

    if (remain == 0) {
      num = i;
      if (min_num > num) min_num = num;
    }

    if (coin[1] > remain && coin[2] > remain) {
      continue;
    }

    for (j = remain / coin[1]; j >= 0; j--) {
      int32_t mid_rem = remain - (coin[1] * j);
      int32_t min_rem = mid_rem % coin[2];

      if (mid_rem == 0) {
        num = i + j;
        if (min_num > num) min_num = num;
      }
      if (min_rem == 0) {
        num = i + j + (mid_rem / coin[2]);
        if (min_num > num) min_num = num;
      }
    }
  }

  printf("%d\n", min_num);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   coin[NUM_COUNT] = { 0 };
  int32_t   price    = 0;
  char     *tmp       = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  price = strtol(str, NULL, 10);
  
  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, NUM_COUNT, " ", coin);

  main_logic(price, coin);

  return 0;
}