#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
    FILE *fp = NULL;
    double num;
    double sum = 0;
    int count = 0;

    if (argc == 1)
        fp = stdin;
    else if (argc == 2) {
        if ((fp = fopen(argv[1], "r")) == NULL) {
            fprintf(stderr, "打开文件%s失败!", argv[1]);
            exit(EXIT_FAILURE);
        }
    }
    else {
        fprintf(stderr, "使用的文件为: %s", argv[0]);
        exit(EXIT_FAILURE);
    }
    
    while (fscanf(fp, "%lf", &num) == 1) {
        sum += num;
        count++;
    }
    if (count > 0)
        printf("算术平均值为: %g", sum / count);
    else
        fprintf(stderr, "你未输入任何数字!\n");

    return 0;
}