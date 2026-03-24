#include <stdio.h>
#include <stdlib.h>

/*
目標：
給定一列火車車廂編號，計算要把車廂排列成遞增順序所需的最少交換次數。

解法：
使用氣泡排序（Bubble Sort）模擬相鄰交換。每當相鄰兩項順序錯誤就交換一次，
並將交換次數累加。氣泡排序中發生的交換總數，正好等於此排列的反序對數量，
也就是最少相鄰交換次數。

技巧：
1. 題目要的是交換次數，不一定要真的輸出排序後結果。
2. 用氣泡排序直接統計交換次數，寫法直觀且容易對照題意。
3. 每筆測資獨立處理，輸出固定句型即可。
*/
int bubbleSortCount(int *array, int index)
{
    /* 記錄總交換次數 */
    int count = 0;

    /* 進行氣泡排序，並同步累計交換次數 */
    for(int i = 0; i < index - 1; i++)
    {
        for(int j = 0; j < index - 1; j++)
        {
            if(array[j] > array[j + 1])
            {
                /* 相鄰逆序時交換 */
                int temp = array[j + 1];
                array[j + 1] = array[j];
                array[j] = temp;
                count++;
            }
        }
    }
    return count;
}
int main()
{
    /* 測資組數 */
    int times;
    scanf("%d", &times);

    while(times--)
    {
        /* 目前這組測資的車廂數量 */
        int trains;
        scanf("%d", &trains);

        /* 儲存車廂編號序列 */
        int array[trains];

        /* 讀入原始排列 */
        for(int i = 0; i < trains; i++)
        {
            scanf("%d", &array[i]);
        }

        /* 計算最少相鄰交換次數 */
        int compareTime = bubbleSortCount(array, trains);
        printf("Optimal train swapping takes %d swaps.\n", compareTime);
    }
    return 0;
}