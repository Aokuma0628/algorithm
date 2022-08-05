#include <stdio.h>
#include <string.h>

#define STR_NUM 			(2)
#define STR_MAX_LINE 	(20)
#define STR_MAX_LEN		(100)


static char *lntrim(char *str) {
	char *p;

	if (!str)
		return NULL;

	p = strchr(str, '\n');
	while (p != NULL) {
		*p = '\0';
		p = strchr(str, '\n');
	}

	return str;
}


int main(void) {
  char 	str[STR_MAX_LEN];
  char 	buf[STR_NUM][STR_MAX_LINE];
  int 	i1;

  for (i1 = 0; i1 < STR_NUM; i1++) {
		fgets(buf[i1], STR_MAX_LEN, stdin);
		lntrim(buf[i1]);
	}

	snprintf(str, STR_MAX_LEN, "%s;%s\n", buf[0], buf[1]);
  printf("%s", str);

  return 0;
}