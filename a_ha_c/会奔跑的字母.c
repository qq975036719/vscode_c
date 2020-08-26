#include <stdio.h>
#include <stdlib.h>
#include <winbase.h>

int main()
{
    int a=0;
    while(a<=100)
    {
        system("cls");
        int b=1;
        while(b<=a)
        {
            printf(" ");
            b++;
        }
        printf("H");
        Sleep(1);
        a++;
    }
    return 0;
}
