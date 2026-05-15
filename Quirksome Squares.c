#include <stdio.h>

/**
 * solve 函數：尋找並輸出指定位數的 Quirksome Squares
 * Quirksome Square 定義：
 * 一個 N 位數的平方數，將其平分為左右兩半後，兩半相加的和再平方，等於原數。
 * 數學性質推導：
 * 令原數為 X，其平方根為 i (i*i = X)。
 * 若 X 為 N 位數，則左右兩半各自為 N/2 位數。
 * 令左半部為 left，右半部為 right，則 X = left * (10^(N/2)) + right。
 * 根據定義：(left + right)^2 = X = i^2
 * 因此：left + right = i
 * 這意味著我們只需要遍歷所有可能的和 i，檢查其平方是否符合條件。
 */
void solve(int digits) 
{
    // 計算拆分位置的權重（例如 digits=4 時，split_num=100）
    int split_num = 1;
    for (int i = 0; i < digits / 2; i++) {
        split_num *= 10;
    }

    // 只需要遍歷到 split_num 即可，因為 (left + right) 的最大值不超過 N/2 位數的最大值
    for (int i = 0; i < split_num; i++) 
    {
        int square = i * i;            // 計算平方值
        int left = square / split_num; // 取得左半部
        int right = square % split_num; // 取得右半部

        // 檢查是否符合 Quirksome 定義：左右相加是否等於平方根 i
        if (left + right == i) 
        {
            // 根據指定位數格式化輸出，不足位數需補 0
            if (digits == 2) 
            {
                printf("%02d\n", square);
            }
            else if (digits == 4) 
            {
                printf("%04d\n", square);
            }
            else if (digits == 6) 
            {
                printf("%06d\n", square);
            }
            else if (digits == 8) 
            {
                printf("%08d\n", square);
            }
        }
    }
}

int main() {
    int digits;
    // 持續讀取位數（通常為 2, 4, 6, 8）
    while (scanf("%d", &digits) != EOF) {
        solve(digits);
    }
    
    return 0;
}