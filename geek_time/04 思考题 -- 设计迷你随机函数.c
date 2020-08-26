#include <stdio.h>
#include <stdlib.h>

int main() {
    int n = 5;
    for (int i = 1; i <= 100; i++) {
        printf("%2d  ", n);         // %2d代表让内容右对齐
        if (i % 10 == 0) printf("\n");
        n = (n * 3) % 101;
    }
    return 0;
}
