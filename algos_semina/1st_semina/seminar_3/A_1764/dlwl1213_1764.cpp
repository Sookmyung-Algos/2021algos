#include<iostream>
#include<algorithm>
#include<vector>
#include<cstdio>

using namespace std;

int main() {
    int N,M;
    scanf("%d %d", &N, &M);

    vector<string> v;
    vector<string> v_result;

    v.resize(N);
    for (int i = 0; i < N; i++) {
        cin >> v[i];   
    }
   
    sort(v.begin(), v.end());     //오름차순으로 정렬

    string str;
    for (int j = 0; j < M; j++) {
        cin >> str;

        if (binary_search(v.begin(), v.end(), str)) { 
            v_result.push_back(str);
        }
    }

    sort(v_result.begin(), v_result.end());      //오름차순으로 정렬

    printf("%d\n", (int)v_result.size());
    for (int i = 0; i < v_result.size(); i++) {   //듣도 보도못한 사람의 이름 출력
        printf("%s\n", v_result[i].c_str());
    }

    return 0;
}
