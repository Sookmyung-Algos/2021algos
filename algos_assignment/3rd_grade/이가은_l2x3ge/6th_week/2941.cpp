#include <iostream>
#include <cmath>
using namespace std;

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	ios_base::sync_with_stdio(false);

	//1. = --> c, s, z(dz= or z=)
	//2. - --> c,d
	//3. j --> l, n

	char c[101];
	int sum=0;
	cin >> c;
	for (int i = 0;c[i] != '\0';i++) {
		if (i == 0) {
			sum++;
			continue;
		}
		//1.
		if (c[i] == '=') {
			switch (c[i - 1]) {
				case 'c':
					sum--;
					break;
				case 's':
					sum--;
					break;
				case 'z':
					if (i >= 2 && c[i - 2] == 'd')
						sum -= 2;
					else
						sum--;
					break;
			}
		}
		//2.
		if (c[i] == '-') {
			switch (c[i - 1]) {
				case 'c':
					sum--;
					break;
				case 'd':
					sum--;
					break;
			}
		}
		//3.
		if (c[i] == 'j') {
			switch (c[i - 1]) {
			case 'l':
				sum--;
				break;
			case 'n':
				sum--;
				break;
			}
		}
		sum++;

	}

	cout << sum;
	return 0;
}
