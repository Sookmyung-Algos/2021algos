#include <iostream>
#include <algorithm>
using namespace std;
 
#define INF 987654321
int vertex, edge;
int arr[101][101];
int from, to, weight;
 
void floyd_warshall() {
    for (int i = 1; i <= vertex; i++)          
        for (int j = 1; j <= vertex; j++)       
            for (int k = 1; k <= vertex; k++)   
                if (arr[j][i] != INF && arr[i][k] != INF)        
                    arr[j][k] = min(arr[j][k], arr[j][i] + arr[i][k]);
}
 
int main(){
    cin >> vertex >> edge;
    for (int i = 1; i <= vertex; i++) { 
        for (int j = 1; j <= vertex; j++) {
            arr[i][j] = INF;
        }
    }
    for (int i = 0; i < edge; i++) { 
        cin >> from >> to >> weight;
        if (arr[from][to] > weight) 
            arr[from][to] = weight;
    }
    floyd_warshall();
    for (int i = 1; i <= vertex; i++) {
        for (int j = 1; j <= vertex; j++) {
            if ( i == j || arr[i][j] == INF)
                cout << 0 << " ";
            else
                cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
