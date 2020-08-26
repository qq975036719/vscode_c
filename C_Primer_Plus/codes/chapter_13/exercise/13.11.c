// 在文件中查找字符串 -- 包含该字符串的行打印出来 -- 用命令行参数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 256

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    char buff[BUFFER_SIZE];

    // 检查参数
    if (argc != 3) {
        printf("参数个数错误!");
        exit(EXIT_FAILURE);
    }

    // 打开文件
    if ((fp = fopen(argv[2], "r")) == NULL) {
        printf("打开文件%s失败", argv[2]);
        exit(EXIT_FAILURE);
    }

    // 读取文件到缓冲区 -- 并查找打印字符串
    while (fgets(buff, BUFFER_SIZE, fp) != NULL) {
        if (strstr(buff, argv[1]))
            printf("%s", buff);
    }

    return 0;
}