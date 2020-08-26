// 打印姓名
#include <stdio.h>

int main(void)
{
    char first_name[50], last_name[50];
    printf("请输入您的名和姓，如小宝 韦:\n");
    scanf("%s %s", last_name, first_name);
    printf("%s,%s\n", last_name, first_name);

    getchar();
    getchar();
    return 0;
}