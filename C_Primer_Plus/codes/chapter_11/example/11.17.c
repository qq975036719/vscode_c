// 使用缩短字符串长度的函数
#include <stdio.h>
#include <string.h>

void fit(char *, unsigned int);
int main(void)
{
    char test_str[] = "Things should be as simple as possible, "
                      "but not simpler.";
    puts(test_str);
    fit(test_str, 38);
    puts(test_str);
    puts(test_str + 39);

    return 0;
}

void fit(char * string, unsigned int size)
{
    if (strlen(string) > size)
        string[size] = '\0';
}