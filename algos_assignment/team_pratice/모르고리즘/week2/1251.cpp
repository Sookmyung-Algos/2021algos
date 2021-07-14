#include <iostream>
#include <string>
using namespace std;

int main() {
	string in, out = "~";
	cin >> in;

	for (int i = 0; i < in.size()-2; i++) {
		for (int j = i + 1; j < in.size() - 1; j++) {
			string temp;
			for (int u = i; u >= 0; u--)	temp += in[u];
			for (int u = j; u > i; u--)	temp += in[u];
			for (int u = in.size() - 1; u > j; u--)	temp += in[u];
			if (out > temp) out = temp;
		}
	}
	cout << out;
	return 0;
}
