#include <iostream>
#include <string>

using namespace std;

string N;
int set[10];

int main() {
	cin >> N;
	for (int i = 0; i < N.length(); i++) {
		set[N[i] - '0']++;
	}
	int p = (set[6] + set[9] + 1) / 2;
	set[6] = set[9] = p;  //6의 개수와 9의 개수를 맞추어준다
	int max = 0;
	for (int i = 1; i < 10; i++)
		if (set[i] > set[max])
			max = i;
	cout << set[max] << endl;
	return 0;
}
