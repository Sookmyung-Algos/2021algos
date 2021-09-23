#include <iostream>
#include <algorithm>
#include <vector> 
#include <math.h>
#define A 10
using namespace std;

int N;
vector<int> vec;

int Prime(int now_num) {
    for (int div_num = 2; div_num <= sqrt(now_num); div_num++) // 루트에 해당하는 값까지 나눠보고 소수인지 체크 
        if (now_num % div_num == 0)
            return 0;
    return 1;
}
 
void dfs(int now_num, int depth) {
    if (Prime(now_num) == 1) {
        if (depth == N) { // 깊이가 N 이 되었으면 리턴
            vec.push_back(now_num);
            return;
        }
        for (int num = 1; num < A; num++)
            dfs(now_num * 10 + num, depth + 1);
    }
    else
        return;
}

int main() {
    ios::sync_with_stdio(false);
    cin >> N;
    for (int num = 2; num < A; num++)
        dfs(num, 1);
    int size = vec.size();
    for (int i = 0; i < size; i++)
        cout << vec[i] << "\n";
    return 0;
}
