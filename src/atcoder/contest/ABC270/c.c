#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  BASE_COUNT = 3,
  NUM_COUNT = 2,
  INPUT_ROW = 200000,
  MAX_LEN = 32,
};


typedef struct _t_tree {
  int32_t no;
  int32_t cnt;
  int32_t *near;
} T_TREE;

typedef struct _t_ans {
  int32_t ans[INPUT_ROW];
  int32_t cnt;
} T_ANS;

bool g_already_search[INPUT_ROW] = { 0 };
T_ANS g_ans = { 0 };

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

static int32_t input_near_number(
  T_TREE *tree,
  int32_t near
)
{
  if (!tree) return NG;

  tree->cnt++;
  tree->near = (int32_t*)realloc(tree->near, sizeof(int32_t) * tree->cnt);
  if (!tree->near) return NG;

  tree->near[tree->cnt - 1] = near;

  return OK;
}

static bool re_ans(
  T_TREE *tree,
  int32_t target
)
{
  if (!tree) return false;

  if (tree->no == target) return true;

  if (tree->near) {

  }
  else {
    return false;
  }




}

static void search_answer(
  T_TREE *trees,
  int32_t n,
  int32_t x,
  int32_t y
)
{
  int32_t i;

  if (!trees) return;

  re_ans(&trees[x - 1], y);

  for (i = 0; i < g_ans.cnt; i++) {
    if (i != 0) printf(" ");
    printf("%d", g_ans.ans[g_ans.cnt - 1 - i]);
  }
  printf("\n");

  return;
}


static void main_logic(
  int32_t n,
  int32_t x,
  int32_t y,
  int32_t num[][NUM_COUNT]
)
{
  T_TREE trees[INPUT_ROW] = { 0 };
  int32_t i;

  for (i = 0; i < n; i++) {
    int32_t no = 0;
    int32_t near = 0;

    trees[i].no = i + 1;

    no = num[i][0];
    near = num[i][1];
    if (input_near_number(&trees[no - 1], near) == NG) {
      printf("memory error\n");
      return;
    };

    no = num[i][1];
    near = num[i][0];
    if (input_near_number(&trees[no - 1], near) == NG) {
      printf("memory error\n");
      return;
    };
  }

  search_answer(trees, n, x, y);

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   base[BASE_COUNT] = { 0 };
  int32_t   num[INPUT_ROW][NUM_COUNT] = {{ 0 }};
  int32_t   n = 0;
  int32_t   x = 0;
  int32_t   y = 0;
  char     *tmp = NULL;
  int32_t   i;
  
  tmp = fgets(str, MAX_LEN, stdin);
  split_str2int(str, BASE_COUNT, " ", base);

  n = num[0];
  x = num[1];
  y = num[2];

  for (i = 0; i < n; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", num[i]);
  }

  main_logic(n, x, y, num);

  return 0;
}