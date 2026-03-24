#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//固定查表
char keyboardMap[48] = "`1234567890-=qwertyuiop[]\\asdfghjkl;'zxcvbnm,./";
int main()
{
    char input[1000];
    
    //輸入直到NULL
    while(fgets(input, sizeof(input), stdin) != NULL)
    {

        //移除換行符
        input[strcspn(input, "\n")] = '\0';

        for(int i = 0; input[i] != '\0'; i++)
        {

            //額外處理空格
            if(input[i] == ' ')
            {
                printf(" ");
                continue;
            }

            //輸出前2格鍵盤位置
            for(int j = 0; j < 47; j++)
            {
                if(input[i] == keyboardMap[j])
                {
                    printf("%c", keyboardMap[j - 2]);
                }
            }
        }
        printf("\n");
    }
    return 0;
}