// 创建图书目录
#include <stdio.h>
#include <string.h>
#define MAXTITL 41
#define MAXAUTL 31

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
};

char * s_gets(char *, int n);

int main(void)
{
    struct book library;       // 声明一个book结构变量

    // 读取信息
    printf("请输入书名: ");
    s_gets(library.title, MAXTITL);

    printf("请输入作者名: ");
    s_gets(library.author, MAXAUTL);

    printf("请输入价格: ");
    scanf("%f", &library.value);

    // 打印结果
    printf("%s by %s: $%.2f\n",
           library.title, library.author, library.value);
    printf("Done!");

    return 0;
}

char * s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);

    if (ret_val) {
        find = strchr(ret_val, '\n');
        if (find)
            *find = '\0';
        else {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}