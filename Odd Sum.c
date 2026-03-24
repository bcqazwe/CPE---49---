#include <stdio.h>
#include <stdlib.h>

int main()
{
    int time;
    scanf("%d", &time);

    for(int i = 0; i < time; i++)
    {
        int front, end, sum = 0;
        scanf("%d %d", &front, &end);

        for(int j = front; j <= end; j++)
        {
            if(j % 2 != 0)
            {
                sum += j;
            }
        }

        printf("Case %d: %d\n", i + 1, sum);
    }
}