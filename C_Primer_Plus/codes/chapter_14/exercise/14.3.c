// 输出图书目录信息 -- 先按输入顺序输出 -- 再按书名字母顺序输出 -- 再按价格升序输出
// 包含多本书的图书目录
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAXTILT 40
#define MAXAULT 30
#define MAXBKS 100

struct book {
    char title[MAXTILT];
    char author[MAXAULT];
    float value;
};

char *s_gets(char *st, int n);
void order_by_input(struct book library[], int count);   // 按输入顺序打印结果
void order_by_name(struct book library[], int count);    // 按书本字母顺序打印
void order_by_price(struct book library[], int count);   // 按价格升序打印

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
        order_by_input(library, count);     // 按输入顺序打印
        order_by_name(library, count);      // 按书名字母顺序打印
        order_by_price(library, count);     // 按价格升序打印
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

void order_by_input(struct book library[], int count)
{
    printf("图书中的书本信息如下(按输入顺序): \n\n");
    for (int i = 0; i < count; i++) {
        printf("书名: %s\n", library[i].title);
        printf("作者: %s\n", library[i].author);
        printf("价格: $%.2f\n", library[i].value);
        putchar('\n');
    }
}

void order_by_name(struct book library[], int count)
{
    char *temp = NULL;
    int top, seek;

    // 创建动态二维字符数组
    char (**ptitle) = (char **)malloc(sizeof(char *) * count);
    for (int i = 0; i < count; i++)
        ptitle[i] = (char *)malloc(sizeof(char) * MAXTILT);

    // 为了不改变library中的顺序 -- 将title存储到一个新的数组中
    for (int i = 0; i < count; i++)
        ptitle[i] = library[i].title;
    
    // 对新数组进行排序
    for (top = 0; top < count - 1; top++)
        for (seek = top + 1; seek < count; seek++)
            if (strcmp(ptitle[top], ptitle[seek]) > 0) {
                temp = ptitle[top];
                ptitle[top] = ptitle[seek];
                ptitle[seek] = temp;
            }
    
    // 对比新数组与library的title进行输入
    printf("图书中的书本信息如下(按字母顺序): \n\n");
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (strcmp(ptitle[i], library[j].title) == 0) {
                printf("书名: %s\n", library[j].title);
                printf("作者: %s\n", library[j].author);
                printf("价格: $%.2f\n", library[j].value);
                putchar('\n');
            }
}

void order_by_price(struct book library[], int count)
{
    float *pvalue = (float *)malloc(sizeof(float) * count);
    int top, seek;
    int temp;

    for (int i = 0; i < count; i++)
        pvalue[i] = library[i].value;

    for (top = 0; top < count - 1; top++)
        for (seek = top + 1; seek < count; seek++)
            if (pvalue[top] > library[seek].value) {
                temp = pvalue[top];
                pvalue[top] = library[seek].value;
                library[seek].value = temp;
            }

    printf("图书中的书本信息如下(按价格顺序): \n\n");
    for (int i = 0; i < count; i++)
        for (int j = 0; j < count; j++)
            if (pvalue[i] == library[j].value) {
                printf("书名: %s\n", library[j].title);
                printf("作者: %s\n", library[j].author);
                printf("价格: $%.2f\n", library[j].value);
                putchar('\n');
            }
}