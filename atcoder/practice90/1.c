#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 3,
  NUM_COUNT = 100000,
  MAX_LEN = 2000000,
  FALSE = 0,
  TRUE = 1,
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

  if (!str || !split || num < 0) {
    return NG;
  }

  tmp = strtok_r(tmp, del, &ptr);
  for (i = 0; i < num; i++) {
    char *end = NULL;
    int val = strtol(tmp, &end, 10);

    if (*end != '\0' && *end != '\n') {
      return NG;
    }
    split[i] = val;
    tmp = strtok_r(NULL, del, &ptr);
  }

  return OK;
}

static int can_split_length (
  int mid,
  int n,
  int l,
  int k,
  int *a
)
{
  int cnt = 0;
  int pre = 0;
  int i;
  
  for (i = 0; i < n; i++) {
    if (a[i] - pre >= mid && l - a[i] >= mid) {
      pre = a[i];
      cnt++;
    }
  }

  if (cnt >= k) return TRUE;

  return FALSE;
}


static int main_logic(
  int count,
  int len,
  int k,
  int *num
)
{
  int left = 0;
  int right = len;

  // 二分探索
  while (right - left > 1) {
    int mid = left + (right - left) / 2;
    if (can_split_length(mid, count, len, k, num)) {
      left = mid;
    }
    else {
      right = mid;
    }
  }

  printf("%d", left);

  return OK;
}


int main(void)
{
  char  str[MAX_LEN] = { 0 };
  int   num[NUM_COUNT] = { 0 };
  int   count = 0;
  int   len   = 0;
  int   k = 0;
  char *tmp = NULL;

  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, 2, " ", num);
  count = num[0];
  len = num[1];
  
  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  k = strtol(str, NULL, 10);

  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, count, " ", num);
  (void)tmp;

  main_logic(count, len, k, num);

  return 0;
}