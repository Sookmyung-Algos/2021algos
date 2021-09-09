#include <iostream>
#include <string>
using namespace std;

#define endl "\n"

struct Trie {
	Trie *next[2];
	int cnt;
	Trie() {
		cnt = 0;
		for (int i = 0; i < 2; ++i)
			next[i] = 0;
	}
	~Trie() {
		for (int i = 0; i < 2; ++i)
			if (!next[i]) delete next[i];
	}
	void insert(char *to_find) {
		++cnt;
		if (!*to_find) {
			return;
		}
		int c = *to_find - '0';
		if (next[c] == NULL)
			next[c] = new Trie();
		next[c]->insert(to_find + 1);
	}
	
	void del(char *to_find) {
		--cnt;
		if (!*to_find) {
			return;
		}
		int c = *to_find - '0';
		next[c]->del(to_find + 1);
	}
	
	void query(char *to_find, int print) {
		if (!*to_find) {
			printf("%d\n", print);
			return;
		}
		int cur = *to_find - '0', op = cur ? 0 : 1;
		if (next[op] && next[op]->cnt)
			next[op]->query(to_find + 1, (print << 1) + 1);
		else
			next[cur]->query(to_find + 1, (print << 1) + 0);
	}
};

int main() {
	Trie* trie;
	int n;
	scanf("%d", &n);
	char tmp[32]; for (int i = 0; i < 31; ++i) tmp[i] = '0'; tmp[31] = 0;
	trie = new Trie(); trie->insert(tmp);
	while (n--) {
		int t, in;
		scanf("%d%d", &t, &in);
		char s[32]; s[31] = 0;
		for (int i = 30; i >= 0; --i) {
			s[i] = (in & 1) + '0'; in >>= 1;
		}
		switch (t) {
		case 1:
			trie->insert(s);
			break;
		case 2:
			trie->del(s);
			break;
		case 3:
			trie->query(s, 0);
		}
		
	}
	return 0;
}
