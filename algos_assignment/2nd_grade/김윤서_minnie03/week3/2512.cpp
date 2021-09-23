//#2512 
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int>v;
int n, m, sum = 0;

int binarysearch(int low, int high) {
	int ans;
	int mid = (low + high) / 2; //상한액 설정
	while (high >= low) { //high값이 low보다 크거나 같을때 while문 반복
		int total = 0; 
		for (int i = 0; i < n; i++) 
			total += (v[i] > mid) ? mid : v[i]; //i-1번째 지방의 예산요청 금액과 상한액을 비교하여 더 작은 값을 sum에 더함
		if (total == m) {//상한액과 예산요청 금액 중 작은값을 택하여 더한 값이 총 예산과 같다면
			return mid; //상한액 반환
		}
		else if (total > m) {//상한액과 예산요청 금액 중 작은값을 택하여 더한 값이 총 예산보다 크다면 총 예산을 초과하므로
			high = mid - 1; //low~mid-1까지 while문 한번 더 반복하여 작은 상한액으로는 예산 내의 범위로 집행 가능한지 탐색
		}
		else //상한액과 예산요청 금액 중 작은값을 택하여 더한 값이 총 예산보다 작다면
		    low = mid + 1; //mid+1~high까지 while문 한번 더 반복하여 더 큰 상한액 가능한지 탐색
		mid = (low + high) / 2;
	}
	return mid;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n; //지방의 수 n 입력
	int y,high=0;
	for (int i = 0; i < n; i++) {
		cin >> y;
		v.push_back(y);
		sum += y; //sum에 각 지방의 예산요청 금액을 다 합친 값을 대입
		if (v[i] > high)
			high = v[i];
	}
	cin >> m; //총 예산 m 입력
	cout<<binarysearch(0,high)<<endl;
	return 0;
}
