#include <vector>
#include <string>
#include <map>
#include <iostream>

using namespace std;

int main() {
	string s = "";
	int count = 0;
	map<char, int> nucleotide = { { 'A', 0 },{ 'C', 0 },{ 'G', 0 }, { 'T', 0 }};

	int n, m;
	cin >> n >> m;
	vector<string> dna;
	for (int i = 0; i < n; i++) {
		string tmp;
		cin >> tmp;
		dna.push_back(tmp);
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			nucleotide[dna[j][i]]++;
		}

		int max = 0;
		char max_char;
		for (auto &tmp : nucleotide) {
			if (tmp.second > max) {
				max = tmp.second;
				max_char = tmp.first;
			}
			tmp.second = 0;
		}
		s += max_char;
	}

	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (s[i] != dna[j][i]) count++;
		}
	}

	cout << s << "\n" << count << "\n";
}
