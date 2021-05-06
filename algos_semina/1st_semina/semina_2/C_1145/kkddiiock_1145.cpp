#include<iostream>
using namespace std;
int n[5];
int chk, value=1;
int main() {
	for (int i = 0; i < 5; i++)
		cin>>n[i];
	while (true) {
		chk = 0;
		for (int i = 0; i < 5; i++)
			if (value % n[i] == 0)chk++;
		if (chk >= 3) {
			cout << value << "\n";
			break;
		}
		value++;
	}
	return 0;
}
