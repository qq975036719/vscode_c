// 包含多本书的图书目录
#include <stdio.h>
#include <string.h>

#define MAXTILT 40
#define MAXAULT 30
#define MAXBKS 100

struct book {
    char title[MAXTILT];
    char author[MAXAULT];
    float value;
};

char *s_gets(char *st, int n);
int main(void)
{
    struct book library[MAXBKS];    // 创建了100个book结构的变量 -- 相当于100本书
    int count = 0;
    
    printf("请输入书名(直接空出一行输入回车退出): ");
    /* 条件：
            直到读取到书名的'\0'
            计数器count应小于书本的数量100
            读取的书名有效 -- 返回的指针不是NULL 
    */
    while (s_gets(library[count].title, MAXTILT) != NULL &&
               library[count].title[0] != '\0' &&
               count < MAXBKS)
    {
        printf("请输入作者名: ");
        s_gets(library[count].author, MAXAULT);

        printf("请输入价格: ");
        scanf("%f", &library[count++].value);

        // 清理输入行
        while (getchar() != '\n')
            continue;

        if (count < MAXBKS) {
            printf("请输入下一本书的信息\n");
            printf("请输入书名(直接空出一行输入回车退出): ");
        }
    }

    if (count > 0) {
        // 打印图书目录
        printf("图书中的书本信息如下: \n\n");
        for (int i = 0; i < count; i++) {
            printf("书名: %s\n", library[i].title);
            printf("作者: %s\n", library[i].author);
            printf("价格: $%.2f\n", library[i].value);
            putchar('\n');
        }
    }else
        printf("目录中没有书!\n");

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val;
    char *find;

    ret_val = fgets(st, n, stdin);
    
    if (ret_val) {
        find = strchr(st, '\n');

        if (find)
            *find = '\0';

        else {
            while (getchar() != '\n')
                continue;
        }
    }

    return ret_val;
}