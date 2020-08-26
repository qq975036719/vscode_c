// 反序显示命令行参数的单词
#include <stdio.h>

int main(int argc, char *argv[])
{
    for (int i = 0; i < argc; i++)
    {
        printf("%s ", argv[argc - i]);
    }
}