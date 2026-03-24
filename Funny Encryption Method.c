#include <stdio.h>
#include <stdlib.h>

/*
    目標:將數字分別視為10進位與16進位
        轉成二進位並分別計算有多少個1
        *十六進位是分別將每個位元都視為十進位*    

*/

//計算該十進位轉換後有多少1
int getOnes(int number)
{
    int count = 0;
    while(number > 0)
    {
        if(number % 2 == 1)
        {
            count++;
        }
        number /= 2;
    }

    return count;
}

//將每個位元都視為十進位並帶入getOnes()
int getB2(int number)
{
    int count = 0;
    while(number > 0)
    {
        count += getOnes(number % 10);
        number /= 10;
    }

    return count;
}

int main()
{
    int time, number, b1, b2;
    
    scanf("%d", &time);
    
    while(time--)
    {
        scanf("%d", &number);
        b1 = getOnes(number);
        b2 = getB2(number);

        printf("%d %d\n", b1, b2);
    }
    return 0;
}