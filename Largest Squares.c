#include <stdio.h>
#include <stdlib.h>

/*
目標：
給定一個字元矩陣，對每個指定的中心點，找出以該點為中心、且所有元素都相同的最大奇數邊長正方形。

解法：
先讀入整個字元矩陣。對每個查詢點 (x, y)，以 square[x][y] 作為中心字元，從半徑 0 開始，
每次嘗試向外擴張 1 格，檢查新形成的正方形是否仍全部為相同字元；若超出邊界或遇到不同字元，
就停止擴張，最後輸出邊長 2 * 半徑 + 1。

技巧：
1. 題目要求的正方形中心固定，因此只需要逐步擴張，不必枚舉所有子矩陣。
2. 邊長一定是奇數，可用半徑 rad 來表示目前正方形大小。
3. 每次擴張前先做邊界檢查，可以避免存取陣列越界。
*/
int main()
{
    /* 測資組數 */
    int times;

    scanf("%d", &times);
    while(times--)
    {
        int row, col, center, x, y;
        

        scanf("%d %d %d", &row, &col, &center);

        /* 儲存整個字元矩陣 */
        char square[row][col];

        for(int i = 0; i < row; i++)
        {
            for(int j = 0; j < col; j++)
            {
                /* 前面的空白可略過換行與空格 */
                scanf(" %c", &square[i][j]);
            }
        }

        /* 題目要求先原樣輸出 row、col、center */
        printf("%d %d %d\n", row, col, center);

        for(int k = 0; k < center; k++)
        {
            /*
             * rad 表示目前可成立正方形的半徑
             * isTheSame 用來記錄擴張後是否仍全部相同
             */
            int rad = 0,  isTheSame = 1;
            scanf("%d %d", &x, &y);

            /* 以查詢點的字元作為比對基準 */
            char centerChar = square[x][y];

            while(1)
            {
                /* 嘗試往外再擴一圈 */
                int nextRad = rad + 1;

                /* 若新正方形超出邊界，就不能再擴張 */
                if(x - nextRad < 0 || x + nextRad >= row || y - nextRad < 0 || y + nextRad >= col)
                {
                    break;
                }

                /* 檢查擴張後整個正方形是否都與中心字元相同 */
                for(int i = x - nextRad; i <= x + nextRad; i++)
                {
                    for(int j = y - nextRad; j <= y + nextRad; j++)
                    {
                        if(square[i][j] != centerChar)
                        {
                            isTheSame = 0;
                        }
                    }

                    if(!isTheSame)
                    {
                        break;
                    }
                }

                if(!isTheSame)
                {
                    break;
                }
                else
                {
                    /* 這一圈合法，更新目前半徑 */
                    rad = nextRad;
                }
            }

            /* 奇數邊長 = 2 * 半徑 + 1 */
            printf("%d\n", 2 * rad + 1);

        }

    }
    return 0;
}