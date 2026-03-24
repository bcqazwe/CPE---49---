#include <stdio.h>
#include <stdlib.h>

/* 方向索引對應字元：0=N, 1=E, 2=S, 3=W */
char dir_char[] = {'N', 'E', 'S', 'W'};
/* 各方向在 x 軸的位移 */
int dx[] = {0, 1, 0, -1};
/* 各方向在 y 軸的位移 */
int dy[] = {1, 0, -1, 0};

/*
目標：
在給定的矩形地圖上模擬多台機器人的移動，輸出每台機器人的最終位置與朝向；
若機器人因向外移動而掉出地圖，需標記為 LOST。

解法：
1. 先讀入地圖右上角座標 (max_x, max_y)。
2. 對每台機器人讀入初始位置與朝向，再逐步執行指令字串：
   - L：左轉 90 度
   - R：右轉 90 度
   - F：朝目前方向前進一格
3. 若 F 會讓機器人離開地圖：
   - 若當前格子沒有 scent（氣味），則機器人 LOST，並在該格留下 scent。
   - 若當前格子已有 scent，忽略這次 F 指令（避免重複掉落）。
4. 每台機器人輸出最終狀態，若掉落則在行尾加上 LOST。

技巧：
1. 用方向索引 0~3 搭配 dx/dy 可簡化轉向與移動。
2. 以 (direction + 3) % 4 與 (direction + 1) % 4 快速處理左轉/右轉。
3. scent 陣列只記錄會導致掉落的邊界格，可有效避免重複 LOST。
*/
int main()
{
    /* 地圖右上角座標 */
    int max_x, max_y;
    /* 目前機器人的位置與朝向字元 */
    int x, y;
    char dir;

    /* 讀入地圖大小 */
    scanf("%d %d", &max_x, &max_y);

    /* scent[x][y] = 1 代表該格有「掉落氣味」 */
    int scent[max_x + 1][max_y + 1];

    /* 初始化所有格子都沒有氣味 */
    for(int i = 0; i < max_x + 1; i++)
    {
        for(int j = 0; j < max_y + 1; j++)
        {
            scent[i][j] = 0;
        }
    }


    /* 逐台機器人處理，直到 EOF */
    while(scanf("%d %d %c", &x, &y, &dir) != EOF)
    {
        /* 將朝向字元轉為方向索引 */
        int direction;

        switch (dir)
        {
        case 'N':
            direction = 0;
            break;
        case 'E':
            direction = 1;
            break;
        case 'S':
            direction = 2;
            break;
        case 'W':
            direction = 3;
            break;            
        
        default:
            break;
        }

        /* lost = 1 表示此機器人已掉落 */
        int lost = 0;

        /* 讀入該機器人的指令字串 */
        char input[120];
        scanf("%s", input);

        /* 逐字元執行指令 */
        for(int i = 0; input[i] != '\0'; i++)
        {

            if(input[i] == 'L')
            {
                /* 左轉 90 度 */
                direction = (direction + 3) % 4;
            }
            else if(input[i] == 'R')
            {
                /* 右轉 90 度 */
                direction = (direction + 1) % 4;
            }
            else
            {
                /* F：嘗試前進一格 */
                int next_x = x + dx[direction];
                int next_y = y + dy[direction];

                /* 若前進後超出地圖範圍 */
                if(next_x < 0 || next_x > max_x || next_y < 0 || next_y > max_y)
                {
                    /* 該格沒有氣味才會掉落，否則忽略這次前進 */
                    if(!scent[x][y])
                    {
                        lost = 1;
                        scent[x][y] = 1;
                        break;
                    }
                }
                else
                {
                    /* 在地圖內，正常前進 */
                    x = next_x;
                    y = next_y;
                }
            }
        }

        /* 輸出最終位置與方向 */
        printf("%d %d %c", x, y, dir_char[direction]);

        if(lost)
        {
            printf(" LOST\n");
        }
        else
        {
            printf("\n");
        }

    }
}