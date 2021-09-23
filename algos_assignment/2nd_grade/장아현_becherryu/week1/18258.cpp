#include <iostream>
#include <queue>

using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	int n, a;
	cin >> n;

    queue<int> q;
	string str;

	for(int i = 0; i < n; i++) {
		cin >> str;
		if (str == "push") {
			cin >> a;
			q.push(a);
		}
		else if (str == "pop") {
			if (q.empty())
				cout << "-1\n";
			else {
                cout << q.front() << "\n";
                q.pop();
            }
		}
		else if (str == "size")
			cout << q.size() << "\n";

		else if (str == "empty") {
			if (q.empty())
				cout << "1\n";
			else
				cout << "0\n";
		}
		else if (str == "front") {
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.front() << "\n";
		}
		else //back
			if (q.empty())
				cout << "-1\n";
			else
				cout << q.back() << "\n";
	}
    return 0;
}
