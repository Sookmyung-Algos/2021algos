#include<iostream>
#include<string>
#include<algorithm>
 
using namespace std;
 
int INF = 1000007;
int broken[10];
int N, M;
 
bool possible(int k) {
    if (k == 0)
        return broken[0] ? false : true;
    while (k) {
        if (broken[k % 10] == 1) {
            return false;
        }
        k /= 10;
    }
  
    return true;
}
 
int find() {
    int ret = abs(N - 100);
    int temp;
    int inf = N * 2 - 100;
    if (inf < 100)
        inf = 100;

    if (M == 10)
        return ret;
 
    for (int i = N; i <= inf; i++) {
        temp = to_string(i).length() + abs(i - N);
        if (possible(i)) {
            ret = min(temp, ret);
            break;
        }
    }
 
    for (int i = N; i >= 0; i--) {
        temp = to_string(i).length() + abs(i - N);
        if (possible(i)) {
            ret = min(temp, ret);
            break;
        }
    }
    return ret;
}
 
int main()
{
    int temp;
    cin >> N >> M;
    for (int i = 0; i < M; i++)
    {
        cin >> temp;
        broken[temp] = 1;
    }
    cout << find() << endl;
  
    return 0;
}
