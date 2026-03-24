#include <stdio.h>
#include <stdlib.h>

/* 儲存每筆測資的整數陣列（最大長度依題目需求預留） */
int array[1000010];

/* qsort 比較函式：由小到大排序 */
int compare(const void *a, const void *b)
{
    int *num1 = (int *)a;
    int *num2 = (int *)b;

    return *num1 - *num2;
}

/*
目標：
給定一串整數，輸出：
1. 最小可能中位數（排序後中間位置）
2. 可作為中位數的數量（陣列中等於中位區間端點的元素個數）
3. 可作為中位數的整數個數範圍

解法：
1. 先將陣列排序。
2. 令 median1 = array[(n - 1) / 2]、median2 = array[n / 2]。
   - 當 n 為奇數時，median1 與 median2 相同。
   - 當 n 為偶數時，可能中位數落在 [median1, median2]。
3. 統計陣列中等於 median1 或 median2 的元素數量，得到 possible。
4. 可作為中位數的整數個數為 median2 - median1 + 1。

技巧：
1. 使用 qsort 快速排序，直接以索引取出中位區間端點。
2. (n - 1) / 2 與 n / 2 這組寫法可同時處理奇偶長度。
3. 輸出第一個值使用 median1，可符合題目要求的最小中位數。
*/
int main()
{
    int count;

    /* 讀到 EOF 為止，每次處理一筆測資 */
    while(scanf("%d", &count) != EOF)
    {
        /* 讀入 count 個整數 */
        for(int i = 0; i < count; i++)
        {
            scanf("%d", &array[i]);
        }

        /* 先排序，方便找中位數區間 */
        qsort(array, count, sizeof(int), compare);

        /* 中位區間兩端：奇數時兩者相同，偶數時可能不同 */
        int median1 = array[(count - 1) / 2];
        int median2 = array[count / 2];

        /* 統計陣列中等於中位區間端點的元素個數 */
        int possible = 0;
        for(int i = 0; i < count; i++)
        {
            if(array[i] == median1 || array[i] == median2)
            {
                possible++;
            }
        }

        /* 可作為中位數的整數個數（包含端點） */
        int possibleA = median2 - median1 + 1;

        printf("%d %d %d\n", median1, possible, possibleA);
    }
}