#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 200000,
  MAX_LEN = 4000000,
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

static int sort_f(
  const void *a,
  const void *b
)
{
  int32_t val_a = *(int32_t*)a;
  int32_t val_b = *(int32_t*)b;

  if (val_a < val_b) {
    return 1;
  }
  else {
    return -1;
  }
}


static void main_logic(
  int32_t n,
  int32_t num[]
)
{
  int32_t i;
  int32_t sum_odd = 0;
  int32_t sum_even = 0;
  int32_t odd_1 = -1;
  int32_t odd_2 = -1;
  int32_t even_1 = -1;
  int32_t even_2 = -1;
  int32_t exist_even = false;

  qsort(num, n, sizeof(int32_t), sort_f);

  // odd
  for (i = 0; i < n; i++) {
    if (num[i] % 2 == 1 && odd_1 < 0) {
      odd_1 = num[i];
      continue;
    }

    if (odd_1 > 0 && num[i] % 2 == 1) {
      odd_2 = num[i];
      break;
    }
  }

  if (odd_1 > 0 && odd_2 > 0) {
    sum_odd = odd_1 + odd_2;
    exist_even = true;
  }

  // even
  for (i = 0; i < n; i++) {
    if (num[i] % 2 == 0 && even_1 < 0) {
      even_1 = num[i];
      continue;
    }

    if (even_1 >= 0 && num[i] % 2 == 0) {
      even_2 = num[i];
      break;
    }
  }

  if (even_1 > 0 && even_2 >= 0) {
    sum_even = even_1 + even_2;
    exist_even = true;
  }

  if (exist_even) {
    printf("%d\n", (sum_odd > sum_even) ? sum_odd : sum_even);
  }
  else {
    printf("-1\n");
  }

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN]   = { 0 };
  int32_t   num[NUM_COUNT] = { 0 };
  char     *tmp       = NULL;
  int32_t   n = 0;

  tmp = fgets(str, MAX_LEN, stdin);
  n = strtol(str, NULL, 10);

  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, n, " ", num);

  main_logic(n, num);

  return 0;
}