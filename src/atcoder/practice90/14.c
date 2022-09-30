#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 100000,
  INPUT_ROW_COUNT = 2,
  MAX_LEN = 2000000,
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
    return 1;
  }
  else {
    return -1;
  }
}


static void main_logic(
  int32_t people,
  int32_t home[],
  int32_t school[]
)
{
  long long int sum = 0LL; 
  int32_t i;
  
  if (!home || !school) return ;

  qsort(home, people, sizeof(int32_t), sort_func);
  qsort(school, people, sizeof(int32_t), sort_func);

  for (i = 0; i < people; i++) {
    sum += abs(home[i] - school[i]);
  }

  printf("%lld\n", sum);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   home[NUM_COUNT] = { 0 };
  int32_t   school[NUM_COUNT] = { 0 };
  int32_t   people    = 0;
  char     *tmp       = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  people = strtol(str, NULL, 10);
  
  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, people, " ", home);

  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, people, " ", school);

  main_logic(people, home, school);

  return 0;
}