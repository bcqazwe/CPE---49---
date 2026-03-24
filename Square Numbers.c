#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//目標:判斷兩數範圍內是否有平方數
int main()
{
    int a, b;
    
    while(1)
    {
        scanf("%d %d", &a, &b);

        if(a == 0 && b == 0)
        {
            break;
        }

        int count = 0;

        //使用sqrt()取得平方根，檢查平方根平方後是否等於原數
        for(int i = a; i <= b; i++)
        {
            int root = sqrt(i);
            if((root * root) == i)
            {
                count++;
            }
        }

        printf("%d\n", count);
    }
}