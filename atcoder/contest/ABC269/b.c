#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 10,
  MAX_LEN = 16,
  FALSE = 0,
  TRUE = 1,
};


static void main_logic(
  char str[][MAX_LEN]
)
{
  int i,j;
  int a = -1;
  int b = -1;
  int c = -1;
  int d = -1;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    for (j = 0; j < 10; j++) {
      if (str[i][j] == '#') {
        if (a == -1) {
          a = i;
        }
        if (c == -1) {
          c = j;
        }
        if (b < i) {
          b = i;
        }
        if (d < j) {
          d = j;
        }
      }
    }
  }

  printf("%d %d\n", a + 1, b + 1);
  printf("%d %d\n", c + 1, d + 1);

  return;
}


int main(void)
{
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  char *tmp = NULL;
  int   i;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

  main_logic(str);

  return 0;
}