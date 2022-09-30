#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 1000,
  MAX_LEN = 8,
};


static void main_logic(
  int32_t num,
  int32_t cars[]
)
{
  int32_t count = -1;
  int32_t f_val = 1;
  int32_t i;
  
  while (f_val <= num) {
    for (i = 0; i < num; i++) {
      if (cars[i] == f_val) {
        f_val++;
      }
    }
    count++;
  }

  printf("%d\n", count);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   cars[NUM_COUNT] = { 0 };
  int32_t   num = 0;
  char     *tmp = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  num = strtol(str, NULL, 10);

  for (i = 0; i < num; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    cars[i] = strtol(str, NULL, 10);
  }

  main_logic(num, cars);

  return 0;
}