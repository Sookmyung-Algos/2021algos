#include <iostream>
#include <vector>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

	vector<pair<int, int>> dot; //점의 위치를 저장해놓을 벡터 dot

	int a, b, c;
	int x1, x2, y1, y2;
	cin >> a >> b >> c;
	cin >> x1 >> x2 >> y1 >> y2;
	
	//위험지역 직사각형의 네 점을 dot 벡터에 push
	dot.push_back({ x1,y1 }); 
	dot.push_back({ x1,y2 });
	dot.push_back({ x2,y1 });
	dot.push_back({ x2,y2 });

	int down = 0,up=0;

	for (int i = 0; i < 4; i++) { //네 점을 탐색하며
		//만약 위험지역의 점 위치가 선보다 아래이거나 선을 지날 때
		if (dot[i].first * a + dot[i].second * b <= -c) down++; 
		//만약 위험지역의 점 위치가 선보다 위거나 선을 지날 때
		if (dot[i].first * a + dot[i].second * b >= -c) up++;
	}

	//네 점이 모두 선을 기준으로 같은 영역에 있을 때 
	if (down == 4 || up == 4) cout << "Lucky";
	//네 점이 모두 선을 기준으로 같은 영역에 있는 것이 아닐 때
	else cout << "Poor";

	return 0;
}
