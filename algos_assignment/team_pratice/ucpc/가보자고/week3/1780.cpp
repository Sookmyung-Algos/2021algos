#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <map>
#include <unordered_map>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm> 
#include <queue>
#include <math.h>
#include <time.h>
#define MAX 100001
using namespace std;
int num[3];  //num[0]:-1 num[1]: 0,num[2]: 1
int arr[2300][2300];
int n;
bool is9(int row, int col,int m) {
	int q = arr[row][col];
	int newrow = m + row;
	int newcol = col + m;
	for (int i =row; i <newrow; i++) {
		for (int j =col; j <newcol; j++) {
			if (arr[i][j] != q) return false;
		}
	}
	num[q+1]++;
	return true;
}

void divide(int row,int col,int m) {
	bool ret = is9(row, col,m);
	if (ret == true) {
		return;
	}
	int newrow = m + row;
	int newcol = col + m;
	if (ret == false) {
		int size =m / 3;
		for (int i = 0; i < 3; i++) {
			for (int j = 0; j < 3; j++) {
				divide(row + size * i, col + size * j, size);
			}
		}
	}
	

}

int main() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);


	cin >> n;


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			
		}
	}

	divide(0,0,n);
	for (int i = 0; i < 3; i++) {
		cout << num[i] << "\n";
	}
	return 0;
}
