#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  NUM_COUNT = 3,
  MAX_LEN = 32,
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


static void main_logic(
  int32_t x,
  int32_t y,
  int32_t z
)
{
  int32_t dis = -1;

  if (x > 0) {
    if (y > 0) {
      if (y < x && y < z) {
        // nothing
      }
      else if (x < y){
        dis = x;
      }
      else if(z < 0) {
        dis = (abs(z) * 2) + x;
      }
      else {
        dis = x;
      }
    }
    else {
      dis = x;
    }
  }
  else {
    if (y > 0) {
      dis = abs(x);
    }
    else {
      if (z > 0) {
        if (x < y) {
          dis = abs(x) + (z * 2);
        }
        else {
          dis = abs(x);
        }
      }
      else {
        if (x < y && z < y) {
          // nothing
        }
        else {
          dis = abs(x);
        }
      }
    }
  }

  printf("%d\n", dis);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   num[NUM_COUNT] = { 0 };
  char     *tmp       = NULL;
  
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, NUM_COUNT, " ", num);

  main_logic(num[0], num[1], num[2]);

  return 0;
}