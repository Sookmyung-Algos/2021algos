#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	string a;
	int alphabet[26] = { 0, };
	int max = -1, maxi, cnt = 0;
	cin >> a;
	for (int i = 0;a[i] != '\0';i++) {
		if (a[i] >= 'A'&& a[i] <= 'Z')
			alphabet[a[i] - 'A']++;
		else if (a[i] >= 'a'&& a[i] <= 'z')
			alphabet[a[i] - 'a']++;
	}
	for (int i = 0;i < 26;i++) {
		if (max < alphabet[i]) { 
			max = alphabet[i]; 
			maxi = i;
		}
	}
	for (int i = 0;i < 26;i++) {
		if (max == alphabet[i])cnt++;
	}
	if (cnt == 1) cout << (char)(maxi+'A');
	else cout << "?";
}
