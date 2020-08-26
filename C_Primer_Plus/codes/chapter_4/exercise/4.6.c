// 格式化打印姓名和姓名长度
#include <stdio.h>
#include <string.h>

int main(void)
{
    char name[40];
    char surname[40];
    printf("请输入您的名和姓: ");
    scanf("%s %s", name, surname);

    // 获取名和姓的长度
    int len_name, len_surname;
    len_name = strlen(name);
    len_surname = strlen(surname);

    // 右对齐打印名字长度
    printf("%s %s\n", name, surname);
    printf("%*d %*d\n", len_name, len_name, len_surname, len_surname);

    // 左对齐打印名字长度
    printf("%s %s\n", name, surname);
    printf("%-*d %-*d", len_name, len_name, len_surname, len_surname);

    getchar();
    getchar();
    return 0;
}