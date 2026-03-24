#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
題目目標：
給定 x 與多項式係數，輸出該多項式在 x 的導數值 P'(x)。

解題方法：
1. 讀入 x 與一整行係數 a0 a1 ... an（由高次到常數項）。
2. 導數係數為 ai * (n - i)，因此常數項不用計算。
3. 使用 Horner 形式累積：result = result * x + 當前導數係數。

技巧：
- 係數行用 fgets 讀入，再用 strtok 切割字串，避免逐項 scanf 的格式問題。
- 以 long long 儲存，降低大數運算時溢位風險。
- 單次迴圈同時完成「導數轉換 + 代入 x」，時間複雜度為 O(n)。

隱藏小細節：
- 當原多項式只有常數項時，導數為 0；此程式因 for 迴圈不會執行，result 會保持 0，剛好正確。
- 係數輸入可能有正負號，使用 atoll 轉型可直接處理，不需額外判斷符號。
- 讀完 x 後先用 getchar() 吃掉換行，避免下一次 fgets 讀到空字串。
*/

int main()
{
    long long int x;

    //輸入X的值
    while(scanf("%lld", &x) != EOF)
    {
        //吃掉緩衝區的"\n"
        getchar();

        //輸入多項式的係數並移除換行符(使用char陣列)
        char input[5000];
        long long int coef[2000], count = 0;
        fgets(input, sizeof(input), stdin);
        input[strcspn(input, "\n")] = '\0';

        //將字串以' '切割提取出來
        char *string = strtok(input, " ");

        //重複提取數字加入coef陣列
        while(string != NULL)
        {
            long long int value = atoll(string);
            coef[count++] = value;

            //第二次以後的strtok要傳入NULL
            string = strtok(NULL, " ");
        }

        //最高項的次方數(前面結束前多算一次)
        int degree = count - 1;
        long long int result = 0;

        //少跑一次因為最後為常數項
        for(int i = 0; i < count - 1; i++)
        {
            //先將結果 * x，再加上當前x係數 * 次方數
            result = result * x + coef[i] * (degree - i);
        }
        printf("%lld\n", result);


    }
    
    return 0;
}