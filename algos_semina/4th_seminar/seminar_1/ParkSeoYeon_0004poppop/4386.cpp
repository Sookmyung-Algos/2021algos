// 4386 별자리 만들기

/* 
크루스칼 알고리즘을 이용하여 최소스패닝트리(MST)를 구함
정점과 간선이 주어지고 간선들 각각의 가중치가 주어졌을 때 모든 정점을 이을 수 있는 간선의 최소 비용을 구하는 문제
*/

#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int N;
int parent[110];
double ans;
vector<pair<double, double>> star;  // 정점
vector<pair<double, pair<int, int>>> edge;  // 간선

double findDistance(double x, double y, double xx, double yy)   // 별자리들 간의 거리 계산
{
    double dx = (x - xx) * (x - xx);
    double dy = (y - yy) * (y - yy);
    double dis = sqrt(dx + dy);

    return dis;
}

int findParent(int A)  // 노드 A의 부모를 찾는 함수. 부모가 같은지 판단하기 위해 필요한 함수
{
    if (A == parent[A])
        return A;
    else 
        return parent[A] = findParent(parent[A]);
}

bool sameParent(int A, int B)
{
    A = findParent(A); // 노드 A의 부모 찾기
    B = findParent(B); // 노드 B의 부모 찾기
    if (A == B) 
        return true;    // 두 부모가 같음
    return false;   // 두 부모가 다름
}

void Union(int A, int B)    // 노드 A, B를 합치는 함수
{
    A = findParent(A);
    B = findParent(B);

    parent[B] = A;  // 노드 A의 부모도 A, 노드 B의 부모도 B가 되어 부모가 같아짐
}

void Solution()
{
    for (int i = 0; i < star.size(); i++)
    {
        double x = star[i].first;
        double y = star[i].second;

        for (int j = i + 1; j < star.size(); j++)
        {
            double xx = star[j].first;
            double yy = star[j].second;

            double dis = findDistance(x, y, xx, yy);
            edge.push_back(make_pair(dis, make_pair(i, j)));
        }
    }

    for (int i = 0; i < N; i++) 
        parent[i] = i;

    sort(edge.begin(), edge.end()); // 간선들의 가중치 오름차순 정렬

    for (int i = 0; i < edge.size(); i++)
    {
        double cost = edge[i].first;
        int Node1 = edge[i].second.first;
        int Node2 = edge[i].second.second;

        if (sameParent(Node1, Node2) == false) // 서로 다른 부모라면
        {
            Union(Node1, Node2);    // union함수로 두 개의 노드 연결
            ans = ans + cost;   // 간선들의 가중치 합 계산
        }
    }
    cout << ans << endl;
}

int main(void)
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);

    cin >> N;

    for (int i = 0; i < N; i++)
    {
        double a, b; 
        cin >> a >> b;
        star.push_back(make_pair(a, b));
    }

    Solution();

    return 0;
}
