#include <iostream>
#include <algorithm>
using namespace std;

int N;
int arr[1000];

int main() {
	cin >> N;
    
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}

	sort(arr, arr + N);

	int sum = 1;
    
	for (int i = 0; i < N; i++) {
		if (arr[i] > sum) {
			break;
		}
        
		sum += arr[i];
	}

	cout << sum;
}
