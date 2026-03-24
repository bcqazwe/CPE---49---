#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * fingerings[noteIndex][button]
 * noteIndex 對應音符，button 1~10 對應 10 個按鍵。
 * 值為 1 代表該音符需要按住此鍵，0 代表不需按。
 */
const int fingerings[14][11] = 
{
    {0, 0,1,1,1,0,0,1,1,1,1}, // c
    {0, 0,1,1,1,0,0,1,1,1,0}, // d
    {0, 0,1,1,1,0,0,1,1,0,0}, // e
    {0, 0,1,1,1,0,0,1,0,0,0}, // f
    {0, 0,1,1,1,0,0,0,0,0,0}, // g
    {0, 0,1,1,0,0,0,0,0,0,0}, // a
    {0, 0,1,0,0,0,0,0,0,0,0}, // b
    {0, 0,0,1,0,0,0,0,0,0,0}, // C
    {0, 1,1,1,1,0,0,1,1,1,0}, // D
    {0, 1,1,1,1,0,0,1,1,0,0}, // E
    {0, 1,1,1,1,0,0,1,0,0,0}, // F
    {0, 1,1,1,1,0,0,0,0,0,0}, // G
    {0, 1,1,1,0,0,0,0,0,0,0}, // A
    {0, 1,1,0,0,0,0,0,0,0,0}  // B
};

/* 將音符字元轉為 fingerings 的索引 */
int getNoteIndex(char note)
{
    char noteTable[] = {"cdefgabCDEFGAB"};

    for(int i = 0; i < 14; i++)
    {
        if(note == noteTable[i])
        {
            return i;
        }
    }
    return -1;
}

/*
目標：
給定一段薩克斯風樂譜字串，統計 10 個按鍵各自被「按下」的次數。

解法：
1. 先建立每個音符對應的按鍵需求表（fingerings）。
2. 逐字讀取樂譜中的音符，取得該音符所需按鍵狀態。
3. 對每個按鍵 j：
   - 若前一個音符此鍵是 0，現在是 1，表示發生一次「按下」，計數加一。
   - 更新目前按鍵狀態，供下一個音符比較。
4. 最後輸出 1~10 號按鍵的按下次數。

技巧：
1. 題目要的是「按下次數」而不是「按住時間」，所以只在 0 -> 1 時累加。
2. 用 prevButton 陣列保存上一個音符的按鍵狀態，邏輯清楚且效率高。
3. fingerings 以查表方式處理，避免大量 if/else 判斷音符。
*/
int main()
{
    /* 測資筆數 */
    int time;

    scanf("%d", &time);
    /* 吃掉讀完整數後的換行 */
    getchar();

    for(int k = 0; k < time; k++)
    {
        /* 一行樂譜字串 */
        char input[300];
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        /* pressedCount[j]: 第 j 鍵被按下的次數 */
        int pressedCount[11] = {0};
        /* prevButton[j]: 前一個音符時第 j 鍵是否按住 */
        int prevButton[11] = {0};

        /* 逐音符處理 */
        for(int i = 0; input[i] != '\0'; i++)
        {
            int index = getNoteIndex(input[i]);

            /* 比較上一狀態與目前音符狀態，統計 0 -> 1 的次數 */
            for(int j = 1; j < 11; j++)
            {
                if(prevButton[j] == 0 && fingerings[index][j] == 1)
                {
                    pressedCount[j]++;
                }
                prevButton[j] = fingerings[index][j];
            }
        }

        /* 依題目格式輸出 10 個按鍵的按下次數 */
        for(int i = 1; i < 11; i++)
        {
            printf("%d", pressedCount[i]);
            if(i != 10)
            {
                printf(" ");
            }
            if(i == 10)
            {
                printf("\n");
            }
        }
    }
    return 0;
}