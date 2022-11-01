#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 2,
  MAX_LEN = 40,
};


static int32_t split_str2int(
  char     *str,
  int32_t   num,
  char     *del,
  int64_t  *split
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
    int64_t val = strtol(tmp, &end, 10);

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
  int64_t x,
  int32_t k
)
{
  int32_t i;
  int64_t ans = x;
  int64_t factor = 10;
  

  for (i = 0; i < k; i++) {
    double val = (double)ans / (double)factor;
    ans = (int64_t) (val + 0.5);
    ans *= factor;
    factor *= 10;
  }

  printf("%lld\n", ans);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int64_t   num[NUM_COUNT] = { 0 };
  char     *tmp       = NULL;
  
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, NUM_COUNT, " ", num);

  main_logic(num[0], num[1]);

  return 0;
}