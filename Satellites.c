#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/* 地球半徑（公里） */
const double R = 6440.0;
double PI;

/*
目標：
給定衛星距地面的高度 s、兩顆衛星之間的夾角 angle（單位可能是度或分），
計算兩顆衛星之間的弧長（arc）與弦長（chord）。

解法：
1. 衛星的軌道半徑 r = 地球半徑 R + 高度 s。
2. 若角度單位為 "min"（角分），先除以 60 換算為度。
3. 若夾角超過 180 度，取其補角（360 - angle），因為兩顆衛星間取較短那段弧。
4. 將度數換算為弧度，再套公式：
   - 弧長 = r * θ（弧度）
   - 弦長 = 2 * r * sin(θ / 2)

技巧：
1. 用 acos(-1.0) 取得精確的 PI 值，避免手動輸入帶來的精度誤差。
2. 角分換算只需在讀入後判斷字串是否為 "min"，處理單位差異非常簡潔。
3. 夾角 > 180 度時取 360 - angle，確保永遠計算較短弧的距離。
*/
int main()
{
    PI = acos(-1.0);
    /* s: 衛星高度（公里）, angle: 兩衛星夾角, string: 角度單位（deg 或 min） */
    double s, angle;
    char string[5];

    /* 持續讀入直到檔案結尾 */
    while(scanf("%lf %lf %s", &s, &angle, string)!= EOF)
    {
        /* 軌道半徑 = 地球半徑 + 衛星高度 */
        double r = R + s;

        /* 若單位為角分，換算成度（1 度 = 60 角分） */
        if (strcmp(string, "min") == 0) 
        {
            angle = angle / 60.0;
        }

        /* 夾角超過 180 度時，改取另一側較短的角 */
        if (angle > 180.0) 
        {
            angle = 360.0 - angle;
        }

        /* 將度數轉換為弧度 */
        double rad = angle * PI / 180;

        /* 弧長 = 半徑 × 弧度 */
        double arc = r * rad;

        /* 弦長 = 2r × sin(θ/2) */
        double chord = 2.0 * r * sin(rad / 2.0);

        printf("%.6f %.6f\n", arc, chord);
    }
    return 0;
}