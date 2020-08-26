// 提供五个选项菜单的字符串处理程序
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define SIZE 81
#define LIM 10

void show_menu();                             // 显示菜单
void show_str(char *st[], int row);           // 打印字符串
void source_str(char *st[], int row);         // 打印源字符串
void sort_ascii(char *st[], int row);         // 按ascii顺序排序
void sort_length(char *st[], int row);        // 按字符串长度递增排序
void sort_first_len(char *st[], int row);     // 按第一个单词的长度排序
int first_word_len(char *st);                 // 获取第一个单词的长度

int main(void)
{
    char choice;            // 用户的选择
    char words[LIM][SIZE];  // 用户输入的字符串
    char *ptstr[LIM];       // 指向用户输入的字符串，方便修改
    int num;                // 统计用户输入的行数

    // 提示用户输入字符串
    puts("请输入最多十个字符串: ");
    // 设置指针指向字符串
    for (num = 0; num < LIM; num++) {
        fgets(words[num], SIZE, stdin);
        ptstr[num] = words[num];
        if (words[num][0] == '\n')
            break;
    }
    show_menu();
    choice = getchar();
    while (getchar() != '\n')
        continue;
    while (choice != 'q' && choice != 'Q') {
        switch(choice) {
            case 'A':
            case 'a':
                source_str(ptstr, num);
                break;
            case 'B':
            case 'b':
                sort_ascii(ptstr, num);
                break;
            case 'C':
            case 'c':
                sort_length(ptstr, num);
            case 'D':
            case 'd':
                sort_first_len(ptstr, num);
            case 'q':
            case 'Q':
                break;
            default:
                printf("你输入的选项无效!");
                break;
        }
        show_menu();
        choice = getchar();
        while (getchar() != '\n')
            continue;
    }
    printf("程序已退出!");
}

void show_menu()
{
    printf("***********************************************************************\n");
    printf("请选择你要使用的功能: \n");
    printf("a. 打印源字符串                  b. 以ASCII中的顺序打印字符串\n");
    printf("c. 按长度递增顺序打印字符串      d. 按字符串中第1个单词的长度打印字符串\n");
    printf("q. 退出程序\n");
    printf("***********************************************************************\n");
}

void show_str(char *st[], int row)
{
    for (int k = 0; k < row; k++)
        puts(st[k]);
}

void source_str(char * st[], int row)
{
    for (int i = 0; i < row; i++) {
        puts(st[i]);
    }
}

void sort_ascii(char *st[], int row)
{
    char *temp;
    // 按ASCII排序
    for (int i = 0; i < row-1; i++) {
        for (int j = (i + 1); j < row; j++) {
            if (strcmp(st[i], st[j]) > 0) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    show_str(st, row);
}

void sort_length(char *st[], int row)
{
    char *temp;
    // 按长度排序
    for (int i = 0; i < row-1; i++) {
        for (int j = (i + 1); j < row; j++) {
            if (strlen(st[i]) > strlen(st[j])) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    show_str(st, row);
}

void sort_first_len(char *st[], int row)
{
    char *temp;
    // 按第一个单词长度排序
    for (int i = 0; i < row-1; i++) {
        for (int j = (i + 1); j < row; j++) {
            // 判断单词长度并排序
            if (first_word_len(st[i]) > first_word_len(st[j])) {
                temp = st[i];
                st[i] = st[j];
                st[j] = temp;
            }
        }
    }
    show_str(st, row);
}

int first_word_len(char *st)
{
    int len = 0;
    // 跳过前面的非字符输入
    while (isspace(*st))
        st++;
    while (!isspace(*st)) {
        st++;
        len++;
    }
    return len;
}