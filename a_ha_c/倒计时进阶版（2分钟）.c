#include <stdio.h>
#include <stdlib.h>
int main()
{
    int m = 1;
    int i = 59;
    printf("2:00");
    sleep(1);
    while (i>=0)
    {
        if (i<10)
        {
            system ("cls");
            printf("%d:0%d\n", m, i);
            i--;
            sleep(1);
        }
        else
        {
        system ("cls");
        printf("%d:%d\n", m, i);
        i--;
        sleep(1);
        }
    }
    m = 0;
    i = 59;
    printf("1:00");
    while (i>=0)
    {
        if (i<10)
        {
            system ("cls");
            printf("%d:0%d\n", m, i);
            i--;
            sleep(1);
        }
        else
        {
        system ("cls");
        printf("%d:%d\n", m, i);
        i--;
        sleep(1);
        }
    }
    return 0;
}
