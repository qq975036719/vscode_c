// 读取两个二进制字符串 -- 分别使用不同的运算符
#include <stdio.h>
#include <limits.h>

int btoi(char *);
char *itob(int num, char *st);

int main(int argc, char *argv[])
{

    char temp_1[32];
    int a;

    a = ~btoi(argv[1]);
    itob(a, temp_1);
    printf("~%s == %s\n\n", argv[1], temp_1);
    a = ~btoi(argv[2]);
    itob(a, temp_1);
    printf("~%s == %s\n\n", argv[2], temp_1);

    a = btoi(argv[1]) & btoi(argv[2]);
    printf("%s & %s == %s\n\n", argv[1], argv[2], itob(a, temp_1));

    a = btoi(argv[1]) | btoi(argv[2]);
    printf("%s | %s == %s\n\n", argv[1], argv[2], itob(a, temp_1));

    a = btoi(argv[1]) ^ btoi(argv[2]);
    printf("%s ^ %s == %s\n\n", argv[1], argv[2], itob(a, temp_1));

    return 0;
}

int btoi(char *pb)
{
    int sum = 0;
    while (*pb) {
        sum *= 2;
        sum += *pb++ - '0';
    }

    return sum;
}

char * itob(int num, char *st)
{
    int i;
    int size = sizeof(int) * CHAR_BIT;

    for (i = size - 1; i >= 0; i--, num >>= 1)
        st[i] = (01 & num) + '0';
    st[size] = '\0';

    return st;
}