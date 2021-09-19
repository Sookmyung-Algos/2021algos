#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#define _CRT_SECURE_NO_WARNINGS
using namespace std;
int origin[10][10] = { 0, };
int dr[8] = { -1,-1,0,1,1,1,0,-1 };
int dc[8] = { 0,1,1,1,0,-1,-1,-1 };
vector<vector<char>>newV(10, vector<char>(10, '.'));
int n;
void boom();
void print();
void around(int i,int j);
int main() {
	bool flag = false;
	string tmp = "";
	cin >> n;
	for(int i=0;i<n;i++){
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			origin[i][j] = (tmp[j] == '.') ? 0 : 1;
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> tmp;
		for (int j = 0; j < n; j++) {
			if (tmp[j] == 'x' && origin[i][j] == 1) {
				flag = true;
			}
			else if (tmp[j] == 'x' && origin[i][j] == 0)
				around(i, j);
		}
	}
	if (flag) boom();
	else print();
	return 0;
}
void boom() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (origin[i][j] == 1)printf("*");
			else printf("%c",newV[i][j]);
		}
		printf("\n");
	}
}
void print() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", newV[i][j]);
		}
		printf("\n");
	}
}
void around(int i,int j) {
	int sum = 0;
	for (int k = 0; k < 8; k++) {
		if (i + dr[k] < 0 || i + dr[k] >= n || j + dc[k] < 0 || j + dc[k] >= n)continue;
		else {
			sum += origin[i + dr[k]][j + dc[k]];
		}
	}
	newV[i][j] = '0' + sum;
}
