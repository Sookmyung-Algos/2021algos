#include <stdio.h>

void sort(int *N, int len) // 정렬을 위한 함수
{
	int i, j;
	int temp;
	for (i = 0; i < len; i++)
	{
		for (j = 0; j <len - (i + 1); j++)
		{
			if (N[j] > N[j + 1]) // 만약 앞의 값이 더 크다면
			{
				temp = N[j]; 
				N[j] = N[j + 1];
				N[j + 1] = temp;
				// temp를 이용해서 두 수의 자리 바꿔주기
			}
		}
	}
}

int main() {
	int N;
	int arr[1001];
	int sum = 0, sum2 = 0;

	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d", &arr[i]); 
	}
	sort(arr, N); // 입력받은 시간 배열 정렬하기
	for (int i = 0; i < N; i++) {
		sum += arr[i]; // 그 때의 원소 값을 더해주고
		sum2 += sum; // 그 값을 다시 sum2에 더해서 총 시간 계산해주기
	}
	printf("%d\n", sum2);
}
