#include <iostream>
#include <algorithm>
#include <queue>
#include <string>
#include <cstring>
using namespace std;

int arr_num, des_num;
bool arr_check[10000];
bool visit[10000];

void check(){
	for (int i = 1000; i < 10000; i++) {
		for (int j = 2; j < i; j++) {
			if ((i%j) == 0){
				arr_check[i] = true;
				break;
			}
		}
	}
}

void search_num(int arr_num,int res){
	queue<pair<int,int>>Q;
	Q.push(make_pair(arr_num,res));
	visit[arr_num] = true;

	while (!Q.empty()){
		int cur_num = Q.front().first;
		int ans = Q.front().second;
		Q.pop();

		if (cur_num == des_num) {
			cout << ans << '\n';
			return;
		}
		else {
			for (int i = 0; i < 4; i++) {
				int tmp_num;
				for (int j = 0; j < 10; j++) {
					string s = to_string(cur_num);
					s[i] = j + '0';
					tmp_num = stoi(s);

					if (arr_check[tmp_num]||visit[tmp_num]||tmp_num>9999
						||tmp_num < 1000){
						continue;
					}
					visit[tmp_num] = true;
					Q.push(make_pair(tmp_num, ans + 1));
				}
			}
		}
	}
	cout << "impossible" << '\n';
}

int main() {
	int T;
	cin >> T;
	check();

	for (int i = 0; i < T; i++){
		cin >> arr_num >> des_num;
		memset(visit, false, sizeof(visit));
		search_num(arr_num, 0);
	}
}
