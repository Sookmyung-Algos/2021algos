#include <iostream>

#include <vector>

#include <queue>

#include <algorithm>

using namespace std;

 

const int MAX = 300000;

 

int N, K;

int bag[MAX];

pair<int, int> jewelry[MAX];

priority_queue<int> pq; //maxHeap 사용

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0); //cin 실행속도 향상

        cin >> N >> K;

       

        for (int i = 0; i < N; i++)

                 cin >> jewelry[i].first >> jewelry[i].second;

        for (int i = 0; i < K; i++)

                 cin >> bag[i];

 

        //보석(무게 기준)과 가방 오름차순 정렬

        sort(jewelry, jewelry + N);

        sort(bag, bag + K);

 

        long long result = 0;

        int idx = 0;

        //무게제한이 낮은 가방부터 최대한 비싼 보석을 넣는 방법

        for (int i = 0; i < K; i++)

        {

                 //i 번째 가방의 무게제한에 충족하는 보석 다 넣음

                 while (idx < N && jewelry[idx].first <= bag[i])

                         pq.push(jewelry[idx++].second);

 

                 //pq의 루트에는 현재 기준 제일 비싼 보석이 들어있음

                 if (!pq.empty())

                 {

                         result += pq.top();

                         pq.pop();

                 }

        }

        cout << result << "\n";

        return 0;

}
