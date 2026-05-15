#include <stdio.h>
#include <stdlib.h>

/**
 * Super Long Sums (UVa 10013)
 * 題目要求計算兩個超長整數（位數最高可達 1,000,000）的和。
 * 由於位數極多，必須逐位讀取並手動處理進位。
 */
int main()
{
    int cases, digits, num1, num2;
    
    // 讀取測試案例數量
    if (scanf("%d", &cases) == EOF) return 0;
    
    while(cases--)
    {
        // 題目要求案例間可能有空行，或者需跳過換行符
        getchar(); 
        // 讀取該大數的總位數
        if (scanf("%d", &digits) == EOF) break;

        // 使用動態長度陣列（VLA）儲存每一位的運算結果
        // 陣列大小可達 1,000,000，建議在正式環境或 stack 限制較小的環境使用 malloc
        int *array = (int *)malloc(digits * sizeof(int));

        // 逐位讀取兩個大數的當前位數，並相加存入陣列
        for(int i = 0; i < digits; i++)
        {
            scanf("%d %d", &num1, &num2);
            array[i] = num1 + num2;
        }

        // 從最後一位開始往前處理進位
        for(int i = digits - 1; i > 0; i--)
        {
            // 如果當前位數大於等於 10，則進位到前一位
            if(array[i] > 9)
            {
                array[i] -= 10;     // 當前位留個位數
                array[i - 1] ++;    // 前一位加 1
            }
        }
        
        // 依序輸出每一位結果，形成完整的和大數
        for(int i = 0; i < digits; i++)
        {
            printf("%d", array[i]);
        }
        printf("\n"); // 每個案例結果後換行

        // 題目要求：除了最後一個案例外，案例之間需輸出一行空行
        if(cases > 0)
        {
            printf("\n");
        }
        
        free(array); // 釋放記憶體
    }
    return 0;
}