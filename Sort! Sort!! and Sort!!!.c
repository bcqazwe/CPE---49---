#include <stdio.h>
#include <stdlib.h>

/* 全域變數：排序用的模數 m，讓 compare 函式可直接存取 */
int mod;

/*
 * 自訂排序規則（依照題目優先順序）：
 * 1. 以 num % mod 的餘數由小到大排
 * 2. 餘數相同時，奇數排在偶數前面
 * 3. 同為奇數，由大到小排
 * 4. 同為偶數，由小到大排
 */
int compare(const void *a, const void *b)
{
    int num1 = *(int *)a;
    int num2 = *(int *)b;
    /* 計算各自對 mod 的餘數 */
    int r1 = num1 % mod;
    int r2 = num2 % mod;

    /* 優先條件：餘數較小的排前面 */
    if(r1 != r2)
    {
        return r1 - r2;
    }

    /* 判斷奇偶性（取絕對值避免負數影響） */
    int isOdd1 = abs(num1 % 2);
    int isOdd2 = abs(num2 % 2);

    /* 次要條件：奇數排偶數前（isOdd2 - isOdd1 讓奇數排在前） */
    if(isOdd1 != isOdd2)
    {
        return isOdd2 - isOdd1;
    }

    /* 同為奇數：由大到小排 */
    if(isOdd1)
    {
        return num2 - num1;
    }

    /* 同為偶數：由小到大排 */
    return num1 - num2;
}

/*
目標：
給定 N 個整數與模數 m，依照四層優先級的自訂規則對整數進行排序並輸出。

解法：
直接使用 qsort 搭配自訂 compare 函式，在 compare 中依序實作四個排序優先條件：
1. 對 m 取餘數，餘數小的排前面
2. 餘數相同時，奇數排偶數前面
3. 同為奇數，由大到小排
4. 同為偶數，由小到大排
直到讀到 count == 0 且 mod == 0 為終止條件。

技巧：
1. 把 mod 設為全域變數，compare 函式即可直接存取，不需額外傳參數。
2. 奇偶判斷用 abs(num % 2)，可避免負數在 C 語言取模時回傳負餘數的問題。
3. 題目格式要先輸出 count 與 mod 再輸出結果，記得保留 printf 的順序。
*/
int main()
{
    /* count: 本筆整數個數 */
    int count;

    /* 讀到 0 0 結束 */
    while(1)
    {
        scanf("%d %d", &count, &mod);
        /* 先輸出本筆的 count 與 mod */
        printf("%d %d\n", count, mod);
        if(count == 0 && mod == 0)
        {
            break;
        }

        /* 儲存本筆整數 */
        int array[count];

        for(int i = 0; i < count; i++)
        {
            scanf("%d", &array[i]);
        }

        /* 依自訂規則排序(sizeof(int)必須) */
        qsort(array, count, sizeof(int), compare);

        /* 逐行輸出排序結果 */
        for(int i = 0; i < count; i++)
        {
            printf("%d\n", array[i]);
        }
    }
    return 0;
}