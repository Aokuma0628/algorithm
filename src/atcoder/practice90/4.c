#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 2000,
  NUM_COUNT = 2000,
  MAX_LEN = 8000,
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


static void main_logic(
  int hight,
  int width,
  int num[][NUM_COUNT]
)
{
  int i,j,k;
  int h_sum[NUM_COUNT] = { 0 };

  for (i = 0; i < hight; i++) {
    int w_sum = 0;
    for (j = 0; j < width; j++) {
      int sum = 0;

      if (h_sum[j] == 0) {
        for (k = 0; k < hight; k++) {
          h_sum[j] += num[k][j];
        }
      }

      if (w_sum == 0) {
        for (k = 0; k < width; k++) {
          w_sum += num[i][k];
        }
      }
  
      sum += h_sum[j];
      sum += w_sum;
      sum -= num[i][j];
      printf("%d", sum);

      if (j < width - 1) {
        printf(" ");
      }
    }
    printf("\n");
  }

  return;
}


int main(void)
{
  char  str[MAX_LEN] = { 0 };
  int   num[INPUT_ROW_COUNT][NUM_COUNT] = {{ 0 }};
  int   val[2] = { 0 };
  int   hight = 0;
  int   width = 0;
  char *tmp = NULL;
  int   i;

  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, 2, " ", val);
  hight = val[0];
  width = val[1];

  for (i = 0; i < hight; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, width, " ", num[i]);
  }

  main_logic(hight, width, num);

  return 0;
}