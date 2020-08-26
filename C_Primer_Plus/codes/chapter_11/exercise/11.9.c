// 将字符串的内容反序
#include <stdio.h>
#include <string.h>
#define SIZE 81

void reverse_str(char *st);
int main(int argc, char*argv[])
{
    char words[SIZE];
    printf("请输入一个字符串: ");
    fgets(words, SIZE, stdin);
    
    while (*words != '\n') {
        reverse_str(words);
        printf("反序后的结果为: ");
        puts(words);

        printf("请输入一个字符串: ");
        fgets(words, SIZE, stdin);
    }
    return 0;
}

void reverse_str(char *st)
{
    int st_len = strlen(st);
    char temp;
    
    for (int i = 0; i < st_len / 2; i++) {     // 调换顺序
        temp = st[i];
        st[i] = st[st_len - 1 - i];
        st[st_len - 1 - i] = temp;
    }
}