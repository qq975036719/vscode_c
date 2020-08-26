#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define LIMIT 81

void ToUpper(char*);
int PunctCount(const char*);

int main(void)
{
	char line[LIMIT];
	char* find;

	puts("请输入一段话: ");
	fgets(line, LIMIT, stdin);      // fgets()会保留输入的换行符,find用于把换行符去除
	find = strchr(line, '\n');
	if (find) 
		*find = '\0';
	ToUpper(line);
	puts(line);
	printf("这句话中有%d个标点符号", PunctCount(line));

	return 0;
}

void ToUpper(char* string)
{
	while (*string) {
		*string = toupper(*string);
		string++;
	}
}

int PunctCount(const char* string)
{
	int ct = 0;
	while (*string) {
		if (ispunct(*string))
			ct++;
		string++;
	}

	return ct;
}