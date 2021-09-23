#include <string>
#include <list>
using namespace std;
int main() {
	string editor;

	int q;
	cin >> q;
	while (q--) {
	list<char> L;
		cin >> editor;
		auto cusor = L.end();
		for (auto op : editor){ 
			if (op == '-') {
				if (cusor != L.begin()) {
					cusor = L.erase(--cusor);
				}
			}
			else if (op == '<') {
				if (cusor != L.begin()) {
					cusor--;
				}
			}
			else if (op == '>') {
				if (cusor != L.end()) {
					cusor++;
				}
			}
			else {
				L.push_back(op);
			}

		}
		for (auto c : L) printf("%c", c);
		cout << endl;
	}

}
