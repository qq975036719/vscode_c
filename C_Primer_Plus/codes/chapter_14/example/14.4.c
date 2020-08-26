// 使用指向结构的指针
#include <stdio.h>
#define LEN 20

struct name {
    char first[LEN];
    char last[LEN];
};

struct guy {
    struct name handle;
    char favfood[LEN];
    char job[LEN];
    float income;
};

int main(void)
{
    struct guy fellow[2] = {
        { { "Alan", "Walker"},
            "Shit",
            "Fucker",
            97500
        },
        { { "Hallo", "Body"},
            "chip",
            "Be-Fucker",
            97600
        }
    };

    struct guy *him;      // 指向struct guy结构的指针

    printf("地址 #1: %p     #2: %p\n", &fellow[0], &fellow[1]);

    him = &fellow[0];
    printf("指针 #1: %p     #2: %p\n", him, him+1);
    printf("him->income is $%.2f -- (*him).income is $%.2f\n",
           him->income, (*him).income);
    him++;
    printf("him->favfood is %s -- him->handle.last is %s\n",
           him->favfood, him->handle.last);

    return 0;
}