#include <iostream>
#include <string>
#include <deque>

using namespace std;

int main() {
	int t,n,tmp,i;
	bool flag, sorted;
	string p,nums;
	cin >> t;
	while (t--) {
		deque<int>list;
		flag = true; sorted = true;
		cin >> p >> n >> nums;
		i = 1;
		while (nums[i] != '\0') {
			tmp = 0;
			while (nums[i] >= '0' && nums[i] <= '9') {
				tmp = tmp * 10 + nums[i] - '0';
				i++;
			}
			if(tmp!=0)
				list.push_back(tmp);
			i++;
		}
		i = 0;
		while (p[i] != '\0') {
			if (p[i] == 'R') sorted = !sorted;
			else {
				if (list.empty()) {
					cout << "error" << '\n';
					flag = false;
					break;
				}
				else if (sorted)
					list.pop_front();
				else
					list.pop_back();
			}
			i++;
		}
		if (flag) {
			cout << "[";
			while (!list.empty()) {
				if (sorted) {
					int t = list.front();
					list.pop_front();
					cout << t;
				}
				else {
					int t = list.back();
					list.pop_back();
					cout << t;
				}
				if (!list.empty())
					cout << ',';
			}
			cout << ']' << '\n';
		}
	}
	return 0;
}
