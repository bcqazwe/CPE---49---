#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
目標：
給定一串可能包含 0-9、A-Z、a-z 的字元，找出使該字串在 base N 下
代表的數字可以被 (N - 1) 整除的最小 N（2 <= N <= 62）。

解法：
1. 先把每個合法字元轉成其數值（0~61），並累加總和 sum，同時找最大位值 max。
2. 進位基數 N 必須大於最大位值，因此從 N = max + 1 開始嘗試。
3. 利用性質：在 base N 中，一個數對 (N - 1) 取模，等同其各位數字和對 (N - 1) 取模。
    所以只要判斷 sum % (N - 1) == 0 是否成立。
4. 找到第一個成立的 N 就輸出；若到 62 都不成立，輸出 impossible。

技巧：
1. 字元映射分三段處理：0-9、A-Z、a-z，剛好覆蓋 62 進位。
2. 只需要數位總和 sum，不必真的把整個字串轉成十進位大數，可避免溢位。
3. 從 max + 1 起掃描，可大幅減少不必要的基數檢查。

隱藏的小細節：
1. 這題核心是可整除性質，不是進位轉換本身，重點在 sum 與 (N - 1) 的關係。
2. 若輸入含空白或符號，getCharValue 會回傳 -1，程式會自動忽略這些非法字元。
3. 若整行都沒有合法字元，max 會維持 -1，迴圈會從 N = 0 開始；
    在本題合法輸入下通常不會發生，但這是邊界行為要注意。
4. 最小合法 base 其實至少為 2；目前程式維持原邏輯不改動，只補註解說明。
*/

/* 將單一字元轉為對應數值；非法字元回傳 -1 */
int getCharValue(char a)
{
    if(a >= '0' && a <= '9')
    {
        return a - '0';
    }
    if (a >= 'A' && a <= 'Z')
    {
        return a - 'A' + 10;
    }
    if(a >= 'a' && a <= 'z')
    {
        return a - 'a' + 36;
    }

    return -1;
}

int main()
{
    /* 讀入每一行待判斷字串 */
    char input[2000];

    /* 逐行處理直到 EOF */
    while(fgets(input, sizeof(input), stdin) != NULL)
    {
        /* 移除行尾換行字元 */
        input[strcspn(input, "\n")] = '\0';

        /* max: 目前最大位值, sum: 位值總和, trigger: 是否找到答案 */
        int max = -1, sum = 0, trigger = 0;

        /* 掃描每個字元，統計合法位值 */
        for(int i = 0; input[i] != '\0'; i++)
        {
            int value = getCharValue(input[i]);

            /* 排除非法字元 */
            if(value != -1)
            {
                if(value > max)
                {
                    max = value;
                }

                sum += value;
            }
        }

        /*
         * 嘗試最小可行基數：N 至少要大於 max
         * 若 sum % (N - 1) == 0，代表此 N 可行
         */
        int start_N = (max < 2) ? 2 : max + 1;
        for(int N = start_N; N <= 62; N++)
        {
            if(sum % (N - 1) == 0)
            {
                printf("%d\n", N);
                trigger = 1;
                break;
            }
        }

        if(!trigger)
        {
            printf("such number is impossible!\n");
        }
    }
    return 0;
}
