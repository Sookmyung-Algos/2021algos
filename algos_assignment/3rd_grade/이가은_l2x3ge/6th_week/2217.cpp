#include<iostream>
#include<algorithm>
#define max(a, b) (((a)>(b))?(a):(b))
using namespace std;

int main() {
	int n, result = 0;
	int weight[100001];
	cin >> n;
	for (int i = 0;i < n;i++) {
		cin >> weight[i];
	}
	sort(weight, weight + n);
	for (int i = 0;i < n;i++) {
		result = max(result,weight[i] * (n - i));
	}
	cout << result;
}
