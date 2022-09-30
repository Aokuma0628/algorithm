#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  MAX_LEN = 8,
  FALSE = 0,
  TRUE = 1,
};


static void main_logic(
  int num
)
{
  int bit,i;

  for (bit = 0; bit < (1 << num); bit++) {
    int cnt0 = 0;
    int cnt1 = 0;

    for (i = 0; i < num; i++) {
      (bit & (1 << (num - i - 1))) ? cnt1++ : cnt0++;
      if ((cnt0 - cnt1) < 0) break;
    }

    if (cnt0 != cnt1) continue;

    for (i = 0; i < num; i++) {
      printf("%s", (bit & (1 << (num - i - 1))) ? ")" : "(");
    }
    printf("\n");
  }

  return;
}


int main(void)
{
  char  str[MAX_LEN] = { 0 };
  int   num = 0;
  char *tmp = NULL;

  tmp = fgets(str, MAX_LEN, stdin);
  num = strtol(str, NULL, 10);

  main_logic(num);

  return 0;
}