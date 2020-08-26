#include <stdio.h>
#include <stdlib.h>

int main(){
    int i = 1;
    while (i <= 9){
        int j = 1;
        while (j <= i) {
            printf("%d*%d=%d\t", j, i, i*j);
            j += 1;
        };
        printf("\n");
        i++;
    };
return 0;
}

int main1(){
    for (int i=1; i<=6; i++) {
        for (int j=1; j<=i; j++) printf("%d*%d=%d\t", j, i, j*i);
        printf("\n");
    }
return 0;
}

