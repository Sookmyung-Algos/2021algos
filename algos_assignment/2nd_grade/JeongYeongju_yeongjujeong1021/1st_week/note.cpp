/*
* 알고리즘 문제 해결에서 C++을 많이 사용하는 이유
- low-level언어이므로 속도가 매우 빠름
- 참고할 수 있는 예제 코드 많음
- 가끔 C++ 사용을 강제하는 문제

* C를 통한 문제 해결과의 차이점
- cin, cout을 통한 입·출력과 namespace, i/o header의 변화, string, bool type 등
- 정렬 함수, 자료구조 등이 이미 구현되어 있음 (C++ STL)
- C언어 표준 함수 사용 가능 (#include <c헤더이름>, <stdio.h> -> <cstdio>)

* namespace
- 모든 식별자(변수, 함수, 형식 등의 이름)가 고유하도록 보장하는 코드 영역
- 같은 스코프 안의 식별자 간 이름 충돌을 막기 위한 장치
- 범위 지정 연산자(::) 사용

* C++ 입출력
- C: scanf(), printf() / <stdio.h> 헤더 / 굉장히 빠름 / 포맷 지정자 필요
- C++: cin, cout / <iostream> 헤더 / 상대적으로 느림 / 포맷 지정자를 사용할 필요 없음

* Fast I/O가 왜 필요한가?
- 데이터 입/출력은 프로그램의 실행시간 중 상당 부분을 차지함
- 입/출력 속도를 빠르게 하는 것만으로도 프로그램의 실행시간을 줄일 수 있음

* C와 C++의 입출력 속도 비교
- C(C11)의 가장 대중적인 입력 방법(scanf)보다 C++(C++17)의 입력 방법(cin)이 2배 이상 더 느림
- 이러한 문제를 해결할 방법 = Fast I/O

* cin/cout 대신 scanf(), printf() 사용
- 가장 쉬운 방법
- <iostream>헤더에 <cstdio>도 포함되어 있으므로 따로 새로운 헤더 추가할 필요x

* Fast I/O(1)
- sync 끊어주기
- C++의 cin/cout이 느린 이유는 C의 입출력 버퍼와 C++의 입출력 버퍼를 동기화시켜야 하기 때문
- 또, cin과 cout은 서로 묶여있는(tie) 관계이므로 입력이 들어오기 전에 모든 출력을 방출하는데, 이것도 C++의 입출력 속도를 느리게 하는 원인 중 하나
- ios_base::sync_with_stdio(false);와 cin.tie(0); cout.tie(0); 코드를 추가하여 입출력 스트림의 동기화를 해제하고 untie하게 만들어 입출력 시간을 크게 단축할 수 있음

* Fast I/O(2)
- endl 대신 '\n' 사용
- endl은 개행하는 역할뿐만 아니라 출력 버퍼에 쌓인 내용을 한꺼번에 출력하는 역할(flush)을 함

* STL
- STL = 표준 템플릿 라이브러리(Standard Template Library)
  컨테이너: 데이터를 저장하는 객체. vector, pair, deque, list, set, map, stack 등
  알고리즘: 검색(lower_bound(), upper_bound(), binary_search())이나 정렬(sort()) 등
  반복자(Iterator): 컨테이너 순회를 위한 일반화된 방법 제공(반복자를 이용하면 같은 로직으로 모든 종류의 컨테이너를 순회할 수 있음)
  함수자(functor)

* STL Container: Vector
- C++의 동적 배열 삽입 순서에 따라 상대적인 위치를 가짐
- 배열과 동일하게 인덱스를 통해 접근 가능 (ex. v[idx] = value)

* C++ STL: Vector의 선언과 사용법
  #include <vector>
  vector<class or type> name;
- Vector 주요 메서드
  v.front(): 벡터의 첫번째 요소
  v.back(): 벡터의 마지막 요소
  v.push_back(item): 벡터의 마지막에 새로운 요소 삽입
  v.emplace_back(item): 벡터의 마지막에 새로운 요소 삽입 (메모리 재할당이 일어나지 않아서 시간이 push_back(item)보다 짧음)
  v.pop_back(): 벡터의 마지막 요소를 제거
  v.erase(index)/v.erase(start, end): 벡터의 해당 인덱스 또는 범위에 해당하는 요소들을 제거
  v.insert(index, item): 벡터의 해당 인덱스에 요소 삽입
  (erase, insert는 시간복잡도가 커서 문제 해결에 잘 사용하지 않음)
  v.size(): 벡터의 크기
- 반복문으로 vector 순회
1) 시작 인덱스, 종료조건, 증감연산 명시
  for (int i = 0; i < v.size(); i++) { cout << v[i] << '\n'; }
  i = 벡터의 인덱스이며, v[i]의 형태로 벡터의 값에 접근할 수 있음
2) 범위 기반 for문
  for (auto i: v) { cout << i << '\n'; }
  colon 좌측에는 변수 타입과 변수 명, 우측에는 순회 대상 container 이름
  index를 통한 접근이 아닌 변수 그 자체로 접근 가능
  사용이 편해보이지만 범위 기반 for문에서는 배열 요소 값을 변경할 수 없다는 단점 有
  i = 벡터 요소의 값이며, 시작과 종료조건을 알려주지 않아도 됨

* Vector는 언제 사용할까?
- 트리나 그래프의 구조를 표현할 때 사용
  vector<int> v[MAX_SIZE];
  i번째 벡터 배열에는 i번째 노드와 연결되어 있는 노드의 번호를 push함으로써 노드들의 연결 관계를 표현할 수 있음
  그 외에도, 동적 배열 자료구조가 필요한 모든 상황에서 Vector를 사용할 수 있음

* STL Container: Stack
- 후입선출(LIFO): 가장 나중에 들어간 것이 가장 먼저 나옴
- LIFO의 특징이 필요한 문제, 특히 짝맞추기 문제에 많이 쓰임

* C++ STL: Stack의 선언과 사용법
  #include <stack>
  stack<class or type> name;
- 주요 메서드
  s.empty(): 스택이 비었는지 확인, 비었으면 true, 비지 않았으면
  false s.top(): 스택의 가장 상위 요소를 리턴
  s.push(item): item을 스택에 추가
  s.pop(): 가장 최근에 들어간 요소를 스택에서 제거. 반환값 없으니 항상 s.top()을 통해 미리 값을 저장해야 함
  s.size(): 스택의 크기

* Stack은 어떻게 사용할 수 있을까?
- 백준 3986 : 좋은 단어 - 글자 짝맞추기 문제 ABBA->good! AABB->good! ABAB->bad!
  1. 단어를 한 글자씩 검사
  2. 스택의 top에 있는 글자가 현재 검사중인 글자와 같다면 pop, 같지 않다면 push
  3. 단어의 마지막 글자까지 검사가 끝난 후 스택이 비어있다면 좋은 단어

* STL Container: Queue
- 선입선출(FIFO): 가장 먼저 들어간 것이 가장 먼저 나옴
- 순서를 고려한 처리가 필요할 때, 특히 BFS(너비 우선 탐색)에서 사용 (BFS는 트리 탐색할 때 사용)

* C++ STL: Queue의 선언과 사용법
  #include <queue>
  queue<class or type> name;
- 주요 메서드
  q.empty(): 큐가 비었는지 확인, 비었으면 true, 비지 않았으면 false
  q.front(): 큐의 첫 요소를 리턴
  q.back(): 큐의 마지막 요소를 리턴
  q.push(item): item을 큐에 추가
  q.pop(): 가장 첫 요소를 큐에서 제거. 반환값 없으니 항상 q.front()을 통해 미리 값을 저장해야 함
  q.size(): 큐의 크기

* Queue는 어떻게 사용할 수 있을까?
- 백준 1158 요세푸스 문제 - 환형 큐
  1. 큐를 순회하며 (cnt의 배수)번째마다 큐의 가장 앞에 있는 수를 출력 & pop
  2. (cnt의 배수)번째가 아니라면 가장 앞에 있는 수를 pop하고 가장 뒤로 push
  3. 큐가 빌 때까지 반복
  
* STL Container: Pair
- 데이터 쌍을 표현할 수 있음
- 짝을 이루는 데이터를 표현할 때 사용

* C++ STL: Pair의 선언과 사용법
  #include <utility> (<vector> 또는 <algorithm> 헤더를 추가해도 됨)
  pair<class or type, class or type> name;
- 멤버, 주요 메서드
  p.first: 페어 p의 첫번째 요소를 반환
  p.second: 페어 p의 두번째 요소를 반환
  make_pair(a, b): a와 b를 쌍으로 묶는 pair를 생성

* pair는 언제 사용할까?
- 가중치가 있는 그래프를 표현할 때 벡터와 함께 사용
  vector<pair<int(node), int(weight)>> v[MAX_SIZe];
  특히 다익스트라 문제를 해결할 때 많이 사용됨
- 엘레먼트의 우선순위를 표현할 때 사용
- 다른 컨테이너(queue나 vector, map 등)와 함께 사용하는 경우가 많음

* STL Container: Map
- key와 value가 쌍(pair)으로 저장되며, key를 통해 value에 빠르게 접근 가능
- key는 오름차순으로 정렬되어 저장
- key는 중복되지 않음(중복 key는 multimap 컨테이너에서 사용 가능)

* Map의 선언과 사용법
  #include <map>
  map<class or type, class or type> name;
- 주요 메서드
  m.insert(p): 맵에 pair 객체인 p를 삽입
  m.size(): 맵의 크기
  m.find(key): 맵 내에서 key라는 키를 가진 요소의 위치(반복자)를 리턴, 없을 시 m.end() 리턴
  m[key] = value; 명령을 통해 원소(key, value)를 추가, 수정 가능

* Map은 언제 사용할까?
- 특정 키워드에 대한 정보를 저장하고 빠르게 참조해야 할 때 사용
- 백준 4358 - 생태학

* STL Container: Set
- 원소의 중복을 허용하지 않음
- 자동적으로 정렬된 상태를 유지

* C++ STL: Set의 선언과 사용법
  #include <set>
  set<class or type> name;
- 주요 메서드
  s.insert(value): s에 값 삽입
  s.find(value): s 내에서 value 값을 탐색하여 해당 위치의 iterator 반환, 없다면 s.end() 반환
  s.erase(k): s에 저장된 val 요소 삭제

* set은 언제 사용할까?
- 요소들을 중복되지 않게, 정렬된 상태로 저장하고 싶을 때 사용
- 중복 요소 없는 vector를 만들고 싶을 때 assign() 메서드와 함께 사용
  v.assign(InputIterator first, InputIterator last)
  벡터 v에 원래 들어있던 내용을 모두 지우고 first부터 last까지의 원소로 새롭게 채우는 메서드
  벡터 v의 내용을 set s의 시작부터 끝까지의 원소로 채움으로써 벡터 v에는 중복된 요소가 없게 됨

* STL Iterator(반복자)
- 컨테이너에 저장된 원소를 순회하고 접근하는 일반화된 방법을 제공
- 컨테이너와 알고리즘이 하나로 동작하게 묶어주는 인터페이스 역할
  (컨테이너 전용 pointer라고 생각하면 됨)
- Iterator는 STL 컨테이너의 메모리 상 주소를 가리킴
  set<string> s;
- method
  s.begin() 처음을 가리킴 (v.begin() + 2 는 세번째 원소를 가리킴)
  s.end() 마지막 다음을 가리킴
  vector<int> v;

* Iterator를 통한 컨테이너 순회
  vector<int>::iterator iter;
  for (iter = v.begin(); iter != v.end(); iter++) { cout << iter << ' '; }
  container<type>::iterator 타입의 반복자를 선언하여 컨테이너 전체를 순회할 수 있으며, 애스터리스크(*)를 붙여 컨테이너 내 요소에 접근할 수 있음
  for (auto iter = v.begin(); iter != v.end(); iter++) { cout << *iter << ' '; }
  auto 타입(타입 추론)을 통해 더 간단하게 코드를 작성할 수 있음

* STL Algorithm
- 정렬과 이진 탐색, upper & lower bound, swap 등
  #include <algorithm>
  1) sort(s, e, function): O(nlogn) 퀵 정렬
  2) stable_sort(s, e, function): O(nlogn) 합병 정렬 (sort와의 차이점은 정렬 이후에도 값이 같은 원소들의 상대적인 순서들이 유지됨)
  3) binary_search(s, e, val): O(logn) 이분 탐색
  4) lower_bound(s, e, val): O(logn) [s, e) 구간에서 val 이상인 첫 값의 위치를 반환
  5) upper_bound(s, e, val): O(logn) [s, e) 구간에서 val 값을 초과하는 첫 값의 위치를 반환
  (upper_bound에서 lower_bound를 빼면 해당 범위 내에 변수가 몇 개인지 알 수 있음)

* 정렬: algorithm 헤더의 sort()와 stable_sort()
  기본적으로 오름차순으로 정렬, 배열의 시작점 주소, 마지막 주소 + 1 (반열림 구간이기 때문)
  1) sort(s, e, function): O(n log n)
  - 구간 [s, e)에서 정렬
  - function은 비교 함수, 옵션 (선택 사항)
  - 배열: sort(arr, arr + length, function)
  - 벡터: sort(v.begin(), v.end(), function)
  2) stable_sort(s, e, function): O(n log n)
  - 값이 같은 원소들의 상대적인 순서 유지
  - 구간 [s, e)에서 정렬
  - function은 비교 함수, 옵션

* 정렬 함수 이용하기: greater<type>, less<type>
  #include <algorithm>, #include <functional>
  less<type>: 첫번째 인자가 두번째 인자보다 작으면 true 반환 -> 오름차순
  greater<type>: 첫번째 인자가 두번째 인자보다 크면 true 반환 -> 내림차순

* 커스텀 정렬: 정렬 함수의 세번째 인자 이용
  sort(s, e, function), stable_sort(s, e, function)
  - 백준 10814: 나이순 정렬 나이와 이름을 입력받고 나이순으로 정렬, 나이가 같다면 가입한 순으로 정렬 구조체를 이용하여 사람별 나이, 이름, 가입 순서를 저장
    cmp 함수 안에서는 올바르게 정렬된 상태를 부등호로 표현하여 반환하도록 함
*/
