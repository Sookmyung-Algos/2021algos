#include <iostream>
#include <vector>
#include <string>
using namespace std;


int main()
{
	int x, y;
	int t;
	cin >> t;

	while (t--) {
		int cnt = 0;
		cin >> x >> y;
	
		int head = 1;
		unsigned int a = y - x;
		int move = 1, movp = 0;
		while (movp < a) {
			cnt++;
			movp += move;
			if (cnt % 2 == 0) move++;
		}
		cout << cnt << endl;

	}

	return 0;
}
