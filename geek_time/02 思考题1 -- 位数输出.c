#include <stdio.h>
#include <stdlib.h>

int main() {
    int num;
    scanf("%d", &num);
    printf(" has %d digits\n", printf("%d", num));
    char output[50];
    int ret = sprintf(output, "%d", num);
    printf("%d\n", ret);

    int n=100;
    printf(" %d ", printf("%d", n));

    return 0;
}
