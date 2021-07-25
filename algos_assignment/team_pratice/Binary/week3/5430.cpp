#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int t, n;
string p, arr;
int num[100001];
int start_idx, end_idx;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> p >> n >> arr;
		int idx = 0;
		for (int i = 0; i < arr.length(); i++) {
			int tmp = 0;
			if (arr[i] != '[' && arr[i] != ']' && arr[i] != ',') {
				int j = i;
				while (arr[j] != '[' && arr[j] != ']' && arr[j] != ',') {
					tmp += arr[j++] - '0';
					tmp *= 10;
					i++;
				}
				tmp /= 10;
				num[idx++] = tmp;
			}
		}
		start_idx = 0; end_idx = idx - 1;
		bool flag = false; bool dir = true; //R : 방향 체크
		for (int i = 0; i < p.length(); i++) {
			if (p[i] == 'R') {
				if (dir) {
					dir = false;
				}
				else if (!dir) {
					dir = true;
				}
			}
			else if (p[i] == 'D') {
				if (idx == 0) {
					flag = true;
					cout << "error\n";
				}
				if (dir==true) {//정방향일때
					start_idx++;
					idx--;
				}
				else if(dir==false){//역방향일때
					end_idx--;
					idx--;
				}
			}
		}
		if (flag == false) {
			cout << '[';
			if (dir) {
				for (int i = start_idx; i <= end_idx; i++) {
					if (i != end_idx) {
						cout << num[i] << ",";
					}
					else cout << num[i];
				}
			}
			else if (!dir) {
				for (int i = end_idx; i >= start_idx; i--) {
					if (i != start_idx) cout << num[i] << ",";
					else cout << num[i];
				}
			}
			cout << "]\n";
		}
	}
}
