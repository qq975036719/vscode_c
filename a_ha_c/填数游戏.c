#include <stdio.h>
#include <stdlib.h>
int main()
{
    for (int a=1; a<=6; a++)
        for (int b=1; b<=6; b++)
            for (int c=1; c<=6; c++)
                for (int d=1; d<=6; d++)
                    for (int e=1; e<=6; e++)
                        for (int f=1; f<=6; f++)
                        {
                            if (a!=b && a!=c && a!=d && a!=e && a!=f &&
                                b!=c && b!=d && b!=e && b!=f &&
                                c!=d && c!=e && c!=f &&
                                d!=e && d!=f &&
                                e!=f && a+b+c == c+d+e && a+b+c == a+f+e)
                                    printf("%d %d %d %d %d %d\n", a,b,c,d,e,f);
                        }    
                            
    return 0;
}
