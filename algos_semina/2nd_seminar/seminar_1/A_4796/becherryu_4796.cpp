#include <iostream>
using namespace std;

int main()
{
	int l, p, v;
	int op, days;
	int input = 1;

	while (true)
	{
		cin >> l >> p >> v;

		if (l == 0 && p == 0 && v == 0)
			break;

		op = (v % p) > l ? l : (v % p);
		days = v / p * l + op;

		cout << "Case " << input << ": " << days << endl;
		input++;
	}

	return 0;
}
