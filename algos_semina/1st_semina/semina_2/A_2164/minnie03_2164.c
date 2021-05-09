#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main() {
	int q[100] = { 0, };
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++)
		q[i] = i + 1;
	int front = -1;
	int rear=n;
	do{
		++front;
		int p=q[++front];
		q[rear++] = p;
	}while(front+2<rear);

	printf("%d", q[--rear]);
	
	return 0;
}
