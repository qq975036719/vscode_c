#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void Reverse(char str[]);
int main()
{
    char str[1000];

    for (int i = 0; i < 1000; i++) {
        if (gets(str) != NULL) {
            Reverse(str);
            puts(str);
        }
        else
            break;
    }

    return 0;
}
void Reverse(char str[]){
    int n=strlen(str);
    int i;
    char temp;
    for(i=0;i<(n/2);i++){
        temp=str[i];
        str[i]=str[n-i-1];
        str[n-i-1]=temp;
    }
}