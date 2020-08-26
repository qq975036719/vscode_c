#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a, b;
    a = 0;
    while(a<=100)
    {
        b = 100;
        system("cls");
        while(b>=a)
        {
            printf(" ");
            b--;
        }
        printf(" O\n");
        b = 100;
        while(b>=a)
        {
            printf(" ");
            b--;
        }
        
        
        printf("<H>\n");
        b = 100;
        while(b>=a)
        {
            printf(" ");
            b--;
        }
        printf("I I\n");
        sleep(0);
        a++;
    }
    return 0;
}
