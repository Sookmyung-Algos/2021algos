#include<iostream>
#include<queue>
using namespace std;

int arr[100001];

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) cin >> arr[i];

	priority_queue<int> maxq, minq;
	for (int i = 0; i < n; i++){
		if (maxq.size() > minq.size()) minq.push(-arr[i]);
		else maxq.push(arr[i]);

		if (maxq.empty() == false && minq.empty() == false){
			if (maxq.top() > -minq.top()){
				int Max_Value = maxq.top();
				int Min_Value = -minq.top();

				maxq.pop(); minq.pop();

				maxq.push(Min_Value);
				minq.push(-Max_Value);
			}
		}
		cout << maxq.top() << "\n";
	}

	return 0;
}
