#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);

    int testCase = 0;
    int count = 0;
    int documentNum, docuPosition, important;
    
    cin >> testCase;
    
    for (int i = 0; i < testCase; i++) {
        count = 0;
        cin >> documentNum >> docuPosition;
        
        queue<pair<int, int>> queue;
        priority_queue<int> priorityQueue;
        
        for (int j = 0; j < documentNum; j++){
            cin >> important;
            queue.push({j, important});
            priorityQueue.push(important);
        }
        
        while (!queue.empty()) {
            int k = queue.front().first;
            int v = queue.front().second;
            
            queue.pop();
            
            if(priorityQueue.top() == v) {
                priorityQueue.pop();
                count++;
                if(k == docuPosition) {
                    cout << count << endl;
                    break;
                }
            } else {
                queue.push({ k, v});
            }
        }
    }
}
