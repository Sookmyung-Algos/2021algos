#include <iostream>
#define MAX 1000
using namespace std;

int list[MAX];
void insertion(int list[], int n);

int main()
{
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int term;
		cin >> term;
		list[i] = term;
	}
	insertion(list, n);
	for (int i = 0; i < n; i++) {
		cout << list[i] << endl;
	}
	return 0;
}

void insertion(int list[], int n)
{
	int i, j, next;
	for (i = 1; i < n; i++) {
		next = list[i];
		for (j = i - 1; j >= 0; j--) {
			if (next < list[j])
				list[j + 1] = list[j];
			else break;
		}
		list[j + 1] = next;
	}
}
