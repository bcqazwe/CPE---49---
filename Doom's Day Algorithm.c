#include <stdio.h>
#include <stdlib.h>

//周一至周日的index為0 - 6
int main()
{

    int time, month, day;
    scanf("%d", &time);

    while(time--)
    {
        //以1/1為基準是周六
        int totalDays = 5;
        scanf("%d %d", &month, &day);

        //計算經過的天數
        for(int i = 1; i < month; i++)
        {
            if(i == 1 || i ==3 || i == 5 || i == 7
             || i == 8 || i == 10 || i == 12)
             {
                totalDays += 31;
             }
            else if(i == 4 || i == 6 || i == 9 || i == 11)
            {
                totalDays += 30;
            }
            else
            {
                totalDays += 28;
            }
        }

        //加上當月經過的天數 - 1(因為從1/1算)
        totalDays += day - 1;

        //計算星期幾
        int result = totalDays % 7;

        switch (result)
        {
        case 0:
            printf("Monday\n");
            break;
        case 1:
            printf("Tuesday\n");
            break;
        case 2:
            printf("Wednesday\n");
            break;
        case 3:
            printf("Thursday\n");
            break;
        case 4:
            printf("Friday\n");
            break;
        case 5:
            printf("Saturday\n");
            break;
        case 6:
            printf("Sunday\n");
            break;          
        default:
            break;
        }
    }
}