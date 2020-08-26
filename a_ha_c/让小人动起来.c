#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    a = 0;
    while(a<=100)
    {
        b = 1;
        system("cls");
        while(b<=a)
        {
            printf(" ");
            b++;
        }
        printf(" O\n");
        b = 1;
        while(b<=a)
        {
            printf(" ");
            b++;
        }
        
        
        printf("<H>\n");
        b = 1;
        while(b<=a)
        {
            printf(" ");
            b++;
        }
        printf("I I\n");
        sleep(0);
        a++;
    }
    return 0;
}
