#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
	char name[20];
	int value;
}word;

int main()
{
	int word_count, cases;
	int i, j, k;
	int value;
	char input[20];
	scanf("%d %d", &word_count, &cases);
	word words[word_count];
	for(i = 0; i < word_count; i++)
	{
		scanf("%s %d", words[i].name, &words[i].value);
	}
	
	for(j = 0; j < cases; j++)
	{
		value = 0;
		scanf("%s", input);
	
		while(strcmp(input, ".") != 0)
		{
			for(i = 0; i < word_count; i++)
			{
				if(strcmp(input, words[i].name) == 0)
				{
					value += words[i].value;
					break;
				}
			}
			scanf("%s", input);
		}
		
		printf("%d\n", value);
	}
	
	return 0;
} 
