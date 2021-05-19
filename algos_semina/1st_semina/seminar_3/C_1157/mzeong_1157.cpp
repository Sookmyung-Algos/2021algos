#include <iostream>
#include <string>
using namespace std;

int main()
{
	int alphabet[100]={0,};
	string word;
	cin >> word;
	
	for (auto c : word)
	{
		if ('a' <= c) c = c - 32;
		alphabet[c]++;
	}

	int max = 0;
	char result = '?';
	
	for (int alpha = 'A'; alpha <= 'Z'; alpha++)
	{
		if (alphabet[alpha] > max) {
			max = alphabet[alpha];
			result = alpha;
		}
		else if (alphabet[alpha] == max) {
			result = '?';
		}
	}
	cout << result << endl;
	return 0;
}
