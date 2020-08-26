// 通过命令行参数来执行不同的字符串命令
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int argc, char *argv[])
{
    char *pt1;
    pt1 = argv[2];

    if (strcmp(argv[1], "-p") == 0)
        puts(pt1);
    // -u 指令 -- 变大写
    else if (strcmp(argv[1], "-u") == 0) {
        while (*pt1) {
            if (islower(*pt1))
                *pt1 = toupper(*pt1);
            pt1++;
        }
        puts(pt1);
    }
    // -l 指令 -- 变小写
    else if (strcmp(argv[1], "-l") == 0) {
        while (*pt1) {
            if (isupper(*pt1))
                *pt1 = tolower(*pt1);
            pt1++;
        }
        puts(pt1);
    }
    if (argc == 2)
        puts(pt1);

    return 0;
}