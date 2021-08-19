#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);

	int n, sum;
	cin >> n;
	vector<int> v(n);
	for (int i = 0;i < n;i++) {
		cin >> v[i];
	}
	//오름차순으로 입력받은 정수들을 정렬한다.
	sort(v.begin(), v.end());
//정렬된 정수의 가장 처음 값(index가 0인 정수)이 1인지 확인한다
	if (v[0] != 1) {
		cout << "1";
		return 0;
	}
	else {
    //1이 있기 때문에 합을 저장하는 변수를 1로 초기화해준다.
		sum = 1;
		for (int i = 1;i < n;i++) {
      // 만약 다음 수가 누적합+1보다 크다면 누적합+1의 값은 나올 수 없다
			if (v[i] > sum + 1) {
				break;
			}
			else {
				sum += v[i];
			}
		}
		cout << sum + 1;
		return 0;
	}
}
