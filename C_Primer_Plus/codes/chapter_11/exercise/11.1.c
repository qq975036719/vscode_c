// 将n个字符存储到一个数组里
#include <stdio.h>
#define SIZE 100

char * get_str(char * st, int n);
int main(int argc, char * argv[])
{
    char words[SIZE];
    puts("请输入一段话: ");
    get_str(words, SIZE);
    puts("你输入的内容如下: \n");
    puts(words);

    return 0;
}

char * get_str(char * st, int n)
{
    int i = 0;
    do {
        st[i] = getchar();
    } while (st[i] != EOF && ++i < n);

    return st;
}