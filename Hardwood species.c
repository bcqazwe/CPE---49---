#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
目標：
給定多筆測資，每筆測資包含多行樹種名稱（以空白行結束），
要輸出每個樹種在該測資中所佔的百分比，並依字典序排列。

解法：
1. 逐行讀入該測資所有樹種名稱，存入陣列。
2. 使用 qsort 依字典序排序整個名稱陣列。
3. 線性掃描排序後陣列，把連續相同名稱視為同一群組並計數。
4. 以 count / total * 100 計算比例，輸出到小數點後四位。

技巧：
1. 先排序再分組，可把統計問題化為一次線性掃描。
2. 利用 strcspn 去掉 fgets 讀入的換行符號，避免比較字串時受影響。
3. 使用雙層索引 i、j：i 指向當前樹種起點，j 往後找下一個不同名稱。

隱藏的小細節：
1. 讀完測資數 T 後，要處理掉輸入中的空行，否則第一筆資料會被誤判為空。
2. qsort 的元素大小必須與每筆名稱儲存空間一致（此處為 35 bytes）。
3. Case 之間要輸出一個空行，但最後一筆後不需要額外處理。
4. 比例計算要轉成 double，避免整數除法造成精度錯誤。
*/

// 定義最大樹木數量與名稱長度
char all_trees[1000005][35];

// qsort 使用的比較函式 (字典序)
int compare(const void *a, const void *b) 
{
    return strcmp((char *)a, (char *)b);
}

int main() {
    // T: 測資筆數；line: 暫存讀取空行或過渡用字串
    int T;
    char line[35];
    
    // 若無法讀到測資數，直接結束
    if (scanf("%d", &T) == EOF)
    {
        return 0;
    }
    
    // 跳過 scanf 後的兩個換行 (一個是數字後的 \n，一個是題目要求的空行)
    getchar(); 
    fgets(line, sizeof(line), stdin);

    for (int t = 0; t < T; t++) 
    {
        // total: 當前測資的樹木總數
        int total = 0;

        // 讀取該 Case 的所有樹木，遇到空白行代表本 Case 結束
        while (fgets(all_trees[total], 35, stdin) && all_trees[total][0] != '\n') 
        {
            // 移除行尾換行字元，讓字串比較一致
            all_trees[total][strcspn(all_trees[total], "\n")] = 0;
            total++;
        }

        // 1. 依字典序排序，讓相同樹種集中在一起
        qsort(all_trees, total, 35, compare);

        // 2. 統計並輸出
        if (t > 0) 
        {
            printf("\n"); // Case 之間的空行
        }

        // 掃描排序後陣列，統計每個樹種連續出現的次數
        for (int i = 0; i < total; ) 
        {
            int count = 0;
            char *current_name = all_trees[i];
            
            // 統計相同名稱的數量
            int j = i;
            while (j < total && strcmp(all_trees[j], current_name) == 0) 
            {
                count++;
                j++;
            }
            
            // 計算百分比並輸出（轉 double 避免整數除法）
            printf("%s %.4f\n", current_name, (double)count * 100.0 / total);
            i = j; // 跳到下一個不同的樹種
        }
    }
    return 0;
}