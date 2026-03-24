#include <stdio.h>
#include <stdlib.h>

/*
 * 檢查序列是否全部為正數
 */
int isPostive(int *array, int count)
{
	int i;
	for(i = 0; i < count; i++)
	{
		if(array[i] <= 0)
		{
			return 0;
		}
	}
	return 1;
}

/* 檢查序列是否嚴格遞增 */
int isIncrease(int *array, int count)
{
	int i;
	for(i = 0; i < count - 1; i++)
	{
		if(array[i] >= array[i + 1])
		{
			return 0;
		}
	}
	return 1;
}

/*
 * 檢查所有 i <= j 的兩兩和是否皆不重複
 * number[sum] 用來標記某個和是否已經出現過
 */
int isNotRepeat(int *array, int count)
{
	int i, j;
	int number[20001] = {0};
	for(i = 0; i < count; i++)
	{
		for(j = i; j < count; j++)
		{
			int sum = array[i] + array[j];
			if(number[sum] == 1)
			{
				return 0;
			}
			
			number[sum] = 1;
		}
	}
	return 1;
}

/*
目標：
判斷輸入序列是否為 B2-Sequence。
B2-Sequence 需同時滿足：
1. 全部元素皆為正整數
2. 序列嚴格遞增
3. 所有 a[i] + a[j]（其中 i <= j）都互不相同

解法：
1. 先檢查是否全為正數。
2. 再檢查是否嚴格遞增。
3. 最後枚舉所有 i <= j 的配對，計算和並用陣列標記是否重複。
4. 三個條件都成立才輸出是 B2-Sequence。

技巧：
1. 把三個條件拆成三個函式，主程式判斷邏輯會很乾淨。
2. 兩兩和檢查使用「出現表」標記，比兩兩比對所有和更直觀。
3. 只需要檢查 i <= j，可避免重複計算 (i,j) 與 (j,i)。

隱藏的小細節：
1. 題目常見陷阱是把遞增誤寫成非遞減；這題必須是嚴格遞增（不能有相等）。
2. 兩兩和要包含 i == j（例如 a[0] + a[0]），不能漏掉。
3. 輸出格式每筆案例後要空一行，否則容易 Presentation Error。
4. 目前函式名稱 isPostive 是原始命名（拼字較常見寫法為 isPositive），
   這次僅加註解、不改命名，避免影響你既有程式結構。
*/
int main()
{
	/* count: 序列長度, caseNum: 測資編號 */
	int count;
	int i;
	int caseNum = 1;
	
	/* 讀到 EOF 為止 */
	while(scanf("%d", &count) != EOF)
	{
		/* 儲存本筆序列 */
		int value[105] = {0};
		
		/* 讀入 count 個整數 */
		for(i = 0; i < count; i++)
		{
			scanf("%d", &value[i]);
		}
		
		/* 要求全為正數、遞增、相加值不能重複 */
		if(isPostive(value, count) && isIncrease(value, count) && isNotRepeat(value, count))
		{
			printf("Case #%d: It is a B2-Sequence.\n", caseNum);
		}
		else
		{
			printf("Case #%d: It is not a B2-Sequence.\n", caseNum);
		}
		caseNum++;
		printf("\n");
	}
	return 0;
}
