#include <stdio.h>
#include <stdlib.h>

/*
目標：
判斷每個矩陣是否為 Symmetric Matrix。
條件包含：
1. 矩陣中所有元素皆不可為負數
2. 矩陣在旋轉 180 度後，內容需與原矩陣完全相同

解法：
1. 讀入矩陣大小 N 與 N x N 元素。
2. 先掃描整個矩陣，若任一元素 < 0，直接標記非對稱。
3. 若目前仍可能對稱，再逐格比較：
   array[i][j] 是否等於 array[N-1-i][N-1-j]。
4. 全部都符合才輸出 Symmetric，否則輸出 Non-symmetric。

技巧：
1. 旋轉 180 度後的對應位置可直接用 (N-1-i, N-1-j) 計算。
2. 先做負數檢查，可提早排除不合法矩陣。
3. 元素型別用 long long，可降低大數輸入時的溢位風險。

隱藏的小細節：
1. 輸入格式是 "N = 數字"，scanf 需帶固定字元格式才能正確讀取。
2. 就算矩陣幾何上對稱，只要有負數依題意也必須判定為 Non-symmetric。
3. 中心點（若 N 為奇數）會對應到自己，天然符合旋轉對稱，不需特別處理。
4. 目前程式比較時遍歷全部元素，雖可再優化成半矩陣，但完整遍歷可讀性較高。
*/
int main()
{
    /* 測資筆數 */
    int time;
    scanf("%d", &time);

    /* 逐筆測資處理 */
    for(int k = 0; k < time; k++)
    {
        /* size: 矩陣邊長；isSymmetric: 是否仍符合條件 */
        int size, isSymmetric = 1;

        /* 依題目格式讀入 N（前導空白可吃掉上一行換行） */
        scanf(" N = %d", &size);

        /* 使用 long long 儲存矩陣元素，避免大數溢位 */
        long long int array[size][size];

        /* 讀入矩陣內容 */
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                scanf("%lld", &array[i][j]);
            }
        }

        /* 先檢查是否存在負數元素 */
        for(int i = 0; i < size; i++)
        {
            for(int j = 0; j < size; j++)
            {
                if(array[i][j] < 0)
                {
                    isSymmetric = 0;
                }
            }
        }

        /* 確認無負數後，再檢查 180 度旋轉對稱 */
        if(isSymmetric)
        {
            for(int i = 0; i < size; i++)
            {
                for(int j = 0; j < size; j++)
                {
                    if(array[i][j] != array[size - i - 1][size - j - 1])
                    {
                        isSymmetric = 0;
                    }
                }
            }
        }

        /* 依題目指定格式輸出結果 */
        printf("Test #%d: ", k + 1);
        if(isSymmetric)
        {
            printf("Symmetric.\n");
        }
        else
        {
            printf("Non-symmetric.\n");
        }
        
        
    }
}