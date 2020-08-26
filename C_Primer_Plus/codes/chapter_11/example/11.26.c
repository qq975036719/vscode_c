// 展现strcpy()的特性 -- 返回值和第1个参数
#include <stdio.h>
#include <string.h>

#define WORDS "beast"
#define SIZE 40

int main(void)
{
    const char *orig = WORDS;
    char copy[SIZE] = "Be the best that you can be.";
    char *ps;

    puts(orig);
    puts(copy);
    ps = strncpy(copy + 7, orig, 6);
    puts(copy);
    puts(ps);

    return 0;
}