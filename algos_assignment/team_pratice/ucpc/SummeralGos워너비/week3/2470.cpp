//#2470 //알칼리나 산만으로 만들어질 수도 있음 주의
#include <iostream>
#include <algorithm> //sort 사용하기 위해
#include <cstdlib> //절댓값 함수(abs) 사용하기 위해
using namespace std;

int n;
long long pro[100001];
long long m; //현재 시행에서 두 용액을 합친 값
long long before = 2000000000; //이전 시행에서 두 용액을 합친 값 (최대로 초기화)
long long result_l, result_r; //두 용액의 합의 절댓값이 최소를 나타내는 두 용액

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> pro[i];

	sort(pro, pro + n); //용액을 오름차순으로 저장

	int left = 0, right = n-1;
	while (left < right) {
		m =pro[left] + pro[right];
		if (abs(m)<abs(before)) { //이번 두 용액의 합의 절댓값이 이전보다 작음
			result_l = pro[left]; //현재의 두 용액을 각각 result에 저장
			result_r = pro[right];
			before = m; //현재까지 합의 절댓값이 최소인 두 용액의 합을 저장
		
			if(m==0) break; //두 용액의 합이 0이라면 더이상 검사하지 않고 반복 종료
		}
		
		if (m > 0) right--; //두 용액의 합이 0보다 크면 양수용액의 index감소
		else left++; //두 용액의 합이 0보다 작으면 음수용액의 index 증가

		
	}
	printf("%lld %lld", result_l, result_r);
	return 0;
}
