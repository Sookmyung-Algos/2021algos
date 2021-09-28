// 9375 패션왕 신해빈

#include <iostream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main() {
    int test;
    cin >> test;

    while (test--) {
        vector<int>v;
        map<string, int>clothes;

        int num;
        cin >> num;

        while (num--) {
            string name, sort;
            cin >> name >> sort;
            clothes[sort]++;
        }
        int ans = 1;
        for (auto iter : clothes) { //map의 범위기반 반복문 구현법
            ans *= (iter.second + 1);
        }
        cout << ans - 1 << '\n';
    }
    return 0;
}
