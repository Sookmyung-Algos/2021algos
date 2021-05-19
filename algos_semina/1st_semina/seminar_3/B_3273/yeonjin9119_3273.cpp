#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main() {
	int n, cnt = 0, x, num[100000];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> num[i];
	}
	cin >> x;
	sort(num, num + n);//수를 오름차순으로 정렬한 후 더하기 위해 정렬 사용
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (num[i] + num[j] == x) {
				cnt++;
			}
			else if (num[i] + num[j] > x) {/* 현재 오름차순으로 정렬했기 때문에 num[i] + num[j]가 x값보다 크다면 
      num[j+1]>num[j] 이므로 다음 for문에서도 두 값을 더했을 때 x보다 클 수 밖에 없음. 그러므로 break를 사용해 이중반복문을 탈출*/
				break;
			}
		}
	}
	cout << cnt;
}
