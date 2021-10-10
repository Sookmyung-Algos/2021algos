1
2
3
4
5
6
7
8
9
10
11
12
13
14
15
16
17
18
19
20
21
22
23
24
25
26
27
28
29
30
31
32
33
34
35
36
37
38
39
40
41
42
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
 
typedef pair<int, int> P;
vector<P> arr;
 
bool comp(P a, P b){
    if(a.second == b.second){
        return a.first < b.first;
    }
    else{
        return a.second < b.second;
    }
}
 
int main(int argc, const char * argv[]) {
    int N;
    cin >> N;
    
    int l, r;//left:시작시간, right:종료시간
    for(int i = 0; i < N; i++){
        cin >> l >> r;
        arr.push_back(make_pair(l, r));
    }
    sort(arr.begin(), arr.end(), comp);
    
    int now = arr[0].second;
    int cnt = 1;
    for(int i = 1; i < N; i++){
        if(now <= arr[i].first){
            cnt++;
            now = arr[i].second;
        }
    }
    
    cout << cnt << '\n';
    
    return 0;
}
