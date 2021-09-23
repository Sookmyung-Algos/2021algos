#include <iostream>
#include <algorithm>
using namespace std;

int main() {

	int N;
    int call[10000];
    long long callsum = 0;
    long long budgetsum;
    int biggest=0;
    long long ans=0;
    
	cin >> N;

	for (int i = 0; i < N; i++) {
		cin >> call[i];
        
        biggest = max(biggest,call[i]);    //요청액 중 최댓값 저장
		callsum += call[i];	// 요청액 합계
	}

	cin >> budgetsum;

	if (callsum <= budgetsum)
		ans = biggest;	// 모든 요청이 배정될 수 있는 경우 요청액 금액 그대로 배정함
	
    else {    // 모든 요청이 배정될 수 없는 경우 상한액 찾아 예산 배정
		int low = 0, high = biggest;
	
		while (low <= high) {
            
			int mid = (low + high) / 2;
            long long sum=0;
            
			for (int i = 0; i < N; i++) {
				
                sum += min(call[i], mid);
			}
			if (sum > budgetsum) {
				high = mid - 1;    // high 값 조정하여 반복문 재실행
			}
			else {
				low = mid + 1;    // while 벗어나게 함
				ans = mid;    // 배정된 예산들 중 최댓값 = mid
			}
		}    // 이분 탐색
	}
	cout << ans;
	return 0;
}
