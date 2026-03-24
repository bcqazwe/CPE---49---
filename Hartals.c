#include <stdio.h>
#include <stdlib.h>

/*
 * 最多模擬 3650 天，且天數從 1 開始編號
 * checkDays[i] 狀態說明：
 * 0  -> 目前尚未標記為罷工日
 * 1  -> 罷工日
 * -1 -> 週五或週六（休假日，不計入罷工）
 */

//最多模擬3650天，且從1開始
int checkDays[3652];

/*
 * 初始化每日狀態：
 * 1. 先清成 0
 * 2. 把每週五（第 6, 13, ... 天）標成 -1
 * 3. 把每週六（第 7, 14, ... 天）標成 -1
 */
void initCheckDays()
{
    //初始化全部
    for(int i = 1; i < 3652; i++)
    {
        checkDays[i] = 0;
    }

    //初始化周五
    for(int i = 6; i <3652; i += 7)
    {
        checkDays[i] = -1;
    }

    //初始化周六
    for(int i = 7; i <3652; i += 7)
    {
        checkDays[i] = -1;
    }

}

/*
目標：
在給定模擬天數內，計算所有政黨造成的總罷工天數（Hartals），
但每週五與週六屬於休假日，不可計入罷工天數。

解法：
1. 用陣列 checkDays 記錄每天狀態。
2. 先把週五、週六標記為不可罷工（-1）。
3. 對每個政黨的罷工週期 h，將 h, 2h, 3h... 的日子標記為罷工（1），
    但若該日是 -1（週五或週六）就跳過。
4. 最後統計所有標記為 1 的天數。

技巧：
1. 以狀態陣列避免重複計數：同一天被多個政黨命中，只會算一次。
2. 先統一初始化休假日，後續只需判斷是否為 -1 即可。
3. 天數從 1 開始編號，能直接對應題目敘述，減少 off-by-one 錯誤。

隱藏的小細節：
1. 週五、週六是固定週期，不受政黨週期影響，必須先排除。
2. 內層迴圈條件使用 j <= days 才能包含最後一天。
3. 即使某天被多次命中，狀態仍維持 1，不會重複累加。
4. 目前變數名稱 groupes 保留原始寫法（拼字常見為 groups），本次僅加註解不改邏輯。
*/
int main()
{
    int time;
    
    scanf("%d", &time);

    /* 逐筆測資處理 */
    while(time--)
    {
        /* 每筆測資都要重新初始化狀態陣列 */
        int days, result = 0;
        initCheckDays();

        /* 讀入模擬天數 */
        scanf("%d", &days);

        int groupes;

        /* 讀入政黨數量 */
        scanf("%d", &groupes);

        /* 逐政黨標記罷工日 */
        for(int i = 0; i < groupes; i++)
        {
            /* 輸入該政黨罷工週期 */
            int value;
            scanf("%d", &value);

            /* 每隔 value 天罷工一次（休假日除外） */
            for(int j = value; j <= days; j += value)
            {
                if(checkDays[j] != -1)
                {
                    checkDays[j] = 1;
                }
            }
        }

        /* 統計罷工總天數 */
        for(int i = 1; i <= days; i++)
        {
            if(checkDays[i] == 1)
            {
                result++;
            }
        }

        /* 輸出答案 */
        printf("%d\n", result);
    }
    return 0;
}