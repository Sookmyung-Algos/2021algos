#include <iostream>
#include <set>
using namespace std;

int main(){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int t;
	cin >> t;

	int n;
	while (t--){
		cin >> n;
		char order;
		int num;
		multiset<int> ms;
		while (n--){
			cin >> order >> num;

			if (order == 'I') ms.insert(num);
			else{
				if (!ms.empty() && num == -1) ms.erase(ms.begin());
				else if (!ms.empty() && num == 1){
					auto iter = ms.end();
					iter--;
					ms.erase(iter);
				}
			}
		}

		if (ms.empty()) cout << "EMPTY" << "\n";
		else{
			auto e = ms.end();
			e--;
			cout << *e << ' ' << *ms.begin() << "\n";
		}
	}
	return 0;
}
