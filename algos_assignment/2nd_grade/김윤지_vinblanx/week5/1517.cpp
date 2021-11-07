#include <iostream>
#include <vector>

using namespace std;
 
long long result = 0;
 
void merge(vector<int> &v, int start, int end) {
	int mid = (start + end) / 2;
	int left = start;
	int right = mid + 1;
	vector<int> temp;
 
	if (start == end) {
		return;
	}
	
	merge(v, start, mid);
	merge(v, mid + 1, end);
 
	while (left <= mid && right <= end) {
		if (v[left] <= v[right]) {
			temp.push_back(v[left++]);
		}
		else {
			temp.push_back(v[right++]);
			result += (mid + 1 - left);
		}
	}
	while (left <= mid) {
		temp.push_back(v[left++]);
	}
	while (right <= end) {
		temp.push_back(v[right++]);
	}
	for (int i = start, j = 0; i <= end; ++i, ++j) {
		v[i] = temp[j];
	}
}
 
int main()
{
	int n;
	vector<int> v;
 
	cin >> n;
 
	v.resize(n);
 
	for (int i = 0; i < n; ++i) {
		cin >> v[i];
	}
 
	merge(v, 0, n - 1);
 
	printf("%lld", result);
 
	return 0;
}
