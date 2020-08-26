// 返回指定日期的天数
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct {
    char month_name[10];
    char sname[4];
    int days;
    int month;
} DATE;

DATE input[12] = {
    {"Janurary", "Jan", 31, 1},
    {"February", "Feb", 28, 2},
    {"March", "Mar", 31, 3},
    {"April", "Apr", 30, 4},
    {"May", "May", 31, 5},
    {"June", "Jun", 30, 6},
    {"July", "Jul", 31, 7},
    {"August", "Aug", 31, 8},
    {"September", "Sep", 30, 9},
    {"October", "Oct", 31, 10},
    {"November", "Nov", 30, 11},
    {"December", "Dec", 31, 12}
};

int calc_days(char *month, int day);
int main(void)
{
    int year, day;
    char month[10];

    printf("请输入年月日: ");
    scanf("%d %s %d", &year, month, &day);
    
    while (year > 1000) {
        int result = calc_days(month, day);

        if (result != -1)
            printf("%d/%s/%d 有%d天\n",
                    year, month, day, calc_days(month, day));
        else
            printf("输入的格式有误, 请重新输入!\n");

        printf("请输入年月日: ");
        scanf("%d %s %d", &year, month, &day);
    }
    printf("Done!");

    return 0;
}

int calc_days(char *month, int day)
{
    if (day<1 || day>31)
        return -1;

    int total = day;
    int temp = atoi(month);

    for (int i = 0; i < 12; i++) {
        if (strcmp(month, input[i].month_name) == 0 ||
            strcmp(month, input[i].sname) == 0 ||
            temp == input[i].month) {
                if (day > input[i].days)
                    return -1;
                else
                    return total;
            }
        else
            total += input[i].days;
    }

    return -1;
}