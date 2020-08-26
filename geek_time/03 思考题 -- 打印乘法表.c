#include <stdio.h>
#include <stdlib.h>

int main()
{
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=i; j++) {
            j == 1 || printf("\t");        // 从左往右，若第一个条件满足就不执行第二个条件，若第一个条件不满足就执行第二个条件
            printf("%d*%d=%d", j, i, j*i);
        }
        printf("\n");
    }
    return 0;
}
