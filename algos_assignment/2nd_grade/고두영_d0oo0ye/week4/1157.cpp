#include <iostream>
using namespace std;

int main() {

	int n = 0;
	int max = 0;
	char str[1000000] = {};
	char num;
	int arr[26] = {};

	cin >> str;

	while (str[n] != 0) {
		if (str[n] >= 'A' && str[n] <= 'Z')
			arr[str[n] - 'A'] += 1;
		else if (str[n] >= 'a' && str[n] <= 'z')
			arr[str[n] - 'a'] += 1;
		n++;
	}

	for (int i = 0; i < 26; i++) {
		if (arr[i] > max)
		{
			max = arr[i];
			num = i + 'A';
		}
	}

	n = 0;
	for (int i = 0; i < 26; i++) {
		if (arr[i] == max) n++;
	}

	if (n > 1) cout << "?" << endl;
	else cout << num << endl;

	return 0;
}
