#include<iostream>
#include<vector>
#include<queue>

#define INF 987654321
using namespace std;

int N, E, A, B, Answer;
int Dist[801];
vector<pair<int, int>> V[801];

int Min(int A, int B) { if (A < B) return A; return B; }

void Dijkstra(int Start){
	priority_queue<pair<int, int>> PQ;
	Dist[Start] = 0;
	PQ.push(make_pair(0, Start));

	while (PQ.empty() == 0){
		int Cost = -PQ.top().first;
		int Cur = PQ.top().second;
		PQ.pop();

		for (int i = 0; i < V[Cur].size(); i++){
			int Next = V[Cur][i].first;
			int nCost = V[Cur][i].second;

			if (Dist[Next] > Cost + nCost){
				Dist[Next] = Cost + nCost;
				PQ.push(make_pair(-Dist[Next], Next));
			}
		}
	}
}


int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);

	cin >> N >> E;
	for (int i = 0; i < E; i++) {
		int a, b, c; cin >> a >> b >> c;
		V[a].push_back(make_pair(b, c));
		V[b].push_back(make_pair(a, c));
	}
	cin >> A >> B;
	
	bool Flag1, Flag2;
	Flag1 = Flag2 = true;

	for (int i = 1; i <= N; i++) Dist[i] = INF;
	Dijkstra(1);
	int Route1 = Dist[A];
	int Route2 = Dist[B];
	if (Route1 == INF) Flag1 = false;
	if (Route2 == INF) Flag2 = false;

	for (int i = 1; i <= N; i++) Dist[i] = INF;
	Dijkstra(A);
	if (Flag1 == true) Route1 = Route1 + Dist[B];
	if (Flag2 == true) Route2 = Route2 + Dist[B];

	for (int i = 1; i <= N; i++) Dist[i] = INF;
	Dijkstra(B);
	if (Flag1 == true) Route1 = Route1 + Dist[N];

	for (int i = 1; i <= N; i++) Dist[i] = INF;
	Dijkstra(A);
	if (Flag2 == true) Route2 = Route2 + Dist[N];

	if (Flag1 == false && Flag2 == false) Answer = -1;
	else Answer = Min(Route1, Route2);

	if (Answer == INF) Answer = -1;

	cout << Answer << "\n";

	return 0;
}
