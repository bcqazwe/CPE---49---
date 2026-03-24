#include<stdio.h>
#include <stdlib.h>
#define MAX 1000001

/*
此題核心：判斷輸入整數是 not prime、prime 或 emirp。
emirp 定義為：本身是質數、反轉後仍是質數，且反轉值不等於自己。
*/
int isPrime[MAX];

// 反轉數字，例如 123 -> 321
int reverseNum(int number)
{
    int result = 0;
    while(number > 0)
    {
        result = (result * 10) + (number % 10);
        number /= 10;
    }
    return result;
}

// 使用篩法預先標記 0~MAX-1 是否為質數
void initSieve()
{
    // 0 和 1 非質數，其餘先假設為質數
    for(int i = 0; i < MAX; i++)
    {
        if(i == 0 || i == 1)
        {
            isPrime[i] = 0;
        }
        else
        {
            isPrime[i] = 1;
        }
        
    }

    // 從 2 開始，把每個質數的倍數標成非質數
    for(int i = 2; i < MAX; i++)
    {
        if(isPrime[i])
        {
            for(int j = i * 2; j < MAX; j += i)
            {
                isPrime[j] = 0;
            }
        }
    }
}

/*
目標：
對每個輸入整數 n，輸出其分類：
1. n is not prime.
2. n is prime.
3. n is emirp.

解法：
1. 先用埃拉托斯特尼篩法建立 isPrime 陣列，快速查質數。
2. 對每個輸入 n：
   - 若 n 非質數，直接輸出 not prime。
   - 若 n 是質數，計算反轉值 r = reverseNum(n)。
   - 若 r 也是質數且 r != n，輸出 emirp；否則輸出 prime。

技巧：
1. 預處理一次篩表，後續每筆查詢都可 O(1) 判斷質數。
2. 反轉數字用取餘數與整除即可，不需字串轉換。
3. 判斷順序先排除 not prime，可讓邏輯更直觀。

隱藏的小細節：
1. emirp 必須滿足反轉後「不等於原數」，像 11 雖是質數但不是 emirp。
2. 題目輸入範圍需落在篩表上限內，才能直接用 isPrime[index] 查表。
3. reverseNum() 在尾數為 0 時會自然去除前導 0（例如 1010 -> 101）。
*/
int main()
{
    // 建立質數查表
    initSieve();

    // 持續讀到 EOF
    int number;
    while(scanf("%d", &number) != EOF)
    {
        // 本身非質數
        if(isPrime[number] == 0)
        {
            printf("%d is not prime.\n", number);
        }
        // 本身為質數，且反轉後也為質數且不同值 -> emirp
        else if (isPrime[number] == 1 && isPrime[reverseNum(number)] == 1 && number != reverseNum(number))
        {
            printf("%d is emirp.\n", number);
        }
        // 本身為質數，但不符合 emirp
        else if(isPrime[number] == 1)
        {
            printf("%d is prime.\n", number);
        }
    }
    return 0;
}