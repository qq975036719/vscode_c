// 读取字符串并显示读入的单词数、大写字母数、小写字母数、标点符号数和数字字符数
#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>

#define SIZE 81

int cal_words(char *st);
int cal_upper(char *st);
int cal_lower(char *st);
int cal_punct(char *st);
int cal_number(char *st);

int main(void)
{
    char input[SIZE];

    puts("请输入字符串: ");
    fgets(input, SIZE, stdin);

    printf("单词数: %d\n", cal_words(input));
    printf("大写字母数: %d\n", cal_upper(input));
    printf("小写字母数: %d\n", cal_lower(input));
    printf("标点符号数: %d\n", cal_punct(input));
    printf("数字符号数: %d\n", cal_number(input));

    return 0;
}

int cal_words(char *st)
{   // 统计单词数
    int words_num = 0;
    bool inword = false;
    // 过滤掉前面的空白输入，让计数从字母开始
    while (isspace(*st))
        st++;
    while (*st) {
        if (isalpha(*st) && !inword) {
            inword = true;
            words_num++;
        }
        if (isspace(*st))
            inword = false;
        st++;
    }

    return words_num;
}

int cal_upper(char *st)
{   // 统计大写字母数
    int uppers_num = 0;
    // 过滤掉前面的空白输入，让计数从字母开始
    while (isspace(*st))
        st++;
    while (*st) {
        if (isupper(*st++))
            uppers_num++;
    }

    return uppers_num;
}

int cal_lower(char *st)
{   // 统计小写字母数
    int lowers_num = 0;
    // 过滤掉前面的空白输入，让计数从字母开始
    while (isspace(*st))
        st++;
    while (*st) {
        if (islower(*st++))
            lowers_num++;
    }

    return lowers_num;
}

int cal_punct(char *st)
{   // 统计标点符号数
    int puncts_num = 0;
    // 过滤掉前面的空白输入，让计数从字母开始
    while (isspace(*st))
        st++;
    while (*st) {
        if (ispunct(*st++))
            puncts_num++;
    }

    return puncts_num;
}

int cal_number(char *st)
{   // 统计数字符号数
    int numbers_num = 0;
    // 过滤掉前面的空白输入，让计数从字母开始
    while (isspace(*st))
        st++;
    while (*st) {
        if (isdigit(*st++))
            numbers_num++;
    }

    return numbers_num;
}