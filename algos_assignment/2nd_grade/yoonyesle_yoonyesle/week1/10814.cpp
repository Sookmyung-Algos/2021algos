#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct score{
		int age, index;
		string name;
}a[100001];
bool comp(score a, score b){
	return a.age!=b.age ? a.age<b.age : a.index<b.index;
}
int main() {
	int n, i;
	cin >> n;
	for(i=0; i<n; i++){
		cin >> a[i].age >> a[i].name;
		a[i].index=i;
	}
	sort(a, a+n, comp);
	for(i=0; i<n; i++)
		cout << a[i].age << ' ' << a[i].name << '\n';
	return 0;
}
