#include <stdio.h>
#include <stdlib.h>

/*
    目標:輸出該數的二進位以及其二進位有多少1 

    技巧:由於計算二進位是由後往前，先將數字存至陣列在反向輸出
*/

void toBinary(int number)
{
    //index為記錄最後存入陣列的下標
    int index = 0, total = 0;
    int value[2000];

    while(number > 0)
    {
        int digit = number % 2;

        if(digit == 1)
        {
            total++;
        }
        value[index++] = digit;
        number /= 2;
    }

    printf("The parity of ");
    for(int i = index - 1; i >= 0; i--)
    {
        printf("%d", value[i]);
    }
    printf(" is %d (mod 2).\n", total);
}

int main()
{
    int number;

    while(1)
    {
        scanf("%d", &number);

        if(number == 0)
        {
            break;
        }

        toBinary(number);

    }
}