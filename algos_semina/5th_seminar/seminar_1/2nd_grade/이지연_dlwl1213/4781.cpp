#include <iostream>
#include <algorithm>
#include <cstring> //memset

using namespace std;

const int MAX = 5000 + 1;
int N, C; //사탕 종류의 수를 변수 N, 칼로리를 변수 C로 지정해줌
double M, P; //돈의 양을 변수M, 사탕 가격을 변수 P로 지정해줌

pair<int, int> candy[MAX];
int cache[100 * 100 + 1];

int maxCalorie(int cash){
        int &result = cache[cash];
        if (result != -1)
                 return result;
        result = 0;
        for (int i = 0; i < N; i++){
                 //잔여금액을 초과해서 살 수없으므로 조건문 지정
                 if (cash - candy[i].second >= 0)
                         result = max(result, candy[i].first + maxCalorie(cash - candy[i].second));
        }
        return result;
}

int main(void){
        while (1){
                 memset(cache, -1, sizeof(cache));
                 cin >> N >> M;
                 if (N == 0 && M == 0.00)
                         break;

                 for (int i = 0; i < N; i++){
                         cin >> C >> P;
                         candy[i] = make_pair(C, (int)(P * 100 + 0.5)); 
                 }
                 cout << maxCalorie((int)(M * 100 + 0.5)) << endl;
        }
        return 0;
}
