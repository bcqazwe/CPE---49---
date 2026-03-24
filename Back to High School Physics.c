#include <stdio.h>
#include <stdlib.h>

int main()
{
    int t, v;

    while(scanf("%d %d", &t, &v) != EOF)
    {
        printf("%d\n", (4 * v * t) / 2);
    }
    return 0;
}