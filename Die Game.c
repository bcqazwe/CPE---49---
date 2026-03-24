#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
目標：
模擬骰子在平面上依照指令（north、south、east、west）滾動後，
輸出最後朝上的點數。

解法：
1. 用結構體記錄骰子的六個面（top、bottom、north、south、east、west）。
2. 每次讀到一個方向指令，就依該方向更新對應四個面的數值輪替。
3. 所有指令執行完後，輸出 top 即可。

技巧：
1. 把六個面都命名清楚，可直接用「面與面之間的對應關係」更新狀態。
2. 旋轉時先用暫存變數 temp 保存其中一個面，避免覆蓋掉尚未使用的值。
3. 每筆測資開始前都重設為初始狀態（上1、北2、西3、東4、南5、下6）。
*/
typedef struct
{
    /* 骰子六個方向的面值 */
    int top;
    int north;
    int west;
    int east;
    int south;
    int bottom;
}Dice;

int main()
{
    /* count: 本筆測資的移動次數 */
    int count;
    /* 紀錄骰子目前狀態 */
    Dice dice;

    /* 讀到 0 結束 */
    while(scanf("%d", &count) && count != 0)
    {
        /* 每筆測資先重設骰子初始朝向 */
        dice.top = 1;
        dice.north = 2;
        dice.west = 3;
        dice.east = 4;
        dice.south = 5;
        dice.bottom = 6;
        
        /* move: 移動方向字串, temp: 旋轉時的暫存值 */
        char move[10];
        int temp;

        /* 依序執行每一次滾動指令 */
        for(int i = 0; i < count; i++)
        {
            scanf("%s", move);

            if(strcmp(move, "north") == 0)
            {
                /* 向北滾：north -> bottom -> south -> top -> north */
                temp = dice.north;
                dice.north = dice.top;
                dice.top = dice.south;
                dice.south = dice.bottom;
                dice.bottom = temp;
            }
            else if(strcmp(move, "south") == 0)
            {
                /* 向南滾：south -> bottom -> north -> top -> south */
                temp = dice.south;
                dice.south = dice.top;
                dice.top = dice.north;
                dice.north = dice.bottom;
                dice.bottom = temp;
            }
            else if(strcmp(move, "east") == 0)
            {
                /* 向東滾：east -> bottom -> west -> top -> east */
                temp = dice.east;
                dice.east = dice.top;
                dice.top = dice.west;
                dice.west = dice.bottom;
                dice.bottom = temp;
            }
            else if(strcmp(move, "west") == 0)
            {
                /* 向西滾：west -> bottom -> east -> top -> west */
                temp = dice.west;
                dice.west = dice.top;
                dice.top = dice.east;
                dice.east = dice.bottom;
                dice.bottom = temp;
            }
        }
        

        /* 輸出最後朝上的面值 */
        printf("%d\n", dice.top);
    }
    return 0;
}