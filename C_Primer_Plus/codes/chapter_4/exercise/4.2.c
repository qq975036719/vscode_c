// 打印名字 -- 增加亿点点细节
#include <stdio.h>
#include <string.h>

int main(void)
{
    char first_name[50], last_name[50];
    printf("请输入您的名和姓，如小宝 韦:\n");
    scanf("%s %s", last_name, first_name);
    int len = strlen(last_name) + strlen(first_name);
    
    // 打印名和姓，包括双引号
    printf("\"%s %s\"\n", last_name, first_name);
    // 在宽度为20的字段右端打印名和姓，包括双引号
    printf("\"%20s %s\"\n", last_name, first_name);
    // 在宽度为20的字段左端打印名和姓，包括双引号
    printf("\"%s %-20s\"\n", last_name, first_name);
    // 在比姓名宽度宽3的字段中打印名和姓
    printf("*%*s %s*\n", len/2 + 3, last_name, first_name);

    getchar();
    getchar();
    return 0;
}