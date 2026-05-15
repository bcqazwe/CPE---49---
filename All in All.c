#include <stdio.h>
#include <stdbool.h>
#include <string.h>

bool isSubsequence(char *t, char *s)
{
	//大字串指標 
    int i = 0;
    //子序列指標 
    int j = 0;
    // 大字串長度 
    int m = strlen(t);
    // 子序列長度 
    int n = strlen(s);
    
    while(i < m && j < n)
    {
    	//若找到子序列往下 
    	if(t[i] == s[j])
    	{
    		j++;
		}
		//每次檢查大字串都往後一位，因為要順序相同 
		i++;
	}
	
	return j == n;
}

int main()
{
	//s = 子序列 
    char s[2000], t[2000];
    
    while(scanf("%s %s", s, t) != EOF)
    {
    	if(isSubsequence(t, s))
    	{
    		printf("Yes\n");
		}
		else
		{
			printf("No\n");
		}
	}

    return 0;
}
