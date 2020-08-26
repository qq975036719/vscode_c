// 计算平均每个单词的字母数
#include <stdio.h>
#include <ctype.h>

int main(void)
{
    int words = 0;
    int char_num = 0;
    char ch;
    char prev = 0;
    while ((ch = getchar()) != EOF) {
        if (isspace(ch)) {
            if (isalpha(prev)) {
                words++;
                continue;
            }
        }
        else if (isalpha(ch)) {
            char_num++;
            prev = ch;
        }
    }
    printf("一共有%d个单词, 这些单词的字母共%d个, 平均每个单词有%.2f个字母!",
           words, char_num, (float) char_num / words);
    return 0;
}