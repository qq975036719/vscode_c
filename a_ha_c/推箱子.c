#include <stdio.h>
#include <stdlib.h>
int main()
{
    char a[12][12] = {"   ### ",
                      "   #*#",
                      "   # #",
                      "####O######",
                      "#*  OS O *#",
                      "#####O#####",
                      "    # #    ",
                      "    #*#    ",
                      "    ###    "};
    int i, x=4, y=5, count=0;
    char ch;
    
    for (i=0; i<=8; i++)
        puts(a[i]);
        
    while(count<4)
    {
        ch = getch(); // 输入指令
        
        // 当小人向下移动
        if (ch=='s' || ch=='S')
        {
            if (a[x+1][y]!='#' && a[x+1][y]!='O' && a[x+1][y]!='@')
            {
               a[x][y] = ' ';
               x++;
               a[x][y] = 'S';
            }
            
            if (a[x+1][y]!='#' && a[x+1][y]=='O' && a[x+2][y]=='*')
            {
                a[x][y] = ' ';
                x++;
                a[x][y] = 'S';
                a[x+1][y] = '@';
                count++;
            }
            
            if (a[x+1][y]!='#' && a[x+1][y]=='O' && a[x+2][y]!='*' && a[x+2][y]!='#')
            {
                a[x][y] = ' ';
                x++;
                a[x][y] = 'S';
                a[x+1][y] = 'O';
            }
            
        }
            
            // 当小人向上移动
        if (ch=='w' || ch=='w')
        {    
            if (a[x-1][y]!='#' && a[x-1][y]!='O' && a[x-1][y]!='@')
            {
               a[x][y] = ' ';
               x--;
               a[x][y] = 'S';
            }
            
            if (a[x-1][y]!='#' && a[x-1][y]=='O' && a[x-2][y]=='*')
            {
                a[x][y] = ' ';
                x--;
                a[x][y] = 'S';
                a[x-1][y] = '@';
                count++;
            }
            
            if (a[x-1][y]!='#' && a[x-1][y]=='O' && a[x-2][y]!='*' && a[x-2][y]!='#')
            {
                a[x][y] = ' ';
                x--;
                a[x][y] = 'S';
                a[x-1][y] = 'O';
            }
        }
            
            // 当小人向左移动
        if (ch=='a' || ch=='A')
        {
            if (a[x][y-1]!='#' && a[x][y-1]!='O' && a[x][y-1]!='@')
            {
               a[x][y] = ' ';
               y--;
               a[x][y] = 'S';
            }
            
            if (a[x][y-1]!='#' && a[x][y-1]=='O' && a[x][y-2]=='*')
            {
                a[x][y] = ' ';
                y--;
                a[x][y] = 'S';
                a[x][y-1] = '@';
                count++;
            }
            
            if (a[x][y-1]!='#' && a[x][y-1]=='O' && a[x][y-2]!='*' && a[x][y-2]!='#')
            {
                a[x][y] = ' ';
                y--;
                a[x][y] = 'S';
                a[x][y-1] = 'O';
            }
        }
            
            // 当小人向右移动
        if (ch=='d' || ch=='D')
        {
            if (a[x][y+1]!='#' && a[x][y+1]!='O' && a[x][y+1]!='@')
            {
               a[x][y] = ' ';
               y++;
               a[x][y] = 'S';
            }
            
            if (a[x][y+1]!='#' && a[x][y+1]=='O' && a[x][y+2]=='*')
            {
                a[x][y] = ' ';
                y++;
                a[x][y] = 'S';
                a[x][y+1] = '@';
                count++;
            }
            
            if (a[x][y+1]!='#' && a[x][y+1]=='O' && a[x][y+2]!='*' && a[x][y+2]!='#')
            {
                a[x][y] = ' ';
                y++;
                a[x][y] = 'S';
                a[x][y+1] = 'O';
            }
        }
        
        system("cls");
        for (i=0; i<=8; i++)
            puts(a[i]);
    }
    system("cls");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    printf("YOU WIN!!!!!\n");
    sleep(5);
    
    return 0;
}
