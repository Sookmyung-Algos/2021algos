// S3_9375 패션왕 신해빈.cpp
#include<iostream>
#include<string>
#include<vector>
#include<unordered_map> // 자동적으로 검사됨
using namespace std;

int t, n;

int main(void) {
    
    cin >> t;
    for (int i = 0; i < t; i++) {
        unordered_map<string, int> um;
        int n; cin >> n;

        for (int i = 0; i < n; i++) { // 입력을 받는 부분
            string name; string kind;
            cin >> name >> kind;
            if (um.find(kind) == um.end()) { // 데이터가 없는 경우
                um.insert({ kind,1 });
            }
            else { // 데이터가 있는 경우
                um[kind]++;
            }

        }

        int ans = 1; // 경우의 수 곱하기
        for (auto kind : um) { // 조합(nCr)
            ans *= (kind.second + 1);
        }
        ans -= 1; // 모두 0일때 제외
        cout << ans << "\n";
    }
    return 0;
}
