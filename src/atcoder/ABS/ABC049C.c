#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 1,
  NUM_COUNT = 0,
  MAX_LEN = 100001,
};


static int reverse(
  char *str
)
{
  int len = strlen(str);
  char tmp;
  int i;

  for (i = 0; i < len / 2; i++) {
    tmp = str[i];
    str[i] = str[len - i - 1];
    str[len - i - 1] = tmp;
  }

  return OK;
}


static int main_logic(
  char *str
)
{
  int i;
  int s_len = strlen(str);
  int t_len = 0;
  int len = s_len;
  char text[4][8] = { 
    "dream",
    "dreamer",
    "erase",
    "eraser"
  };

  for (i = 0; i < 4; i++) {
    reverse(text[i]);
  }
  
  reverse(str);

  while(len > 0) {
    for (i = 0; i < 4; i++) {
      t_len = strlen(text[i]);
      if (strncmp(text[i], &str[s_len - len], t_len) == 0) {
        len -= t_len;
        break;
      }
    }

    if (i >= 4) {
      printf("NO");
      return OK;
    }
  }

  printf("YES");

  return OK;
}


int main(void)
{
  int   i;
  char  str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  char *tmp = NULL;
  int   len = 0;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

  len = strlen(str[0]);
  str[0][len - 1] = '\0';

  main_logic(str[0]);

  return 0;
}