#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
目標：
讀入多行字串，統計每一行中各 ASCII 字元出現的次數，並依照題目要求輸出：
1. 出現次數由小到大排序
2. 若出現次數相同，ASCII 值由大到小排序

解法：
1. 對每一行輸入建立一個 letters[256] 陣列，分別對應所有 ASCII 字元。
2. 掃描字串中的每個字元，將對應 ASCII 位置的出現次數加一。
3. 使用 qsort 依照題目指定的排序規則排序。
4. 依序輸出所有出現次數不為 0 的字元與其頻率。

技巧：
1. 題目是依 ASCII 值輸出，不是直接輸出字元本身，所以結構中要記錄 ascii 與 freq。
2. 排序規則是先比頻率、再比 ASCII 值，適合寫成自訂 compare 函式交給 qsort。
3. 每筆測資輸出後要補一個空白行，才能符合 UVA 題目的輸出格式。
*/
typedef struct 
{
    /* 字元的 ASCII 數值 */
    int ascii;
    /* 該字元在目前這一行出現的次數 */
    int freq;
}Letter;

/*
 * 排序規則：
 * 1. 頻率小的排前面
 * 2. 若頻率相同，ASCII 較大的排前面
 */
int compare(const void *a, const void *b)
{
    Letter *l1 = (Letter *)a;
    Letter *l2 = (Letter *)b;

    if(l1->freq != l2->freq)
    {
        return l1->freq - l2->freq;
    }

    return l2->ascii - l1->ascii;
}

int main()
{
    /* 儲存每一行輸入內容 */
    char input[1100];
    /* 字串長度 */
    int len;
    /* 紀錄 256 個 ASCII 字元的頻率資訊 */
    Letter letters[256];

    /* 持續讀入直到 EOF，每次處理一行 */
    while(fgets(input, sizeof(input), stdin) != NULL)
    {
        /* 去掉 fgets 讀進來的換行字元 */
        input[strcspn(input, "\n")] = '\0';
        len = strlen(input);
        
        /* 每處理新的一行前，先把所有頻率歸零 */
        for(int i = 0; i < 256; i++)
        {
            letters[i].freq = 0;
        }

        /* 掃描整行字串，累計每個 ASCII 字元的出現次數 */
        for(int i = 0; i < len; i++)
        {
            int ascii = (int)input[i];
            letters[ascii].ascii = ascii;
            letters[ascii].freq++;;
        }

        /* 依題目要求排序：頻率遞增，若相同則 ASCII 遞減 */
        qsort(letters, 256, sizeof(Letter), compare);

        /* 只輸出實際有出現過的字元 */
        for(int i = 0; i < 256; i++)
        {
            if(letters[i].freq != 0)
            {
                printf("%d %d\n", letters[i].ascii, letters[i].freq);
            }
        }

        /* 每筆測資之間輸出一個空行 */
        printf("\n");
    }
    
}