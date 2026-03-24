#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
 * 以遞迴實作歐幾里得演算法（Euclidean Algorithm）
 * 回傳 a 與 b 的最大公因數。
 */
int GCD(int a, int b)
{
    if(b == 0)
    {
        return a;
    }

    return GCD(b, a % b);
}

/*
 * 將二進位字串轉為十進位整數
 * 由最低位（字串尾端）往前累加：sum += bit * 2^k
 */
int binary2Dec(char *number, int length)
{
    int mult = 1, sum = 0;

    /* 每往前一位，權重乘以 2 */
    for(int i = length - 1; i >= 0; i--)
    {
        sum += (number[i] - '0') * mult;
        mult *= 2;
    }

    return sum;
}

/*
目標：
給定兩個二進位字串，判斷它們轉成十進位後是否有大於 1 的公因數。
若 GCD > 1，輸出 "All you need is love!"；否則輸出 "Love is not all you need!"。

解法：
1. 讀入兩個二進位字串。
2. 先把兩字串轉成十進位整數。
3. 以歐幾里得演算法計算兩數的最大公因數 GCD。
4. 根據 GCD 是否為 1 決定輸出訊息。

技巧：
1. 二進位輸入使用字串接收，處理位元操作更直觀。
2. 轉換時由字串尾端往前掃描，可直接用權重 mult（1,2,4,8...）累加。
3. GCD 使用遞迴公式 gcd(a,b)=gcd(b,a%b)，程式短且效率高。

隱藏的小細節：
1. 題目關鍵不是比較字串本身，而是比較「轉成十進位後」的共同因數。
2. 若其中一個數為 0，GCD(0, x) 會是 x；目前判斷規則仍適用。
3. 這份程式使用 int 儲存十進位結果，若二進位字串過長可能溢位；
   在 UVA 本題常見資料範圍通常可通過，但若要更保險可改用 long long。
4. 輸出格式中的 Pair 編號從 1 開始，且大小寫與驚嘆號都要完全一致。
*/
int main()
{
    /* 測資筆數 */
    int time;
    /* 兩個二進位字串 */
    char num1[40], num2[40];

    scanf("%d", &time);

    for(int i = 0; i < time; i++)
    {
        /* 讀入兩個二進位字串 */
        scanf("%s", num1);
        scanf("%s", num2);

        /* 先轉十進位，再計算最大公因數 */
        int result = GCD(binary2Dec(num1, strlen(num1)), binary2Dec(num2, strlen(num2)));

        /* 依題目指定格式輸出 */
        printf("Pair #%d: ", i + 1);

        /* 若 GCD 為 1，代表互質，則不是 all you need */
        if(result == 1)
        {
            printf("Love is not all you need!\n");
        }
        else
        {
            printf("All you need is love!\n");
        }
    }
    return 0;
}