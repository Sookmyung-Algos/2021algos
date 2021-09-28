#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <algorithm>
using namespace std;

int n, c[100001], price = 0, p1, p2;
int main() {
	scanf("%d", &n); //유제품수 n입력
	for (int i = 0; i < n; i++) { //n번동안 
		scanf("%d", c + i); //c 배열에 유제품의 가격 입력
	}
	p1 = n - 1; //p1은 n-1인덱스부터 시작
	p2 = n - 2; //p2는 n-2인덱스부터 시작
	sort(c, c + n); //c배열을 오름차순으로 정렬
	int k = n / 3; 
	for (int i = 0; i < k; i++) { //n/3번동안 
		price += (c[p1] + c[p2]); //price에 p1,p2인덱스의 배열값을 더해줌
		p1 -= 3; //p1을 3씩 감소
		p2 -= 3; //p2를 3씩 감소
	}
	if (p1 >= 0) { //만약 p1이 0보다 크거나 같으면 
		price += c[p1]; //price에 p1인덱스의 배열값을 더해줌
	}
	if (p2 >= 0) { //만약 p2가 0보다 크거나 같으면 
		price += c[p2]; //price에 p2인덱스의 배열값을 더해줌
	}
	printf("%d", price); //price(유제품 모두 살 때의 최소비용) 출력
}
