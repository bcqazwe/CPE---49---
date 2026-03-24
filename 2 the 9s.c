#include <stdio.h>
#include <stdlib.h>

/*
 * 將字串形式的大整數做「各位數字總和」
 * 這樣可避免整數溢位（輸入可能非常長）。
 */
int getDigitSumByArray(char *input)
{
    int sum = 0;
    for(int i = 0; input[i] != '\0'; i++)
    {
        sum += input[i] - '0';
    }

    return sum;
}

/* 將一般整數做「各位數字總和」 */
int getDigitSumByInt(int number)
{
    int sum = 0;
    while(number > 0)
    {
        sum += number % 10;
        number /= 10;
    }

    return sum;
}

/*
目標：
讀入一個十進位整數字串（以 0 結束輸入），判斷是否為 9 的倍數；
若是，輸出其 9-degree（反覆做數字和直到變成 9 的次數層級）。

解法：
1. 先用字串逐位加總，得到第一層數字和 sum。
2. 若 sum 不能被 9 整除，直接輸出不是 9 的倍數。
3. 若可被 9 整除，degree 先設為 1（代表第一層已成立）。
4. 當 sum > 9 時，反覆把 sum 取數字和，並把 degree++。
5. 最後輸出 9-degree。

技巧：
1. 第一輪用字串計算，能安全處理超過 int 範圍的大數。
2. 後續 sum 值很小（最多幾位數加總），改用整數函式處理更快。
3. 以 sum % 9 == 0 先做快篩，可避免不必要的迭代。

隱藏的小細節：
1. 這題的終止條件是「整行只有 0」，程式用 input[0] == '0' 判斷。
2. 9-degree 的起點是 1，不是 0；因為第一層數字和已經算過一次。
3. while(sum > 9) 而不是 >= 9，避免在 sum == 9 時多加一次 degree。
4. 若輸入是 9，本題答案是 degree = 1，這是常見邊界測資。
*/
int main()
{
    /* 以字串讀入大整數（避免溢位） */
    char input[1100];
    /* 記錄 9-degree */
    int degree;

    /* 反覆讀入直到遇到單獨的 0 */
    while(1)
    {
        scanf("%s", input);
        if(input[0] == '0')
        {
            break;
        }

        /* 第一次以字串計算各位數字總和 */
        int sum = getDigitSumByArray(input);

        /* 非 9 的倍數可直接輸出 */
        if(sum % 9 != 0)
        {
            printf("%s is not a multiple of 9.\n", input);
            continue;
        }

        /* 已確認是 9 的倍數，第一層 degree 為 1 */
        degree = 1;

        /* 持續壓縮成數字和，直到剩下一位數 */
        while(sum > 9)
        {
            degree++;
            sum = getDigitSumByInt(sum);
        }

        printf("%s is a multiple of 9 and has 9-degree %d.\n", input, degree);
    }
    return 0;
}