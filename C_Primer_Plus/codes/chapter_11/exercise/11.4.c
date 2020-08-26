// 读取一个单词到数组中 -- 指明可读取的最大字符数
#include <stdio.h>
#include <ctype.h>
#define SIZE 80

char *get_word(char * output, int n);
int main(int argc, char *argv[])
{
    char words[SIZE];
    int n;
    puts("请输入你想读取的字符数: ");
    scanf("%d", &n);
    while (getchar() != '\n')
        continue;

    get_word(words, n);
    puts("你输入的第一个单词是: ");
    puts(words);

    return 0;
}

char *get_word(char * output, int n)
{
    char input[SIZE];
    char *in;
    int count = 0;
    puts("请输入一句话: ");
    fgets(input, SIZE, stdin);
    in = input;
    

    // 检测输入的字符串前面是否为空白字符
    while (isspace(*in) && count < n) {
        in++;
        count++;
    }
    // 将连续的字母读入到output数组中
    while (isalpha(*in) && count < n) {
        *output++ = *in++;
        count++;
    }
    *output = '\0';

    return output;
}