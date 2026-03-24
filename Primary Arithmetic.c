#include <stdio.h>
#include <stdlib.h>

//取得最後一位的值
int getDigit(int num)
{
    return num % 10;
}

int main()
{
    int num1, num2, totalCarry;
    int carry;

    //持續執行直到輸入皆為0
    while(1)
    {
        //每次皆需重置進位與進位總和
        totalCarry = 0;
        carry = 0;

        scanf("%d %d", &num1, &num2);
        if(num1 == 0 && num2 == 0)
        {
            break;
        }

        //判斷是否產生進位
        while(1)
        {
            if(num1 == 0 && num2 == 0)
            {
                break;
            }

            if(carry + getDigit(num1) + getDigit(num2) >= 10)
            {
                totalCarry += 1;
                carry = 1;
            }
            else
            {
                carry = 0;
            }
            num1 /= 10;
            num2 /= 10;
        }

        if(totalCarry == 0)
        {
            printf("No carry operation.\n");
        }
        else if(totalCarry == 1)
        {
            printf("1 carry operation.\n");
        }
        else
        {
            printf("%d carry operations.\n", totalCarry);
        }

    }
    
}