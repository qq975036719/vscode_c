#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[50][50] = {"######",
                      "#O #  ",
                      "# ## #",
                      "#  # #",
                      "##   #",
                      "######",
                     };
    
    int i, x, y, p, q;
    x = 1;
    y = 1;
    p = 1;
    q = 5;
    
    char ch;
    
    for (i=0; i<=5; i++)
        puts(a[i]);
    
    while (x!=p || y!=q) {
    ch = getch();
    
    if (ch=='s' || ch=='S')
    {
        if (a[x+1][y]!='#')
        {
            a[x][y] = ' ';
            x++;
            a[x][y] = 'O';
        }
    }
    
    if (ch=='w' || ch=='W')
    {
        if (a[x-1][y]!='#')
        {
            a[x][y] = ' ';
            x--;
            a[x][y] = 'O';
        }
    }
    
    if (ch=='a' || ch=='A')
    {
        if (a[x][y-1]!='#')
        {
            a[x][y] = ' ';
            y--;
            a[x][y] = 'O';
        }
    }
    
    if (ch=='d' || ch=='D')
    {
        if (a[x][y+1]!='#')
        {
            a[x][y] = ' ';
            y++;
            a[x][y] = 'O';
        }
    }
    
    system("cls");
    for (i=0; i<=5; i++)
        puts(a[i]);
    }
    system("cls");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    puts("You Win!!!!!!");
    return 0;
}
