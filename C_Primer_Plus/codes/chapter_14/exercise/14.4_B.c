// 打印社会保险信息 -- 传递结构的值
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 40

typedef struct {
    char fname[MAX];
    char mname[MAX];
    char lname[MAX];
} USER;

typedef struct {
    char sid[30];
    USER name;
} user_info;

void show_info(user_info list, int n);
int main(void)
{
    user_info user_list[5] = {
        {
            "302039823",
            {
                "Dribble",
                "Mike",
                "Flossie",
            }
        }
    };
    show_info(user_list[0], 5);
    return 0;
}

void show_info(user_info list, int n)
{
    printf("用户信息如下: ");
    if (strlen(list.sid) < 9)
        return;
    printf("%s, %s", list.name.fname, list.name.lname);
    if (strlen(list.name.mname) > 0)
        printf(" %c.", list.name.mname[0]);
    printf(" -- %s\n", list.sid);
}