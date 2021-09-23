#include <iostream>
#include <map>

using namespace std;

map<string, float> m;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);  //fast io
    string tree;
    float count = 0;

    while (getline(cin, tree)) {
        count++;
        if (m.find(tree) != m.end())  //이미 나무 key가 있는 경우
            m[tree]++;
         else  //처음 입력된 나무 key인 경우
            m[tree] = 1;
        
    }

    cout << fixed;
    cout.precision(4); //소수점 넷째까지만

    for (auto it = m.begin(); it != m.end(); it++) { //iterator를 통해 순회 출력
        float per = (it->second / count) * 100; // it->second = value
        cout << (it->first) << ' '; 
        cout << per << '\n'; // it->second = key
    }

    return 0;
}
