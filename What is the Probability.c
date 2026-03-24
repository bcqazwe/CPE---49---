#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main()
{
    int time;
    scanf("%d", &time);
    int n, i;
    double p;

    //等比公式 Ans = a / (1 - r)
    //首項 = p * (1 - p) ^ (i - 1)(前面的都失敗，自己成功)
    //公比 =(1 - p) ^ n(大家都失敗)
    while(time--)
    {
        scanf("%d %lf %d", &n, &p, &i);

        if(p == 0.0)
        {
            printf("0.000\n");
            continue;
        }
        double a = p * pow((1 - p), i - 1);
        double b = 1 - pow(1 - p, n);

        printf("%.4f\n", a / b);
    }
    return 0;
}