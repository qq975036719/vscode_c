// 使用strncmp()函数
#include <stdio.h>
#include <String.h>
#define LISTSIZE 6

int main(void)
{
    const char *list[LISTSIZE] = {
        "astronomy", "astounding",
        "astrophysics", "ostracize",
        "asterism", "astrophobia"
    };
    int count = 0;
    int i;
    for (i = 0; i < LISTSIZE; i++)
        if (strncmp(list[i], "astro", 5) == 0) {
            printf("Found: %s\n", list[i]);
            count++;
        }
    printf("列表中的单词有%d个是以astro开头", count);

    return 0;
}