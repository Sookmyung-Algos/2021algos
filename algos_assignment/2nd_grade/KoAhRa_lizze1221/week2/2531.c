#include <stdio.h>
#include <string.h>

int arr[33333]; // 초밥 정보가 담긴 배열
int slide[3333]; // k개 안에 같은 종류의 초밥의 개수 세기 위한 배열

int main(){
	int n, d, k, c, kind, plate, res = -1;
	scanf("%d %d %d %d", &n, &d, &k, &c);
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &arr[i]);
	}
	kind = plate = 0; // kind는 다른 종류의 접시의 개수, plate는 현재 먹은 접시 개수
	//최대의 종류를 먹을라면 쿠폰을 사용
	slide[c] = 1;
	kind++;

	for (int i = 0; i < k; i++) // 처음 k개 계산
	{
		if (slide[arr[i]] == 0) kind++; // 0에서 1로 바뀌면 먹은 것을 의미
		slide[arr[i]]++; // 같은 종류의 초밥
		plate++; // 먹은 접시 개수 1 증가
		arr[n + i] = arr[i]; // 마지막 인덱스와 첫 번째 인덱스 연결
	}
	for (int i = k; i < n + k; i++){
		if (res < kind)
			res = kind; // 먹은 초밥 개수 
		if (slide[arr[i]] == 0) kind++; 
		slide[arr[i]]++;
		plate++;
		if (slide[arr[i - k]] == 1) kind--; 
		slide[arr[i - k]]--;
		plate++;
	}
	printf("%d \n", res);
	return 0;
}
