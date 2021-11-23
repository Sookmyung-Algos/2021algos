// S1_11403 경로찾기

#include <algorithm>
#include <iostream>
#define INF 1000
using namespace std;

int N;
int matrix[101][101];

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(NULL); cout.tie(NULL);

  cin >> N;
  for (int i = 1; i <= N; i++){
    for (int j = 1; j <= N; j++) {
      cin >> matrix[i][j]; 
      if (matrix[i][j] == 0) matrix[i][j] = INF; // 초기화
    }
  }

  // 플로이드-와샬
  for (int i = 1; i <= N; i++)
    for (int j = 1; j <= N; j++)
      for (int k = 1; k <= N; k++)
        matrix[j][k] =
            min(matrix[j][k], matrix[j][i] + matrix[i][k]);

  // 결과 출력
  for (int i = 1; i <= N; i++) {
    for (int j = 1; j <= N; j++) {
      if (matrix[i][j] == INF)
        cout << 0 << ' ';
      else
        cout << 1 << ' ';
    }
    cout << '\n';
  }

  return 0;
}
