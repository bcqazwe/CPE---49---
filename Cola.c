#include <stdio.h>
#include <stdlib.h>

/*
目標：
給定一開始擁有的可樂瓶數（同時也是可喝到的可樂數），
在規則「3 個空瓶可換 1 瓶可樂」下，計算最多總共能喝到幾瓶可樂。

解法：
1. total 先設為初始 bottle，代表一開始就能喝到這些可樂。
2. left 代表目前手上的空瓶數。
3. 當 left >= 3 時可繼續兌換：
   - 喝到 1 瓶新可樂，total++
   - 空瓶數更新為 left = left - 3 + 1（拿 3 空瓶換 1 瓶，喝完再得到 1 空瓶）
4. 若最後 left == 2，可向朋友借 1 空瓶再換 1 瓶，因此 total 還可再 +1。

技巧：
1. 直接用模擬法可清楚反映題目流程，實作簡單且不易出錯。
2. 將兌換過程濃縮成 left = left - 3 + 1，可避免多餘變數。
3. left == 2 的特判是本題關鍵，代表可借瓶完成最後一次兌換。
*/
int main()
{
    /* bottle: 初始可樂瓶數 */
    int bottle;

    /* 讀到 EOF 為止，每筆輸入獨立計算 */
    while(scanf("%d", &bottle) != EOF)
    {
        /* total: 最終可喝到的總瓶數 */
        int total = bottle;

        /* left: 目前可用來兌換的空瓶數 */
        int left = bottle;

        /* 只要空瓶至少 3 個，就可再換 1 瓶 */
        while(left >2)
        {
            total++;
            left = left - 3 + 1;
        }

        /* 剩 2 個空瓶時，可借 1 個再換最後 1 瓶 */
        if(left == 2)
        {
            total++;
        }

        printf("%d\n", total);
    }
    return 0;
}