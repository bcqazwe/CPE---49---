#include <stdio.h>
#include <stdlib.h>

//計算位數總和
long long int digitSum(long long number)
{
    int sum = 0;

    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

//遞迴計算
long long int function(long long int number)
{
    if(number < 10)
    {
        return number;
    }
    else
    {
        return function(digitSum(number));
    }
}

int main()
{
    long long int number;
    
    while(1)
    {
        scanf("%lld", &number);

        if(number == 0)
        {
            break;
        }
        printf("%lld\n", function(number));
    }
    
    return 0;
}