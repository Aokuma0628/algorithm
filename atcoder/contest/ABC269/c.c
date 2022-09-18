#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  MAX_CNT = 65536,
  MAX_LEN = 32,
  FALSE = 0,
  TRUE = 1,
};

static void main_logic(
  long long int val
)
{
  int i, j;
  long long int ans[MAX_CNT] = { 0 };
  int cnt = 1;

  for (i = 0; i < 60; i++) {
    long long int x = 1LL << i;
    if (val < x) break;

    if (val & x) {
      int size = cnt;
      for (j = 0; j < size; j++) {
        ans[cnt++] = ans[j] | x;
      }
    }
  }

  for (i = 0; i < cnt; i++) {
    printf("%lld\n", ans[i]);
  }

  return;
}


int main(void)
{
  char  str[MAX_LEN] = { 0 };
  char *tmp = NULL;
  long long int val = 0;

  tmp = fgets(str, MAX_LEN, stdin);
  val = strtoll(str, NULL, 10);

  main_logic(val);

  return 0;
}