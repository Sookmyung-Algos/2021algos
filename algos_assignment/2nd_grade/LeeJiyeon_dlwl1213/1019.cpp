#include <iostream> 

using namespace std; 
const int MAX = 10; 

long long numbers[MAX]; 

void calculate(int num, int increase) { 
    while (num) { 
        numbers[num % 10] += increase; 
        num /= 10; 
    } 
} // placeOfNum: []의 자리 수 

void func(int start, int end, int placeOfNum) { 
    while (start % 10 && start <= end) { 
        calculate(start, placeOfNum); 
        start++; 
    } 
    if (start > end) { 
        return; 
    } 
    while (end % 10 != 9 && start <= end) { 
        calculate(end, placeOfNum); 
        end--; 
    } 
    
    long long cnt = (end / 10 - start / 10 + 1); 
    for (int i = 0; i < MAX; i++) { 
        numbers[i] += cnt * placeOfNum; 
    } 
    func(start / 10, end / 10, placeOfNum * 10); 
} 

int main(void) { 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    int N; 
    cin >> N; 
    func(1, N, 1); 
    
    for (int i = 0; i < MAX; i++) { 
        cout << numbers[i] << " "; 
    } 
    cout << "\n"; 
    return 0; 
}
