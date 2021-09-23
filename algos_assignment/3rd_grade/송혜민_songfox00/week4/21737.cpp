#include<iostream>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int main() {
	int n;
	cin >> n;

	string str;
	cin >> str;
	queue<char>q;
	queue<int>t;
	vector<char>num;

	int res = 0, j = 0, c = 0;
	int sum = 0;
	char s;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] >= '0'&&str[i] <= '9') {
			num.push_back(str[i]);
		}
		else {
			q.push(str[i]);
			string a = "";
			int flag = 0;
			if (num.size()!=0) {
				for (int k = 0; k < num.size(); k++) {
					if (num[k] == '0') {
						if (flag == 1)
							a += num[k];
						else
							continue;
					}
					else {
						a += num[k];
						flag = 1;
					}
				}
				if (a.length() == 0)
					a = "0";
				t.push(stoi(a));
				num.clear();
			}
		}

		if (t.size() == 2) {
			s = q.front();
			q.pop();
			res = t.front();
			t.pop();
			sum = t.front();
			t.pop();
			if (s == 'S') {
				res -= sum;
			}
			else if (s == 'M') {
				res *= sum;
			}
			else if (s == 'U') {
				res /= sum;
			}
			else if (s == 'P') {
				res += sum;
			}
			t.push(res);
		}
		if (!q.empty() && q.front() == 'C') {
			c++;
			cout << t.front() << ' ';
			q.pop();
		}
	}
	if (c == 0)
		cout << "NO OUTPUT";

	return 0;
}
