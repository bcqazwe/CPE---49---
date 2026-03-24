#include <stdio.h>
#include <stdlib.h>

int main()
{
    //需要使用long long int
    long long int hashmat, enemy;

    //需要使用 "%lld" 和 llabs()
    while(scanf("%lld %lld", &hashmat, &enemy) != EOF)
    {
        printf("%lld\n", llabs(hashmat - enemy));
    }
}