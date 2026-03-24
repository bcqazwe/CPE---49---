#include <stdio.h>
#include <stdlib.h>

/*
 * 將平面座標 (x, y) 映射到題目路徑上的一維序號。
 * 公式：
 * n = x + y
 * index = n * (n + 1) / 2 + x
 */
long long int loc(long long int x, long long int y)
{
    long long int n = x + y;
    long long int result = n * (n + 1) / 2 + x;

    return result;
}

/*
目標：
給定兩個點 (x1, y1) 與 (x2, y2)，求在題目指定編號路徑中，
從前者走到後者需要的步數（即兩點對應序號差）。

解法：
1. 將每個座標映射成路徑上的序號 index。
2. 兩點步數 = index2 - index1。
3. 依題目格式輸出每個測資的答案。

技巧：
1. 路徑可按對角線分層，層號為 n = x + y。
2. 每層起始位置可由三角形數 T(n) = n(n+1)/2 得到。
3. 用 long long 儲存，避免 n(n+1) 在整數乘法時溢位。

隱藏的小細節：
1. 這題看似是走格子，其實可轉成「序號差」的數學題，複雜度降為 O(1)。
2. index 公式中的 +x 對應同一對角線內的偏移量，不是 +y。
3. 若題目保證第二點在第一點之後，index2-index1 會是非負；
   程式保留通用寫法，直接以差值計算。
4. 使用函式 loc() 把映射邏輯封裝，主程式只負責輸入輸出，閱讀性更好。
*/
int main()
{
    /* x1,y1: 起點座標；x2,y2: 終點座標；time: 測資筆數 */
    int x1, y1, x2, y2, time;

    scanf("%d", &time);

    /* 逐筆處理測資 */
    for(int i = 0; i < time; i++)
    {
        scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

        /* 步數 = 終點序號 - 起點序號 */
        long long int step = loc(x2, y2) - loc(x1, y1);
        printf("Case %d: %lld\n", i + 1, step);
    }
    return 0;
}