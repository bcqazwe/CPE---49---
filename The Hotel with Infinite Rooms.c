#include <stdio.h>
#include <stdlib.h>

int main()
{
    long long int s, d;
    
    //原理:查詢天數開始減去當前團體的入住天數，若 <= 0則剛好該團體正入住中
    while(scanf("%lld %lld", &s, &d) != EOF)
    {
        while(d > 0)
        {
            d -= s;
            s++;
        }
        s--;
        printf("%lld\n", s);
    }
    
}