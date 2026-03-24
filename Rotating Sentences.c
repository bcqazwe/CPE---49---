#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[110][110];
    int line = 0;
    int maxLength = -1;
    
    while(fgets(string[line], sizeof(string[line]), stdin) != NULL)
    {

        //移除換行符
        string[line][strcspn(string[line], "\n")] = '\0';

        //計算最大字串長度
        if((int)strlen(string[line]) > maxLength)
        {
            maxLength = strlen(string[line]);
        }
        line++;
    }

    //將長度不足的字串補齊' '
    for(int i = 0; i < line; i++)
    {
        int index = 0;
        while(string[i][index] != '\0')
        {
            index++;
        }
        for(;index < maxLength; index++)
        {
            string[i][index] = ' ';
        }

        //記得補上'\0'
        string[i][maxLength] = '\0';
    }

    //先由下往上輸出，再由左至右
    for(int i = 0; i < maxLength; i++)
    {
        for(int j = line - 1; j >= 0; j--)
        {
            printf("%c", string[j][i]);
        }
        printf("\n");
    }
    return 0;
}