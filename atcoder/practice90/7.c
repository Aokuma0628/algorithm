#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 300000,
  NUM_COUNT = 300000,
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

static int32_t sort_class(
  const void *a,
  const void *b
)
{
  int32_t val_a = *(int32_t *)a;
  int32_t val_b = *(int32_t *)b;
  
  if (val_a > val_b) {
    return 1;
  }
  else {
    return -1;
  }
}

static bool solve_min_diff(
  int32_t class[],
  int32_t idx,
  int32_t rate
)
{
  if (!class) return false;

  if (idx == 0) return false;

  if (class[idx] > rate) {
    return true;
  }
  else {
    return false;
  }
}


static void main_logic(
  int32_t class_num,
  int32_t class[],
  int32_t people
)
{
  char    str[16] = { 0 };
  char    *tmp;
  int32_t i;

  qsort(class, class_num, sizeof(int32_t), sort_class);

  for (i = 0; i < people; i++) {
    int32_t h_idx = class_num - 1;
    int32_t l_idx = 0;
    int32_t m_idx = 0;
    int32_t idx   = 0;
    int32_t rate  = 0;

    memset(str, 0, 16);
    tmp = fgets(str, 16, stdin);
    rate = strtol(str, NULL, 10);

    while (abs(h_idx - l_idx) > 1) {
      m_idx = (h_idx + l_idx) / 2;

      if (solve_min_diff(class, m_idx, rate)) {
        h_idx = m_idx;
      }
      else {
        l_idx = m_idx;
      }
    }

    idx = abs(class[h_idx] - rate) > abs(class[l_idx] - rate) ? l_idx : h_idx;

    printf("%d\n", abs(rate - class[idx]));
  }

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN]          = { 0 };
  int32_t   class[NUM_COUNT]      = { 0 };
  int32_t   class_num = 0;
  int32_t   people    = 0;
  char     *tmp       = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  class_num = strtol(str, NULL, 10);
  
  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, class_num, " ", class);

  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  people = strtol(str, NULL, 10);

  main_logic(class_num, class, people);

  return 0;
}