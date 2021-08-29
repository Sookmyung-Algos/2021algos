#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <stack>
#include <vector>
#include <algorithm> 
#include <queue>

#include <time.h>
#define MAX 100001
using namespace std;

int n, k;
int arr[101][101];
int garo, sero;
void push(int num) {
	
	for (int i = sero; i < k+sero; i++) {
		for (int j = garo; j < k+garo; j++) {
			arr[i][j] = num;
		}
		
	}
	
	garo += k;
	garo = garo % (n * k);
	if (garo == 0) sero += k;
}
int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);

	cin >> n >> k;


	for (int i = 0; i < n*n; i++) {
		int p;
		cin >> p;
		push(p);
	}
	for (int i = 0; i < n * k; i++) {
		for (int j = 0; j < n * k; j++) {
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	return 0;
}
