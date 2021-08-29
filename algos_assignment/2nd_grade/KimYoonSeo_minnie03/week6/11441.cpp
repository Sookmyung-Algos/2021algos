#include <iostream>
#include <vector>
using namespace std;

int main() {
	int n, m, a, b;
	scanf("%d", &n);

	vector<int> num(n+1,0); //n+1을 크기로 하는 벡터 num 생성
	int temp;

	for (int i = 1; i<= n; i++) { //n번동안
		scanf("%d",&temp); //temp를 입력받고 
		num[i] = num[i-1]+temp; //i-1번째까지의 합과 temp를 합쳐 num[i]에 저장
	}

	scanf("%d", &m);
	while(m--){ //m번 동안
		scanf("%d %d", &a, &b);
        //b까지의 합에서 a-1까지의 합을 빼면 a~b사이 숫자의 합을 구할 수 있음
		printf("%d\n", num[b] - num[a - 1]);
	}
	return 0;
}
