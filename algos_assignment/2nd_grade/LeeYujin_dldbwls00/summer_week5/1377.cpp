#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

//버블소트가 어디서 멈추는지
int n;
int main() {
    cin >> n;
    vector<pair<int, int>> v(n); //<숫자, 인덱스> 
    for (int i = 0; i < n; i++) {
        cin >> v[i].first;
        v[i].second = i;
    }
    sort(v.begin(), v.end());
    int ans = 0;
    for (int i = 0; i < n; i++)   ans = max(ans, v[i].second - i);
    cout << ans + 1;
	return 0;
}//복습
