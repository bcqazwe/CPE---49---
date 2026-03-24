#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//自訂義compare(若是int, floaty要多加一層*)
int compare(const void *a, const void *b)
{
    return strcmp((char *)a, (char *)b);
}

int main()
{
    int time;
    scanf("%d", &time);

    //國家陣列(最多2000個，每個最多75字)
    char countries[2000][75];

    //用於抹去後面多於文字
    char dummy[100];

    //處理輸入
    for(int i = 0; i < time; i++)
    {
        scanf("%s", countries[i]);
        fgets(dummy, sizeof(dummy), stdin);
    }

    //使用qsort(陣列, 元素總數, 元素大小, 排序法)
    qsort(countries, time, 75 * sizeof(char), compare);

    //預設國家出現次數為1
    int count = 1;

    //處理比較
    for(int i = 0; i < time; i++)
    {

        //i + 1 < time防止錯誤存取，相鄰2個國家名稱是否相同
        if(i + 1 < time && strcmp(countries[i], countries[i + 1]) == 0)
        {
            count++;
        }
        else
        {
            printf("%s %d\n", countries[i], count);
            
            //重置國家出現次數為1
            count = 1;
        }
    }
    return 0;
}