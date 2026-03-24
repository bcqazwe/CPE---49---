#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
目標：
給定兩個字串，找出兩者共同擁有的字母，並按字母順序輸出。
若某字母在兩字串中出現次數不同，則輸出該字母出現次數較少的那個數量。

解法：
1. 讀入兩個字串（忽略大小寫）。
2. 分別計算兩字串中各個字母的出現頻率。
3. 逐字母檢查：若兩字串都有此字母，輸出該字母「最小頻率」次。
4. 字母按 a-z 順序摛述，自動保證輸出的字母順序。

技巧：
1. 使用 tolower() 統一轉小寫，簡化大小寫比較。
2. 用頻率陣列 freq[26] 記錄 26 個英文字母，空間效率高。
3. 直接摛述 a-z，無需排序，輸出順序已正確。

隱藏的小細節：
1. 使用 fgets() 可安全處理包含空格的輸入字串。
2. 需用 strcspn() 移除換行字元，避免計算到 '\n'。
3. 程式邏輯可簡化：三個 if-else-if 分支都輸出 min(freq1[i], freq2[i]) 次，
   其實住可以用 min() 函數直接簡化。
4. 無需檢查非字母字元（題目保證只有字母），tolower() 對非字母的行為不影響結果。
*/
int main()
{
    /* 存放兩個輸入字串 */
    char string1[1100], string2[1100];
    
    /* fgets 可讀取包含空格的字串，直到遇到 EOF */
    while(fgets(string1, sizeof(string1), stdin) != NULL && fgets(string2, sizeof(string2), stdin) != NULL)
    {

        /* 移除 fgets 讀進來的換行字元 */
        string1[strcspn(string1, "\n")] = '\0';
        string2[strcspn(string2, "\n")] = '\0';

        /* 分別計算兩字串的字母頻率 */
        int freq1[26] = {0}, freq2[26] = {0};

        /* 摛述第一個字串，統計各字母出現次數 */
        for(int i = 0; string1[i] != '\0'; i++)
        {
            /* tolower 轉小寫之後，計算該字母索引 */
            freq1[tolower(string1[i]) - 'a']++;
        }

        /* 摛述第二個字串，統計各字母出現次數 */
        for(int i = 0; string2[i] != '\0'; i++)
        {
            freq2[tolower(string2[i]) - 'a']++;
        }

        /* 逐字母輸出共同字母，使用兩者頻率的最小值 */
        for(int i = 0; i < 26; i++)
        {
            /* 若兩字串都包含此字母，才輸出 */
            if(freq1[i] > 0 && freq2[i] > 0 )
            {
                /* 計算應輸出該字母的次數（取雙方頻率中較小者） */
                if(freq1[i] > freq2[i])
                {
                    /* freq2[i] 較小 */
                    for(int j = 0; j < freq2[i]; j++)
                    {
                        printf("%c", i + 'a');
                    }
                }
                else if(freq1[i] < freq2[i])
                {
                    /* freq1[i] 較小 */
                    for(int j = 0; j < freq1[i]; j++)
                    {
                        printf("%c", i + 'a');
                    }
                }
                else
                {
                    /* 兩者相等 */
                    for(int j = 0; j < freq1[i]; j++)
                    {
                        printf("%c", i + 'a');
                    }
                }
                
            }
        }
        printf("\n");
    }
    return 0;
}