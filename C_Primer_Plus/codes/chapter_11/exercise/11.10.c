// del_space() -- 删除字符串中的空格
#include <stdio.h>
#define SIZE 81

void del_space(char *st);
int main(void)
{
    char words[SIZE];
    printf("请输入一个字符串: ");
    fgets(words, SIZE, stdin);

    while (*words != '\n') {
        del_space(words);
        printf("删除空格后的字符串为: ");
        puts(words);

        printf("请输入一个字符串: ");
        fgets(words, SIZE, stdin);
    }

    return 0;
}

void del_space(char *st)
{
    char *new_st;

    while (*st) {
        if (*st == ' ') {
            new_st = st;
            
            do {
                *new_st = *(new_st + 1);
                new_st++;
            } while (*new_st);
        }
        else
            st++;
    }
}