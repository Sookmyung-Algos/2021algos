#include <iostream>
using namespace std;
 
int main(void)
{
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
 
	int N;
	int arr[26];
	bool is_possible;
	string s1, s2;
	cin >> N;
 
	for (int i = 0; i < N; i++) {
		cin >> s1 >> s2;
		is_possible = true;
		fill(arr, arr + 26, 0);
		for (int j = 0; j < s1.length(); j++) {
			arr[s1[j] - 'a']++;
			arr[s2[j] - 'a']--;
		}
		for (int j = 0; j < 26; j++) {
			if (arr[j] != 0) {
				is_possible = false;
				break;
			}
		}
		if (is_possible) cout << "Possible\n";
		else cout << "Impossible\n";
	}
 
	return 0;
}
