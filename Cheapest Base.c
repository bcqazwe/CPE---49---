#include <stdio.h>
#include <stdlib.h>

/* 和 cost[] 對照的字元表（本解法未直接使用，但保留可讀性） */
char digits[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";

/* 儲存 0~9、A~Z 共 36 個符號的印刷成本 */
int cost[36];

/*
 * 計算 number 在指定 base 下的總印刷成本
 * 作法：反覆取餘數得到每一位，累加該位符號成本
 */
int getCost(int number, int base)
{
    /* 數字 0 在任何進位都表示為單一符號 '0' */
    if(number == 0)
    {
        return cost[0];
    }

    /* 轉換並累計每一位的成本 */
    int total = 0;
    while(number > 0)
    {
        total += cost[number % base];
        number /= base;
    }

    return total;
}

/*
目標：
對每個輸入數字，找出在 base 2 到 base 36 中，表示該數字的「最小總印刷成本」所對應的所有進位。

解法：
1. 先讀入 36 個符號成本（0~9, A~Z）。
2. 對每個查詢數字 n：
   - 枚舉 base = 2..36，利用 getCost(n, base) 計算成本。
   - 第一次枚舉找出最小成本 minCost。
   - 第二次枚舉把成本等於 minCost 的 base 全部標記並輸出。
3. 每個 case 依題目格式輸出。

技巧：
1. 成本只和每一位的符號有關，因此轉進位時「取餘數 + 除 base」即可逐位計算。
2. 先找最小值，再做第二輪收集所有最小 base，實作簡單且不容易漏答案。
3. 針對 number == 0 做特判，可避免 while(number > 0) 不進入造成成本錯誤。

隱藏的小細節：
1. 這題要求輸出「所有」最便宜進位，不是只輸出其中一個。
2. 成本高低與位數不一定正相關：位數雖多，若符號成本低，總成本仍可能更小。
3. 進位範圍固定是 2~36，不需要也不能測試 1 或 37 以上。
4. 若輸入數字是 0，不論進位為何，表示都只有一位 '0'，成本固定為 cost[0]。
*/
int main()
{
    /* time: case 次數，freq: 該 case 的查詢數量 */
    int time, freq;

    /* 先輸入 case 數 */
    scanf("%d", &time);

    /* 最外圈逐個 case 處理 */
    for(int k = 0; k < time; k++)
    {
        /* 輸入 36 個符號成本 */
        for(int i = 0; i < 36; i++)
        {
            scanf("%d", &cost[i]);
        }

        /* 輸入該 case 的查詢數量 */
        scanf("%d", &freq);

        /* 儲存該 case 所有查詢數字 */
        int numbers[freq];

        /* 讀入所有查詢 */
        for(int i = 0; i < freq; i++)
        {
            scanf("%d", &numbers[i]);
        }

        /* 輸出 case 標頭 */
        printf("Case %d:\n", k + 1);

        /* 逐一處理每個查詢數字 */
        for(int i = 0; i < freq; i++)
        {

            /* 每筆查詢先重置最小成本 */
            int minCost = 9999999;

            /* isMins[base] = 1 表示此 base 為最小成本之一 */
            int isMins[37];

            /* 清空標記表（僅使用 2~36） */
            for(int j = 2; j <= 36; j++)
            {
                isMins[j] = 0;
            }

            /* 第一次枚舉：找最小成本 */
            for(int j = 2; j <= 36; j++)
            {
                int cost = getCost(numbers[i], j);
                if(cost < minCost)
                {
                    minCost = cost;
                }
            }

            /* 第二次枚舉：標記所有等於最小成本的 base */
            for(int j = 2; j <= 36; j++)
            {
                if(getCost(numbers[i], j) == minCost)
                {
                    isMins[j] = 1;
                }
            }

            /* 輸出所有最便宜進位 */
            printf("Cheapest base(s) for number %d:", numbers[i]);
            for(int j = 2; j <= 36; j++)
            {
                if(isMins[j] == 1)
                {
                    printf(" %d", j);
                }
            }
            printf("\n");
        }

        /* 每個 case 後補空行（配合題目輸出格式） */
        if(k < time)
        {
            printf("\n");
        }

    }
    return 0;
}