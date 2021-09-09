#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    int n, h; //길이, 높이
    cin >> n >> h;
    vector<int> up, down;
    for (int i = 0; i < n/2; i++) {
        int temp;
        cin >> temp;
        down.push_back(temp);
        cin >> temp;
        up.push_back(temp);
    }
    
    sort(down.begin(), down.end());
    sort(up.begin(), up.end());

    vector<int> destroy(down.size());
    int result = 2000001, cnt = 1, crash;
    for (int i = 1; i <= h; i++) {
        //lower_bound: 찾으려는 값보다 작거나 큰 수가 처음으로 나오는 인덱스
        //upper_bound: 찾으려는 값을 초과하는 수가 처음으로 나오는 인덱스
        crash = down.size() - (lower_bound(down.begin(), down.end(), i) - down.begin());
        crash += up.size() - (upper_bound(up.begin(), up.end(), h - i) - up.begin());

        if (result == crash)    cnt++;
        else if (result > crash) {
            result = crash;
            cnt = 1;
        }
    }
    cout << result << " " << cnt;
    return 0;
}
