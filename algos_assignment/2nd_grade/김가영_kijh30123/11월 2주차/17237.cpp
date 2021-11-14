#include<iostream>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);

	int n,a;
	int arr[25]={0,};

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		arr[a]++;
	}
	for (int i = 20; i > 1; i--) {
		arr[i - 1] += (arr[i] / 2);
	}
	if (arr[1] >= 2)
		cout << "A";
	else
		cout << "B";

}
