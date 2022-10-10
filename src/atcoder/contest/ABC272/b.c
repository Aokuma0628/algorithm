#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 101,
  INPUT_COUNT = 100,
  MAX_LEN = 400,
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
  int32_t n,
  int32_t m,
  int32_t num[][NUM_COUNT]
)
{
  bool is_yes = true;
  bool ans[NUM_COUNT][NUM_COUNT] = {{ false }};
  int32_t i,j,k;

  for (i = 0; i < m; i++) {
    for (j = 1; j < num[i][0]; j++) {
      for (k = j + 1; k <= num[i][0]; k++) {
        int32_t x = num[i][j] - 1;
        int32_t y = num[i][k] - 1;

        if (x < y) {
          ans[x][y] = true;
        }
        else {
          ans[y][x] = true;
        }
      }
    }
  }

  for (i = 0; i < n; i++) {
    for (j = i + 1; j < n; j++) {
      if (ans[i][j] == false) is_yes = false;
    }
  }

  printf("%s\n", is_yes ? "Yes" : "No");

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   nm[2] = { 0 };
  int32_t   num[INPUT_COUNT][NUM_COUNT] = {{ 0 }};
  char     *tmp       = NULL;
  int32_t   n = 0;
  int32_t   m = 0;
  int32_t   i;
  
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, 2, " ", nm);
  n = nm[0];
  m = nm[1];

  for (i = 0; i < m; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", num[i]);
  }

  main_logic(n, m, num);

  return 0;
}