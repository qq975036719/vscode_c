// 在文件中保存结构中的内容 -- 增加删除数据功能
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXTITL 40
#define MAXAUTL 40
#define MAXBKS 10

struct book {
    char title[MAXTITL];
    char author[MAXAUTL];
    float value;
    int delete_flag;
};

char *s_gets(char *st, int n);
int main(void)
{
    FILE *pbooks = NULL;
    struct book library[MAXBKS];        // 结构数组
    int count = 0;
    int filecount, index;
    int size = sizeof(struct book);
    char delete;

    // 打开文件
    if ((pbooks = fopen("book.dat", "r+b")) == NULL) {
        fputs("Can't open book.dat file.\n", stderr);
        exit(EXIT_FAILURE);
    }

    rewind(pbooks);     // 定位到文件开始
    while (count < MAXBKS && fread(&library[count], size, 1, pbooks) == 1) {
        if (count == 0) {
            puts("Current contents of book.dat: ");
            printf("%s by %s: $%.2f\n", library[count].title,
                   library[count].author, library[count].value);
        }
        count++;
    }
    filecount = count;      // filecount记录的是原本文件中已有的结构数量

    if (count == MAXBKS) {
        fputs("The book.dat file is full.", stderr);
        exit(EXIT_FAILURE);
    }
    
    // 询问是否需要更改数据
    printf("Do you want to modify library?(y/n):");
    scanf("%c", &delete);
    if (delete == 'y'||delete == 'Y') {
        for (int i = 0; i < count; i++) {
            printf("%s by %s: $%.2f\n", library[i].title, library[i].author, library[i].value);
            while (getchar()!='\n')
                continue;
            puts("Do you want to delete the book?(y/n)");
            scanf("%c", &delete);
            if (delete == 'y' || delete == 'Y')
                library[i].delete_flag = 1;
        }
    }

    while (getchar()!='\n')
        continue;
    puts("Please add new book titles.");
    puts("Press [enter] at the start of a line to stop.");
    while (count < MAXBKS && s_gets(library[count].title, MAXTITL) != NULL &&
               library[count].title[0] != '\0')
    {
        puts("Please enter the author.");
        s_gets(library[count].author, MAXAUTL);

        puts("Please enter the price.");
        scanf("%f", &library[count++].value);
        // 清除输入行
        while (getchar() != '\n')
            continue;
        
        if (count < MAXBKS)
            puts("Enter the next title.");
    }

    rewind(pbooks);
    // 打印图书目录信息
    if (count > 0) {
        // 输出到屏幕
        puts("Here is the list of your books:");
        for (index = 0; index < count; index++) {
            if (library[index].delete_flag != 1) {
                printf("%s by %s: $%.2f\n", library[index].title,
                       library[index].author, library[index].value);
                // 输出到文件
                fwrite(&library[filecount], size, count - filecount, pbooks);
            }
        }
        
    } else
        puts("No books? Too bad.\n");

    puts("Bye!\n");
    fclose(pbooks);

    return 0;
}

char *s_gets(char *st, int n)
{
    char *ret_val = NULL;
    char *find;

    ret_val = fgets(st, n, stdin);
    if (ret_val) {
        find = strchr(st, '\n');
        if (find)
            *find = '\0';
        else
            while (getchar() != '\n')
                continue;
    }

    return ret_val;
}