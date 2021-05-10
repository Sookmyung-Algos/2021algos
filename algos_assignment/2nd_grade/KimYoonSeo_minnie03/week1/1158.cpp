include <iostream>
#include <queue>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	int n, k,count=0;
	cin >> n >> k;

	queue<int> yo;

	for (int i = 1; i <= n; i++) { //큐에 1~n까지 push
		yo.push(i);
	}

	cout << "<"; 

	while (yo.size() > 1) {
		count++;
		
		if (count % k == 0) { //count%k==0 이면 맨앞 요소 출력
			cout << yo.front() << ", ";
		}
		else { //아니면 맨뒤에 push
			yo.push(yo.front());
		}
		yo.pop(); //맨앞 요소 pop
	}

	cout << yo.front() << ">";
	return 0;
}
