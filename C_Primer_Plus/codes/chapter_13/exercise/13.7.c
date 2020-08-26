// 按指定模式打印两个文件的内容
// 模式a -- 打印第1个文件的第1行,第二个文件第1行 -- 然后第一个文件第2行,第二个文件第2行...以此类推
// 模式b -- 行号相同的行打印成一行
#include <stdio.h>
#include <stdlib.h>
#define LEN 40
#define LINE_SIZE 512

// 函数原型
void mode_a(FILE *fp1, FILE *fp2);
void mode_b(FILE *fp1, FILE *fp2);
void show_menu(void);
char get_choice(void);
char get_first(void);


int main(void)
{
    char file_1[LEN];
    char file_2[LEN];
    FILE *fp1, *fp2;
    char choice;

    // 读取文件名
    printf("请输入两个文件的文件名: ");
    while (scanf("%s %s", file_1, file_2) != 2)
        fprintf(stderr, "您的输入有误,请重新输入！\n");
    while (getchar()!='\n')
        continue;

    // 打开文件
    if ((fp1 = fopen(file_1, "r")) == NULL) {
        fprintf(stderr, "打开文件: %s 失败", file_1);
        exit(EXIT_FAILURE);
    }
    if ((fp2 = fopen(file_2, "r")) == NULL) {
        fprintf(stderr, "打开文件: %s 失败", file_2);
        exit(EXIT_FAILURE);
    }

    // 提示用户选择模式
    show_menu();
    choice = getchar();

    // 分模式执行
    switch(choice) {
        case 'a':
            mode_a(fp1, fp2);
            break;
        case 'b':
            mode_b(fp1, fp2);
            break;
        case 'q':
            break;
        default:
            printf("输入的选项有误!\n");
            break;
    }

}

void show_menu(void)
{
    printf("**********************************\n");
    printf("请选择模式: \n");
    printf("a. 按行号分别打印两个文件\n");
    printf("b. 按行号同时打印两个文件\n");
    printf("q. 退出程序\n");
    printf("**********************************\n");
}

char get_choice(void)
{
    char ch = get_first();
    while (ch != 'a' || ch != 'b' || ch != 'q') {
        fprintf(stderr, "你输入的选项有误,请重新输入!\n");
        ch = get_first();
    }

    return ch;
}

char get_first(void)
{
    char ch = getchar();
    while (getchar() != EOF)
        continue;
    
    return ch;
}

void mode_a(FILE *fp1, FILE *fp2)
{
    int i = 1;
    char line_1[LINE_SIZE];
    char line_2[LINE_SIZE];

    while (fgets(line_1, LINE_SIZE, fp1) != NULL) {
        if (fgets(line_2, LINE_SIZE, fp2) != NULL) {
            printf("FILE 1 NO.%d : %s", i, line_1);
            printf("FILE 2 NO.%d : %s", i, line_2);
            i++;
        }
        // 因为fgets()会保留换行符, 所以直接printf()即可
        // 因为题目要求分别逐行打印两个文件

        else {      // 第一个文件行数多于第二个文件行数时的情况
            printf("FILE 1 NO.%d : %s", i, line_1);
            i++;
        }
    }
    while (fgets(line_2, LINE_SIZE, fp2) != NULL)     // 第一个文件行数少于第二个文件行数时的情况
        printf("FILE 2 NO.%d : %s", i++, line_2);
}

void mode_b(FILE *fp1, FILE *fp2)
{
    int i = 1;
    char *line_1 = (char *)malloc(LINE_SIZE * sizeof(char));
    char *line_2 = (char *)malloc(LINE_SIZE * sizeof(char));

    while (fgets(line_1, LINE_SIZE, fp1) != NULL) {
        if (fgets(line_2, LINE_SIZE, fp2) != NULL) {
            printf("LINE NO.%d : ", i);
            while (*line_1 != '\n')
                putchar(*line_1++);
            putchar('+');
            printf("%s", line_2);
            i++;
        }
        // 因为fgets()会保留换行符, 所以要把第一个文件的换行符过滤掉才能与第二个文件同行
        // 因为题目要求两个文件的同一行号打印在同一行

        else {      // 第一个文件行数多于第二个文件行数时的情况
            printf("LINE NO.%d : %s", i, line_1);
            i++;
        }
    }
    while (fgets(line_2, LINE_SIZE, fp2) != NULL)     // 第一个文件行数少于第二个文件行数时的情况
        printf("LINE NO.%d : %s", i++, line_2);

    free(line_1);
    free(line_2);
}