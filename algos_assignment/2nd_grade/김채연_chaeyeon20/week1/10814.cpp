#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

struct Node {
	int age;
	string name;
	int order;
};
bool compare(Node v, Node tar) {
	if (v.age < tar.age) return true;
	if (v.age > tar.age) return false;
	if (v.order > tar.order) return false;
	return true;
}
void init() {
	cin.tie(0);
	cout.tie(0);
	ios_base::sync_with_stdio(false);
}
Node arr[100000];
int main() {
	init();
	int n;
	cin >> n;
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i].age >> arr[i].name;
		arr[i].order = i;
	}
	sort(arr,arr + n, compare);
	for (int i = 0; i < n; i++) {
		cout << arr[i].age << " " << arr[i].name << "\n";
	}
	return 0;
}
