#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

typedef struct 
{
    char alpha;
    int freq;
}letter;

int compare(const void *a, const void *b)
{
    letter *l1 = (letter *)a;
    letter *l2 = (letter *)b;

    if(l1->freq != l2->freq)
    {
        //回傳負數時會交換(此是由大到小)
        return l2->freq - l1->freq;
    }

    //回傳負數時會交換(此是由小到大)
    return l1->alpha - l2->alpha;
}

int main()
{
    int time;
    scanf("%d", &time);

    //移除"\n"
    getchar();

    letter count[26];

    //初始化count[26]結構
    for(int i = 0; i < 26; i++)
    {
        count[i].alpha = i + 'A';
        count[i].freq = 0;
    }

    char input[1000];
    while(time--)
    {
        fgets(input, sizeof(input), stdin);

        //移除"\n"
        input[strcspn(input, "\n")] = '\0';

        for(int i = 0; input[i] != '\0'; i++)
        {
            if(isalpha(input[i]))
            {
                count[toupper(input[i]) - 'A'].freq++;
            }

            
        }
    }

    
    qsort(count, 26, sizeof(letter), compare);
    for(int i = 0; i < 26; i++)
    {
        if(count[i].freq != 0)
        {
            printf("%c %d\n", count[i].alpha, count[i].freq);
        }
    }
    
    return 0;
}