#include <stdio.h>
#include <stdlib.h>

int main()
{
    int num1, num2, cycleLength, maxCycleLength;
    while(scanf("%d %d", &num1, &num2) != EOF)
    {
        //預先輸出2數
        printf("%d %d ", num1, num2);

        //處理交換問題(後者必須較大)
        if(num1 > num2)
        {
            int temp = num1;
            num1 = num2;
            num2 = temp;
        }

        //新一輪max必須歸零
        maxCycleLength = 0;

        //num1至num2迴圈
        for(int i = num1; i <= num2; i++)
        {
            int n = i;

            //至少輸出一次n，所以cycleLength至少為1
            cycleLength = 1;

            //演算法內容
            while(1)
            {
                if(n == 1)
                {
                    break;
                }

                if(n % 2 != 0)
                {
                    n = 3 * n + 1;
                }
                else
                {
                    n /= 2;
                }

                cycleLength++;
            }

            //max比較
            if(cycleLength > maxCycleLength)
            {
                maxCycleLength = cycleLength;
            }
        }

        //輸入最大的cycleLength
        printf("%d\n", maxCycleLength);
    }
    return 0;
}