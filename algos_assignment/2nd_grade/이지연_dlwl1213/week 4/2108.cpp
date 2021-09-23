#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int main(void) {
    ios_base::sync_with_stdio(false); 
    cin.tie(NULL);
  
    int N, temp, mean, mode = 0, min, max = 0;
    bool isSecond = false;
    cin>>N;
  
    vector<int> vec(N);
    vector<int> vec2(8001, 0);
  
    for(int i = 0; i < N; i ++){
        cin>>vec[i];
        mean += vec[i];
        temp = (vec[i] <= 0) ? abs(vec[i]) : vec[i] + 4000;
        vec2[temp]++;
        if(vec2[temp] > max)
            max = vec2[temp];
    }
    sort(vec.begin(), vec.end());

    for(int i = -4000; i < 4001; i++){  //빈도수가 가장 높은 값을 max에 저장한 뒤, 정렬하고 가장 작은 -4000부터 순회하여 max 값이랑 같은 값을 찾아줌. max 값이랑 같으면 mode에 저장하고 두 번째로 if 문을 타게 되면 mode에 저장한 뒤 반복이 종료되므로 두 번째로 작은 값이 mode에 저장되게 됨
        temp = i <= 0 ? abs(i) : i+4000;
        if(vec2[temp] == max){
            mode = i;
            if(isSecond)
                break;
            isSecond = true;
        }
    }

    cout<<round(mean/(double)N)<<'\n'; //mean에 입력된 값을 모두 더한 뒤, 마지막에 double형으로 나눠서 round 함수를 통해 반올림하여 산술평균 구함
    cout<<vec[round(N/2)]<<'\n'; //정렬된 벡터에서 중앙 인덱스 값을 찾아서 출력
    cout<<mode<<'\n';
    min = vec[0];
    max = vec[vec.size()-1];
    cout<<max - min<<'\n';  //정렬한 뒤 가장 큰 값에서 작은 값을 빼면 입력받은 수의 범위가 됨
}
