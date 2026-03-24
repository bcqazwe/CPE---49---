#include<stdio.h>
#include<stdlib.h>

int main()
{
    int length;
    while(scanf("%d", &length) != EOF)
    {
        int array[length], trigger = 1;

        //用於檢查是否出現1 - (n - 1)
        int checkTable[length];

        for(int i = 0; i < length; i++)
        {
            scanf("%d", &array[i]);
        }

        //將長度標記為出現過
        for(int i = 0; i < length - 1; i++)
        {
            checkTable[abs(array[i] - array[i + 1])] = 1;
        }

        //若其中一個沒出現即停止
        for(int i = 1; i < length; i++)
        {
            if(checkTable[i] != 1)
            {
                trigger = 0;
                break;
            }
        }

        if(trigger)
        {
            printf("Jolly\n");
        }
        else
        {
            printf("Not jolly\n");
        }

    }
}