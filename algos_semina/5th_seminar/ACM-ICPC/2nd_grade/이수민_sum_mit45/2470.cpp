#include <iostream>
#include <vector>
#include <algorithm>
#define INF 2000000000
using namespace std;

vector <int> ans(2);
int main(){
	int N; cin >> N;
	vector <int> arr(N);
	for(int i=0; i<N; i++) cin >> arr[i];
	sort(arr.begin(), arr.end()); // 정렬이 필수! 
	
	int start =0; int end = N-1; // 왼쪽 끝과 오른쪽 끝에서 시작
	int min = INF; // 0에 가까운 최솟값
	
	while(start < end){
		int sum = arr[start] + arr[end];
		if (min > abs(sum)){ // 0에 가까운 최솟값이라면
			min = abs(sum); ans[0] = arr[start]; ans[1] = arr[end]; // 최솟값 갱신, 두 포인터 값 저장
			
			if (sum == 0) break;
		}
		if (sum<0) start++; // 음수라면 더 작은 음수를 빼기
		else end--; // 양수라면 더 작은 양수를 더하기
	}
	
	cout << ans[0] << " " << ans[1];
}
