#include <stdio.h>
#include <stdlib.h>

/*
    目標:判斷數列是否成立

    *下一個數為上一個數 / m ，且必須整除至1*

    技巧:m至少為2(不能除以0和1(無窮迴圈))且n不可為1，且被除數要大於除數
*/

int main()
{
    int array[2000];

    int n, m, count;
    int isBoring;

    while(scanf("%d %d", &n, &m) != EOF)
    {
        //初始化isBoring = 0和count = 1(因為array[0]是自己)
        isBoring = 0, count = 1;

        //先檢查輸入
        if(m < 2 || n < m)
        {
            printf("Boring!\n");
            continue;
        }

        //n為1直接結束
        if(n == 1)
        {
            printf("Boring!\n");
            continue;
        }
        
        //初始化array
        array[0] = n;
        for(int i = 1; i < 2000; i++)
        {
            array[i] = 0;
        }

        //重複迴圈直到1
        while(1)
        {
            if(n == 1)
            {
                break;
            }

            //無法整除為Boring
            if(n % m != 0)
            {
                isBoring = 1;
                break;
            }

            //將數值存入array
            array[count] = n / m;
            n /= m;
            count++;
        }

        //輸出
        if(isBoring)
        {
            printf("Boring!");
        }
        else
        {
            for(int i = 0; i < count; i++)
            {
                if(i > 0)
                {
                    printf(" ");
                }
                printf("%d", array[i]);
            }
        }
        printf("\n");
    }
    return 0;   
}