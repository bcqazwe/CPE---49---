#include <stdio.h>
#include <stdlib.h>

//這裡從0開始，所以偶數位為奇
int isMultipleOf11(char *array)
{
    int odd = 0, even = 0;
    for(int i = 0; array[i] != '\0'; i++)
    {
        if(i % 2 == 0)
        {
            odd += array[i] - '0';
        }
        else
        {
            even += array[i] - '0';
        }
    }

    return abs(odd - even) % 11 == 0;
}

int main()
{
    char input[1100] = {0};

    while(1)
    {
        scanf("%s", input);
        //使用Strcmp比較，單純使用input[0] == '0'可能使"0123"無法計算
        if(strcmp(input, "0") == 0)
        {
            break;
        }
        
        if(isMultipleOf11(input))
        {
            printf("%s is a multiple of 11.\n", input);
        }
        else
        {
            printf("%s is not a multiple of 11.\n", input);
        }
    }
}
