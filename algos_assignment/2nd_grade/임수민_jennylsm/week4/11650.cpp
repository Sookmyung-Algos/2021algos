#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

vector<pair<int, int> > v;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int n;
    int a, b;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> a >> b;
        v.push_back({ a,b });
    }
    sort(v.begin(), v.end());  //x좌표와y좌표를 입력받아서 정렬한다

    for (int i = 0; i < v.size(); i++) {
        cout << v[i].first << " " << v[i].second << "\n";  //정렬한 원소를 출력한다
    }

    return 0;
}
