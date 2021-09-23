#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<cmath>
#include<string>
#include<memory.h>
#include<stack>
#include<cstdlib>
#include<climits>
using namespace std;
int main() {
	int n;
	long long arr[100001];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	long long ans = LLONG_MAX;
	int y1 = 0, y2 = 0;
	int low = 0, high = n - 1;
	while (low < high) {//서로 다른 용액 섞어야하므로 >= 아님
		long long mid = arr[low] + arr[high];
		if (llabs(mid) < ans) {
			ans = llabs(mid); //절댓값 더 작은 것으로 저장
			y1 = low;
			y2 = high; //각각의 용액 인덱스 저장
		}
		//오름차순이므로
		if (mid < 0) low++; 
		else high--;
	}
	cout << arr[y1] << " " << arr[y2];
}
