#include <stdio.h>
#include <stdlib.h>

/*
目標：
讀入多組踩地雷棋盤，對每個非地雷格子輸出其周圍 8 個方向的地雷數量；
若該格本身是地雷，則直接輸出 '*'。

解法：
1. 反覆讀入 row、col，直到遇到 0 0 結束。
2. 讀入整個棋盤字元陣列（'*' 代表地雷，'.' 代表空格）。
3. 逐格處理：
   - 若是地雷，輸出 '*'
   - 若是空格，檢查八個鄰居座標，統計地雷數量後輸出數字。
4. 依題目格式輸出 Field 編號，且不同測資間需空一行。

技巧：
1. 以 dx/dy 兩個陣列統一管理 8 個方向，程式更簡潔。
2. 檢查鄰居時先判斷邊界，避免陣列越界。
3. 用 fieldCount 控制輸出格式，確保多筆資料的空行位置正確。
*/
int main()
{
    /* row/col: 棋盤尺寸，fieldCount: 測資編號（從 1 開始） */
    int row, col, fieldCount = 1;

    /* 讀到 0 0 為止 */
    while (scanf("%d %d", &row, &col) && row != 0 && col != 0)
    {
        /* 儲存原始棋盤 */
        char array[row][col];

        /* 讀入每個格子的字元（'*' 或 '.'） */
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                scanf(" %c", &array[i][j]);
            }
        }

        /* 不同測資之間需要空一行 */
        if (fieldCount > 1)
        {
            printf("\n");
        }

        /* 輸出測資標頭 */
        printf("Field #%d:\n", fieldCount++);

        /* 八方向位移 */
        int dx[] = {-1, -1, -1,  0, 0,  1, 1, 1};
        int dy[] = {-1,  0,  1, -1, 1, -1, 0, 1};
        int next_x, next_y;

        /* 逐格產生答案棋盤並直接輸出 */
        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                /* 地雷格保持 '*' */
                if(array[i][j] == '*')
                {
                    printf("*");
                }
                else
                {
                    /* 統計周圍 8 格的地雷數 */
                    int count = 0;
                    for(int k = 0; k < 8; k++)
                    {
                        next_x = i + dx[k];
                        next_y = j + dy[k];

                        /* 先判斷是否在棋盤範圍內 */
                        if (next_x >= 0 && next_x < row && next_y >= 0 && next_y < col) 
                        {
                            if (array[next_x][next_y] == '*') 
                            {
                                count++;
                            }
                        }
                    }
                    printf("%d", count);
                }
            }
            printf("\n");
        }
    }
    
    return 0;
}