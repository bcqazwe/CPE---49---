#include <stdio.h>
#include <stdlib.h>

//使用bubble sort排序array(需用到中位數)
void bubbleSort(int *array, int num)
{
    for(int i = 0; i < num - 1; i++)
    {
        for(int j = 0; j < num - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                int temp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int time, relativeNum;
    scanf("%d", &time);

    while(time--)
    {
        //輸入部分
        scanf("%d", &relativeNum);
        int relativeDis[relativeNum];
        for(int i = 0; i < relativeNum; i++)
        {
            scanf("%d", &relativeDis[i]);
        }

        bubbleSort(relativeDis, relativeNum);

        //提取中位數
        int median = relativeDis[relativeNum / 2];

        //取得中位數與全部距離的總和
        int totalDistance = 0;
        for(int i = 0; i < relativeNum; i++)
        {
            totalDistance = totalDistance + abs(relativeDis[i] - median);
        }

        printf("%d\n", totalDistance);
    }
    
    return 0;
}