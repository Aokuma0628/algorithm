#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

enum {
  OK = 1,
  NG = 0,
  INPUT_ROW_COUNT = 100000,
  NUM_COUNT = 2,
  MAX_LEN = 16,
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
  int32_t people,
  int32_t score[][NUM_COUNT],
  int32_t ques
)
{
  char    str[MAX_LEN]     = { 0 };
  int32_t range[NUM_COUNT] = { 0 };
  int32_t score_sum[NUM_COUNT][INPUT_ROW_COUNT] = {{ 0 }};
  int32_t tmp_score1 = 0;
  int32_t tmp_score2 = 0;
  int32_t i;
  char   *tmp;

  for (i = 0; i < people; i++) {
    int32_t score1 = tmp_score1;
    int32_t score2 = tmp_score2;
    if (score[i][0] == 1) {
      score1 += score[i][1];
    }
    else {
      score2 += score[i][1];
    }

    score_sum[0][i] = score1;
    score_sum[1][i] = score2;
    tmp_score1 = score1;
    tmp_score2 = score2;
  }

  for (i = 0; i < ques; i++) {
    int32_t low  = 0;
    int32_t high = 0;
    int32_t sum1 = 0;
    int32_t sum2 = 0;
    int32_t j;

    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", range);

    low = range[0] - 1;
    high = range[1] - 1;

    if (low == 0) {
      sum1 = score_sum[0][high] - 0;
      sum2 = score_sum[1][high] - 0;
    }
    else {
      sum1 = score_sum[0][high] - score_sum[0][low - 1];
      sum2 = score_sum[1][high] - score_sum[1][low - 1];
    }

    printf("%d %d\n", sum1, sum2);
  }

  return;
}


int32_t main(void)
{
  char      str[MAX_LEN] = { 0 };
  int32_t   score[INPUT_ROW_COUNT][NUM_COUNT] = {{ 0 }};
  int32_t   people    = 0;
  int32_t   ques      = 0;
  char     *tmp       = NULL;
  int32_t   i;

  tmp = fgets(str, MAX_LEN, stdin);
  people = strtol(str, NULL, 10);
  
  for (i = 0; i < people; i++) {
    memset(str, 0, MAX_LEN);
    tmp = fgets(str, MAX_LEN, stdin);
    split_str2int(str, NUM_COUNT, " ", score[i]);
  }

  memset(str, 0, MAX_LEN);
  tmp = fgets(str, MAX_LEN, stdin);
  ques = strtol(str, NULL, 10);

  main_logic(people, score, ques);

  return 0;
}