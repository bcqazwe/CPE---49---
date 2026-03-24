#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char string[1000];

    //計算奇偶數
    int index = 0;

    while(fgets(string, sizeof(string), stdin) != NULL)
    {
        //移除換行符
        string[strcspn(string, "\n")] = '\0';
        
        for(int i = 0; string[i] != '\0'; i++)
        {
            if(string[i] == '\"')
            {
                index++;
                if(index % 2 != 0)
                {
                    printf("``");
                }
                else
                {
                    printf("''");
                }
            }
            else
            {
                printf("%c", string[i]);
            }
        }
        printf("\n");
    }
    return 0;
}