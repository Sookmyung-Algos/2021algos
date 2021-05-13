#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cstring>
using namespace std;


int main() {
    int n, m, cnt = 0;
    string name[1000000];/*두 리스트에는 모두 중복되는 명칭이 없다고 하였으니 이를 이용하여 문제를 풀기 위해 두 리스트를 한 공간에 받음.*/
    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i = 0; i < n + m; i++)
        cin >> name[i];//모든 리스트를 다 받음

    sort(name, name + n + m);// 정렬 함수를 사용해 A-Z순으로 정렬 
    for (int i = 1; i < n + m; i++)// 만약 두 리스트에 모두 있다면 정렬했을 때 바로 앞,뒤에 존재할 것이므로 이를 이용해 듣보잡을 찾아낸다
        if (name[i] == name[i - 1])
            cnt++;
    
    cout << cnt << '\n';// 듣보잡이 몇명인지를 먼저 출력해야하므로 명수를 저장한 cnt를 출력하고 다시 for문을 이용해 듣보잡을 찾아 출력한다.
    for (int i = 1; i < n + m; i++)
        if (name[i] == name[i - 1]) {
           
            cout << name[i] << '\n';
        }

}
