#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main() {
	int n,num,sum=0;
	cin >> n;
	vector<int> v;
	for (int i = 0; i < n; i++) {
		scanf("%d", &num);
		v.push_back(num);
	}
	sort(v.begin(), v.end(), greater<int>());
	if (n % 3 != 0) {
		for (; n % 3 != 0; n--) {
			sum += v.back();
			v.pop_back();
		}
	}
	while (n / 3 != 0) {
		v.pop_back();
		sum += v.back();
		v.pop_back();
		sum += v.back();
		v.pop_back();
		n -= 3;
	}
	printf("%d", sum);
}
