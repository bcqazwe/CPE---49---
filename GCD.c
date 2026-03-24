#include <stdio.h>
#include <stdlib.h>

int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

int main()
{
    int g;
    int n; 
    while(1)
    {

        scanf("%d", &n);

        if(n == 0)
        {
            break;
        }
        g = 0;
        for(int i = 1; i < n; i++)
        {
            for(int j = i + 1; j <= n; j++)
            {
                g += GCD(i, j);
            }
        }
        printf("%d\n", g);
    }
    return 0;
}