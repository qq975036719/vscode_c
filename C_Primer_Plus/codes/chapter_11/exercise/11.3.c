// 读取一个单词到数组中
#include <stdio.h>
#include <ctype.h>
#define SIZE 80

char *get_word(char * output);
int main(int argc, char *argv[])
{
    char words[SIZE];
    get_word(words);
    puts("你输入的第一个单词是: ");
    puts(words);

    return 0;
}

char *get_word(char * output)
{
    char input[SIZE];
    char *in;
    puts("请输入一句话: ");
    fgets(input, SIZE, stdin);
    in = input;

    // 检测输入的字符串前面是否为空白字符
    while (isspace(*in))
        in++;
    // 将连续的字母读入到output数组中
    while (isalpha(*in))
        *output++ = *in++;
    *output = '\0';

    return output;
}