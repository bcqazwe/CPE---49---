#include <stdio.h>
#include <stdlib.h>

/*
目標：
已知兩隊比分總和 sum 與分差 sub，求兩隊各自可能的整數分數。
若不存在非負整數解，輸出 impossible。

解法：
設較高分為 x、較低分為 y，則有：
1. x + y = sum
2. x - y = sub
聯立可得：
   x = (sum + sub) / 2
   y = (sum - sub) / 2
再檢查是否符合非負整數條件，符合就輸出較大者在前。

技巧：
1. 先用公式直接求解，比逐步嘗試配對分數更快。
2. 只要 (sum + sub) 或 (sum - sub) 不是偶數，就不可能得到整數解。
3. 保持輸出順序為大分在前，能符合題目期望格式。

隱藏的小細節：
1. 條件 sum < sub 時必定無解，因為分差不可能大於總分。
2. 即使 sum >= sub，仍要檢查整除 2，否則會得到小數分數。
3. x 或 y 出現負數也要判定 impossible，避免輸出不合理比分。
4. 雖然理論上 x >= y，但程式最後再做一次大小比較輸出，可提高穩健性。
5.使用long long int
*/
int main()
{
    /* 測資筆數 */
    int time;
    scanf("%d", &time);

    /* 逐筆處理 */
    while(time--)
    {
        /* sum: 總分, sub: 分差 */
        long long int sum, sub;

        scanf("%lld %lld", &sum, &sub);

        /* 由聯立方程直接求兩隊分數 */
        long long int x = (sum + sub) / 2;
        long long int y = (sum - sub) / 2;

        /*
         * 兩隊分數 < 0，或無法整除 2（會是小數）都屬於不可能
         * 另外 sum < sub 代表分差大於總分，也是不可能
         */
        if(sum < sub || x < 0 || y < 0 || (sum + sub) % 2 != 0 ||(sum - sub) % 2 != 0)
        {
            printf("impossible\n");
            continue;
        }

        /* 依題目需求輸出較大分數在前 */
        if(x > y)
        {
            printf("%lld %lld\n", x, y);
        }
        else
        {
            printf("%d %d\n", y, x);
        }
        
    }
    return 0;
}
