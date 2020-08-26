// 打开命令行参数的文件 -- 并统计字符在文件中出现的次数
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char *argv[])
{
    FILE *fp;
    int ct = 0;
    char ch;

    // 检查命令行参数个数
    if (argc < 2) {
        fprintf(stderr, "参数个数错误!");
        exit(EXIT_FAILURE);
    }
    if (strlen(argv[1]) != 1) {
        fprintf(stderr, "第二个参数必须是一个字符!");
        exit(EXIT_FAILURE);
    }

    // 当用户没输入文件名时 -- 从标准输入中读入
    if (argc == 2) {
        printf("请输入字符串: ");
        while ((ch = getchar()) != EOF)
            if (ch == argv[1][0])
                ct++;
        printf("你输入的字符串中 %c 出现的次数为 %d \n", argv[1][0], ct);
    }
    // 当用户输入了文件名时
    else {
        for (int i = 2; i < argc; i++) {
            if ((fp = fopen(argv[i], "r")) == NULL) {
                printf("打开文件: %s 失败\n", argv[i]);
                printf("打开下一个文件...\n");
                continue;
            }
            ct = 0;
            while ((ch = getc(fp)) != EOF) {
                if (ch == argv[1][0])
                    ct++;
            }
            printf("字符 %c 在文件 %s 中出现了 %d 次\n", argv[1][0], argv[i], ct);
            fclose(fp);
        }
    }

    return 0;
}