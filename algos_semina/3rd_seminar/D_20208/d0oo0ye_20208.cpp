#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

typedef struct Struct
{
	int y;
	int x;
	bool checked;
}val;

int n = 0, m = 0, h = 0;
int result = 0;
int arr[10][10] = { 0, };

val house;
vector <val> mint;

void dfs(int y, int x,int cur, int cnt, int hp) {
	if (cnt > result) {
		if (abs(y - house.y) + abs(x - house.x) <= hp)
			result = cnt;
	}
  
	if (hp <= 0)
		return;
  
	for (int i = 0; i < mint.size(); i++) {
			int len = abs(mint[i].y - y) + abs(mint[i].x - x);
    
			if (len <= hp && mint[i].checked == 0) {
				mint[i].checked = 1;
        
				dfs(mint[i].y, mint[i].x, i+1, cnt + 1, hp - len + h);
				mint[i].checked = 0;
			}
			
	}

}

int main() {
	cin >> n >> m >> h;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++){
			int temp = 0;
			cin >> temp;
      
			if (temp == 1)
				house.y = i, house.x = j;
      
			else if (temp == 2)
				mint.push_back({ i,j,0 });
		}
	}
	
	dfs(house.y,house.x,0, 0, m);
  
	cout << result  << endl;
	return 0;
}
