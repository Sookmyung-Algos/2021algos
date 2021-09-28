#include <stdio.h>
#define MAX 1000001

int main() {
	int ice, loc;
	int n, k;
	int min, max;
	int left, right;
	int sum = 0;
	int sumMax = 0;
	int bucket[MAX];

	scanf("%d %d", &n, &k); //얼음양동이 n개, 좌우로 k만큼 떨어진 양동이까지 닿을 수 있음

	scanf("%d %d", &ice, &loc); //첫 양동이의 loc(위치)와 ice(얼음개수) 값을 입력받고 
	bucket[loc] = ice; //bucket배열의 loc 인덱스에 ice 값을 저장
	min = loc, max = loc; //최소,최대값에 처음 위치(loc)을 저장

	for (int i = 0; i < n - 1; i++) { //처음 제외하고 n-1번동안
		scanf("%d %d", &ice, &loc); //양동이의 loc와 ice 값 입력
		min = ((min < loc) ? min : loc); //최소 loc를 구해서 min에 저장
		max = ((max > loc) ? max : loc); //최대 loc를 구해서 max에 저장
		bucket[loc] = ice; //bucket배열의 loc 인덱스에 ice값을 저장
	}

	for (left = min; left + 2 * k <= max; left++) { //left가 min(최소 loc)부터 시작하여 left+2*k 값이 max(최대 loc)보다 작거나 같을때까지
		sum = 0;
		for (int i = 0; i < 2 * k; i++) { //sum에 left인덱스의 ice값부터 left+2*k-1인덱스의 ice값까지 더해줌
			sum += bucket[left + i];
		}
		sumMax = ((sumMax > sum) ? sumMax : sum); //최대 sum값을 sumMax에 저장

	}

	printf("%d", sumMax);
}
