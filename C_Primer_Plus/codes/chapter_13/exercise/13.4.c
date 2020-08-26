// 打开命令行参数中的文件并统计数量
#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    int file_ct = 0;
    FILE *fp;

    for (int i = 1; i < argc; i++) {
        fp = fopen(argv[i], "r");
        fprintf(stdout, "正在打开文件%s...\n", argv[i]);
        fclose(fp);
        putchar('\n');
        file_ct++;
    }
    printf("All done, 共打开了%d个文件", file_ct);

    return 0;
}