#include <stdio.h>
#include <stdlib.h>
#include <string.h>

enum {
  INPUT_ROW_COUNT = 4,
  MAX_LEN = 6,
};

int main(void)
{
  int i, j, k;
  char str[INPUT_ROW_COUNT][MAX_LEN] = { { 0 } };
  char *tmp = NULL;
	int num_500 = 0;
	int num_100 = 0;
	int num_50 = 0;
	int sum = 0;
	int count = 0;

  for (i = 0; i < INPUT_ROW_COUNT; i++) {
    tmp = fgets(str[i], MAX_LEN, stdin);
    (void)tmp;
  }

	num_500 = strtol(str[0], NULL, 10);
	num_100 = strtol(str[1], NULL, 10);
	num_50 = strtol(str[2], NULL, 10);
	sum = strtol(str[3], NULL, 10);

	for (i = 0; i <= num_500; i++) {
		if (500 * i > sum) {
			break;
		}
		for (j = 0; j <= num_100; j++) {
			if (500 * i + 100 * j > sum) {
				break;
			}
			for (k = 0; k <= num_50; k++) {
				if (500 * i + 100 * j + 50 * k > sum) {
					break;
				}
				if (500 * i + 100 * j + 50 * k == sum) {
					count++;
				}
			}
		}
	}

	printf("%d", count);

  return 0;
}