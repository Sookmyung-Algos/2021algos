#include <iostream>
#include <vector>

using namespace std;

int main(){
	int n;
	cin >> n;
	vector<int> DP_max(3, 0), DP_min(3, 0);  //최대값과 최소값을 저장
	int left, mid, right;
	for (int i = 0; i < n; i++){
		cin >> left >> mid >> right;
		if (i == 0) 	DP_max = DP_min = { left, mid, right };
		else{
			vector<int> temp_max = DP_max, temp_min = DP_min;
			DP_max[0] = left + max(temp_max[0], temp_max[1]);
			DP_max[1] = mid + max(temp_max[0], max(temp_max[1], temp_max[2]));
			DP_max[2] = right + max(temp_max[1], temp_max[2]);
			DP_min[0] = left + min(temp_min[0], temp_min[1]);
			DP_min[1] = mid + min(temp_min[0], min(temp_min[1], temp_min[2]));
			DP_min[2] = right + min(temp_min[1], temp_min[2]);
		}  //왼쪽 입력은 왼쪽값과 가운데값중에서 선택, 가운데 입력은 세 수중에서 선택, 오른쪽입력은 오른쪽값과 가운데값중에서 선택하도록 한다.
	}

	cout << max(DP_max[0], max(DP_max[1], DP_max[2])) << ' ' <<
		min(DP_min[0], min(DP_min[1], DP_min[2]));

	return 0;
}
