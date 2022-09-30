#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW = 10000,
  NUM_COUNT = 2,
  MAX_LEN = 16,
};

static int32_t split_str2int(
  char     *str,
  int32_t   num,
  char     *del,
  int32_t  split[]
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


static void main_logic(
  int32_t num,
  int32_t work[][NUM_COUNT]
)
{
  int32_t max = 0;
  int32_t cnt = 0;
  int32_t m_cnt = 0;
  int32_t i, j;
  
  for (i = 0; i < num; i++) {
    if (max < work[i][1]) max = work[i][1];
  }
  
  j = 1;
  while (j <= max) {
    bool in_value = false;

    for (i = 0; i < num; i++) {
      if (work[i][0] <= j && j <= work[i][1]) {
        in_value = true;
      }
    }

    if (in_value) {
      cnt++;
    }
    else {
      cnt = 0;
    }

    if (m_cnt < cnt) m_cnt = cnt;
    j++;
  }

  printf("%d\n", m_cnt);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   work[INPUT_ROW][NUM_COUNT] = {{ 0 }};
  int32_t   num = 0;
  char     *tmp = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  num = strtol(str, NULL, 10);

  for (i = 0; i < num; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", work[i]);
  }

  main_logic(num, work);

  return 0;
}