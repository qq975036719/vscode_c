// 嵌套结构
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

const char *msg[5] = {
    "   Thank you for the wonderful evening, ",
    "You certainly prove that a ",
    "is a special kind of guy. We must get together",
    "over a delicious ",
    " and have a few laughs"
};

int main(void)
{
    struct guy fellow = {
        {"Alan", "Walker"},
        "Shit",
        "Fucker",
        97500
    };

    printf("Dear %s,\n\n", fellow.handle.first);
    printf("%s %s.\n", msg[0], fellow.handle.first);
    printf("%s %s\n", msg[1], fellow.job);
    printf("%s\n", msg[2]);
    printf("%s%s", msg[3], fellow.favfood);
    printf("%s", msg[4]);

    if (fellow.income > 100000)
        printf("!!\n");
    else if (fellow.income > 60000)
        printf("!\n");
    else
        printf(".\n");

    return 0;
}