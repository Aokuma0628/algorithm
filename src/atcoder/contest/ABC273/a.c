#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  MAX_LEN = 4,
};


static void main_logic(
  int32_t n
)
{
  int32_t i;
  int32_t f0 = 1;
  int32_t fn = f0;

  for (i = 1; i <= n; i++) {
    fn = i * fn;
  }

  printf("%d\n", fn);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN]   = { 0 };
  char     *tmp       = NULL;
  int32_t   n = 0;

  tmp = fgets(str, MAX_LEN, stdin);
  n = strtol(str, NULL, 10);

  main_logic(n);

  return 0;
}