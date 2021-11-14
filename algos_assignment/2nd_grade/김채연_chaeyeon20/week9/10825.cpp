#include <iostream>
#include <algorithm>
using namespace std;

struct student {
	char name[10]{};
	short a, b, c;
};



bool dict(char a[10], char b[10]) {
	for (short s = 0; s < 10; s++)
		if (a[s] != b[s])
			return a[s] < b[s];
	return true;
}

bool compare(student a, student b) {
	if (a.a != b.a) return a.a > b.a;
	if (a.b != b.b) return a.b < b.b;
	if (a.c != b.c) return a.c > b.c;
	else return dict(a.name, b.name);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	int n;
	cin >> n;

	student* arr = new student[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i].name;
		cin >> arr[i].a;
		cin >> arr[i].b;
		cin >> arr[i].c;
	}

	sort(arr, arr + n, compare);
	for (int i = 0; i < n; i++)
		cout << arr[i].name << '\n';

	delete[] arr;
	return 0;
}
