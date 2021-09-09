#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct STUDENT{
    string name;
    int korean;
    int english;
    int math;
}s;

bool cmp (const STUDENT &a, const STUDENT &b){
    if (a.korean > b.korean) return true; // 국어 감소하는 순
    else if (a.korean == b.korean){
        if (a.english < b.english) return true; // 영어 증가하는 순
        else if (a.english == b.english){
            if (a.math > b.math) return true; // 수학 감소하는 순
            else if (a.math == b.math){
                if (a.name < b.name) return true; // 알파벳 순
            }
        }
    }
    return false;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
    
    int T;
    cin >> T;
    
    vector <STUDENT> v(T);
    while (T--){
        cin >> s.name >> s.korean >> s.english >> s.math;
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmp);
    
    for (auto i:v){
        cout << i.name << '\n';
    }
    return 0;
}
