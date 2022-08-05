#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ERROR (1)

#define LINE_MAX_NUM (1000)
#define STR_MAX_LINE (20)
#define STR_MAX_LEN (100)

// N K
// x_1
// x_2
// ...
// x_N

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

static char **get_stdin_all_line(char *buf[], int num, int max) {
	int i1;

	if (!buf)
		return NULL;

	if (num < 0 || max < 0)
		return NULL;

	for (i1 = 0; i1 < num; i1++) {
		fgets(buf[i1], max, stdin);
		lntrim(buf[i1]);
	}

	return buf;
}

static char *get_stdin_one_line(char *buf, int max) {

	if (!buf)
		return NULL;

	if (max < 0)
		return NULL;

	fgets(buf, max, stdin);
	lntrim(buf);

	return buf;
}

int main(void) {
	char init_line[STR_MAX_LINE] = {0};
	char buf[LINE_MAX_NUM][STR_MAX_LINE] = {{0}};
	int num = 0;
	float exp = 0.0;
	char *p;
	char *endptr;

	if (get_stdin_one_line(init_line, STR_MAX_LINE) == NULL)
		return ERROR;

	p = strchr(init_line, ' ');
	if (!p)
		return ERROR;

	*p = '\0';
	p++;

	num = strtol(init_line, &endptr, 10);
	if (*endptr != '\0')
		return ERROR;

	exp = strtof(p, &endptr);
	if (*endptr != '\0')
		return ERROR;

	if (get_stdin_all_line((char **)buf, LINE_MAX_NUM, STR_MAX_LINE) == NULL)
		return 0;

	return 0;
}