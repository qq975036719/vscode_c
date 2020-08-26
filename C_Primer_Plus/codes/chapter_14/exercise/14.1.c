// 统计到指定月份为止的总天数
#include <stdio.h>
#include <string.h>

typedef struct {
    char name[10];
    char sname[4];
    int days;
    int monnum;
} MONTH;

MONTH months[12] = {
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

int calc_days(char *month);
int main(void)
{
    char month[10];

    printf("请输入月份(英文): ");
    scanf("%s", month);
    while (strlen(month) >= 3) {
        printf("The total to %s is %d\n", month, calc_days(month));
        printf("请输入月份(英文): ");
        scanf("%s", month);
    }
    printf("Done!");

    return 0;
}

int calc_days(char *month)
{
    int total = 0;
    for (int i = 0; i < 12; i++) {
        if (strcmp(month, months[i].name) == 0)
            return total;
        else
            total += months[i].days;
    }

    return -1;
}