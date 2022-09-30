#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	int i = 0;
	int num = 0;
	char str = '\0';

	for (i = 0; i < 3; i++) {
		str = fgetc(stdin);

		if (str == '1') {
			num++;
		}
	}

	printf("%d", num);

  return 0;
}