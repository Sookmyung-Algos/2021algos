#include <iostream>
using namespace std;
// 유니온파인드: 다리를 모두 유니온한 후 연결되지 않은 다리를 찾는다

int find(int x);
void merge(int x, int y);
bool isUnion(int x, int y);

int arr[300001];

int main(){
    int n; // 섬의 개수
    int x, y;
    
    cin >> n;
    for (int i=0; i<300001; i++)    arr[i]=i; // 섬 번호 넣기
    for (int i=0; i<n-2; i++){
        cin >> x >> y;
        merge(x,y);
    }
    for (int i=2; i<=n; i++){
       if (!isUnion(1,i)){ // 유니온에 없는 경우 출력
           cout << 1 << " " << i;
           return 0;
       }
    }
    return 0;
}

int find(int x){ // 섬 번호를 찾는 함수
    if (arr[x] == x)
		return x;
	return arr[x] = find(arr[x]);
}

void merge(int x, int y){
    x = find(x);
	y = find(y);
	if (x != y)    arr[y] = x;
}

bool isUnion(int x, int y){
    x = find(x);
	y = find(y);
	if (x == y) // 유니온에 있는 경우
		return true;
	return false;
}
