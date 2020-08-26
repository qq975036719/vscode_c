// 字符串修饰符展示
#include <stdio.h>
#include <string.h>
#define BLURB "Authentic imitation"

int main(void)
{
    printf("BLURB的字段宽度为: %d\n", strlen(BLURB));
    printf("[%2s]\n", BLURB);
    printf("[%24s]\n", BLURB);
    printf("[%24.5s]\n", BLURB);
    printf("[%-24.5s]\n", BLURB);

    getchar();
    return 0;
}