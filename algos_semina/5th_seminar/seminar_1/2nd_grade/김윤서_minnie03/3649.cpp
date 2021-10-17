#include <iostream> 
#include <vector> 
#include <algorithm> 
using namespace std; 

int main(void) { 
	ios_base::sync_with_stdio(0); 
	cin.tie(0); cout.tie(0);
	
	int x; 
	while (cin >> x) { 
		int n; 
		cin >> n; 
		
		vector<int> blocks(n); // 레고조각의 수 n을 크기로하는 정수 벡터 blocks 생성
		for (int i = 0; i < n; i++) { // 레고조각의 수만큼
			cin >> blocks[i]; // 레고조각의 길이 입력
		} 
		sort(blocks.begin(), blocks.end()); // 레고조각 작은 것부터 정렬
		int flag = 0; // 막을 수 있는지 없는지 체크하는 변수 

		x *= 10000000; // 센티미터 단위를 나노미터 단위로 변환
		for (int i = 0; i < n && blocks[i] <= x / 2; i++) { 
			int low = i + 1, high = n - 1; 
			// 이분탐색
			while (low <= high) { 
				int mid = (low + high) / 2; 
				if (blocks[mid] + blocks[i] == x) { // 구멍에 넣을 두 조각의 길이의 합이 구멍의 너비와 일치한다면
					flag = 1;  // flag=1로 저장
					cout << "yes " << blocks[i] << " " << blocks[mid] << "\n"; break; 
				} 
				else if (blocks[mid] + blocks[i] < x) { // 구멍의 너비보다 작다면
					low = mid + 1; // 범위의 가장 작은 수를 중간+1 값으로 저장
				} 
				else {  // 구멍의 너비보다 크다면
					high = mid - 1; // 범위의 가장 큰 수를 중간-1 값으로 저장
				} 
			} 
			if (flag) { // 구멍을 완벽하게 막을 수 있다면
				break; // 반복문 종료
			} 
		} 
		if (flag == false) { // 구멍을 완벽하게 막을 수 없다면
			cout << "danger\n"; // 'danger' 출력
		} 
	} 
	return 0;
}
