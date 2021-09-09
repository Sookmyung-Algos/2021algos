#include <iostream>
#include <string>
using namespace std;

#define endl "\n"

struct Trie {
	Trie *next[26];
	int cnt;
	Trie() {
		cnt = 0;
		for (int i = 0; i < 26; ++i)
			next[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < 26; ++i)
			if (!next[i]) delete next[i];
	}
	void insert(string to_find, int i, bool print) {
		if (!to_find[i]) {
			++cnt;
			if (!print) {
				cout << to_find;
				if (cnt > 1)
					cout << to_string(cnt);
				cout << endl;
			}
			return;
		}
		int c = to_find[i] - 'a';
		if (!next[c] && !print) {
			next[c] = new Trie();
			for (int j = 0; j <= i; ++j)
				cout << to_find[j];
			cout << endl;
			print = true;
		}
		if (next[c] == NULL)
			next[c] = new Trie();
		next[c]->insert(to_find, i + 1, print);
	}
};

int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	Trie* trie;
	int n;
	cin >> n;
	trie = new Trie();
	while (n--) {
		string in;
		cin >> in;
		trie->insert(in, 0, false);
	}
	return 0;
}
