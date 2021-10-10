#include <iostream>
#include <deque>
#include <algorithm>

using namespace std;

const int MAX = 3000000;

int N, D, K, C;
int result;
int sushi[MAX];
int sushiKind[3000 + 1] = { 0 };

deque<int> dq;

int main(void) {

        ios_base::sync_with_stdio(0);
        cin.tie(0); //cin 실행속도 향상
        cin >> N >> D >> K >> C;

        for (int i = 0; i < N; i++)
                 cin >> sushi[i];

        int cnt = 0;

        //첫 번째 스시부터 K개 덱에 넣고 종류 센다
        for (int i = 0; i < K; i++) {
                 dq.push_back(sushi[i]);
                 if (!sushiKind[sushi[i]]++) {
                         cnt++;
                 }
                 result = max(result, cnt);
        }

        //슬라이딩 윈도우 기법
        for (int i = 0; i < N - 1; i++){
                 //맨 앞 스시를 빼고
                 dq.pop_front();
                 //해당 스시의 종류가 덱에 없을 경우 cnt를 뺀다
                 if (!(--sushiKind[sushi[i]]))
                         cnt--;

                 //다음 스시를 덱에 넣는다
                 dq.push_back(sushi[(i + K) % N]);
             
                 //새로운 종류라면 cnt를 더해준다
                 if (!(sushiKind[sushi[(i + K) % N]])++)
                         cnt++;

                 //덱에 쿠폰 스시가 없다면
                 if (!sushiKind[C])
                         result = max(result, cnt + 1);

                 //덱에 쿠폰 스시가 있다면
                 else
                         result = max(result, cnt);
        }
        cout << result << "\n";
        return 0;
}
