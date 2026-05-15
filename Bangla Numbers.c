#include <stdio.h>

/**
 * bangla 遞迴函數：將數字轉換為孟加拉數字單位系統
 * 單位轉換規則：
 * 1 kuti  = 10,000,000 (一千萬)
 * 1 lakh  = 100,000    (十萬)
 * 1 hajar = 1,000      (一千)
 * 1 shata = 100        (一百)
 */
void bangla(long long n) {
    // 處理 kuti (千萬) 級別，因為數字可能超過千萬，所以需要遞迴處理
    if (n >= 10000000) {
        bangla(n / 10000000);
        printf(" kuti");
        n %= 10000000;
        // 如果餘數為 0，表示後續沒有數位需要處理，直接返回
        if (n == 0) return;
    }
    // 處理 lakh (十萬)
    if (n >= 100000) {
        printf(" %lld lakh", n / 100000);
        n %= 100000;
    }
    // 處理 hajar (千)
    if (n >= 1000) {
        printf(" %lld hajar", n / 1000);
        n %= 1000;
    }
    // 處理 shata (百)
    if (n >= 100) {
        printf(" %lld shata", n / 100);
        n %= 100;
    }
    // 處理剩餘的個位數與十位數
    if (n > 0) {
        printf(" %lld", n);
    }
}

int main()
{
    long long int number;
    int time = 1; // 記錄測試案例序號

    // 持續讀取輸入直到 EOF
    while(scanf("%lld", &number) != EOF)
    {
        // 輸出格式：序號佔 4 格並右對齊，後接點號
        printf("%4d.", time);

        if(number == 0)
        {
            // 如果輸入為 0，特殊處理輸出 0
            printf(" 0");
        }
        else
        {
            // 呼叫遞迴函數處理數字轉換
            bangla(number);
        }
        printf("\n"); // 每組案例結束後換行
        time++;
    }
    return 0;
}