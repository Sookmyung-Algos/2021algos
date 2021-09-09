#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <functional>
using namespace std;

vector<string> v;
vector<int> al(26, 0);

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    int n, sum = 0;
    cin >> n;

    string s;
    for (int i = 0; i < n; i++) {
        cin >> s;
        v.push_back(s);
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= v[i].size(); j++) {
            al[v[i][v[i].size() - j] - 'A'] += pow(10, j - 1);
        }
    }
        
    sort(al.begin(), al.end(), greater<>());

    int j = 9;
    for (auto i : al) {
        if (i == 0) break;
        sum += i * j--;
    }

    cout << sum << '\n';

    return 0;
}
