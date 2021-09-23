#include <stdio.h>
#include <string.h>

int main()

{
	char arr[100] = {};
	scanf("%s", &arr);
	int num[26] = {};

	for (int i = 0; i < strlen(arr); i++)
	{
		num[arr[i] - 'a']++;
	}
	for (int i = 0; i < 26; i++)
	{
		printf("%d ", num[i]);
	}

}
