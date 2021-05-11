# include <stdio.h>
# include <string.h>
int main()
{
	char arr[1000001];
	int i,j;
	int alpha[26]={0,};
	int m = 0;
	char c = '?';
	scanf("%s",arr);
	
	for(i = 0; arr[i]!='\0'; i++)
	{
		if(arr[i] >='a')
			arr[i] -=32;
		alpha[arr[i]-65]++;
	}
	
	for(i = 0; i<26; i++)
	{
		if(m < alpha[i])
		{
			m = alpha[i];
			c = i;
		}
		else if(m == alpha[i])
		{
			c = '?';
		}
	}
	
	if(c != '?')
	{
		printf("%c",65+c);
	}
	else
	{
		printf("?");
	}
	
	
	return 0;
}
