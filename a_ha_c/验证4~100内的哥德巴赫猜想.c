#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i;
    int counta;
    int countb;
    for (i=4 ;i<=100; i+=2)
    {
        for (int a=2; a<=i/2; a++)
        {
            
            // �ж� a �Ƿ�Ϊ����
            counta = 0;
            for (int aa=2; aa<=a-1; aa++)
            {
                if (a%aa==0)
                {
                    counta++;
                    break;
                }
            
            // ��� a ������
            if (counta==0)
                {
                    int b=i-a;
                    
                    // �ж� b �Ƿ�Ϊ����
                    countb = 0;
                    for (int bb=2; bb<=b-1; bb++)
                    {
                        if (b%bb==0)
                        {
                            countb++;
                            break;
                        }
                    }
                    if (countb==0)
                        {
                            printf("%d=%d+%d\n", i, a, b);
                            break;
                        }
                }    
                    
            }
        }
    }
    return 0;
}
