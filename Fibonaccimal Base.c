#include <stdio.h>
#include <stdlib.h>

/*
    目標:輸出斐波那契數之和的出現情形
    EX:17 = 13 + 3 + 1
    輸出:1 0 0 1 0 1
        13 8 5 3 2 1     

    技巧:生成斐波那契數列，並從最高位使用貪心法尋找
*/
int main()
{
    int fib[45], count = 2;

    //此題是從1和2開始
    fib[0] = 1, fib[1] = 2;

    //數列生成算法(直到100000000)
    for(int i = 2; i < 45; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        count++;
        if(fib[i] > 100000000)
        {
            break;
        }
    }

    int time, input;
    scanf("%d", &time);

    while(time--)
    {
        scanf("%d", &input);
    
        //預先輸出數字
        printf("%d = ", input);

        //用於檢查是否找到了第一個數
        int started = 0;

        //index要 - 1開始(陣列下標 - 1)
        for(int i = count - 1; i >= 0; i--)
        {
            if(input >= fib[i])
            {
                printf("1");
                started = 1;
                input -= fib[i];
            }
            else if(started)
            {
                printf("0");
            }
        }

        printf(" (fib)\n");

    }    
    return 0;
}