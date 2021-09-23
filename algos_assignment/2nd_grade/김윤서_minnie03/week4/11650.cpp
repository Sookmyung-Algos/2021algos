#include <iostream>
#include <vector>
using namespace std;

class Point { //Point라는 클래스를 만들어 x,y의 순서쌍을 선언
public:
	int x;
	int y;
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
};
vector<Point>temp; //Point 벡터 temp를 선언
vector<Point>arr; //Point 벡터 arr를 선언

void merge(int left, int mid, int right) {
	int left_end, num_elements, tmp_pos;
	left_end = mid - 1;
	tmp_pos = left;
	num_elements = right - left + 1; //left부터 right까지의 원소의 개수
	while (left <= left_end && mid <= right) {
		if (arr[left].x < arr[mid].x) //arr배열의 맨왼쪽 원소의 x좌표가 mid의 x좌표보다 작으면
			temp[tmp_pos++] = arr[left++]; //temp배열에 arr맨왼쪽의 원소 삽입
		else if (arr[left].x > arr[mid].x) //arr배열의 맨왼쪽 원소의 x좌표가 mid의 x좌표보다 크면
			temp[tmp_pos++] = arr[mid++]; //temp배열에 arr배열의 mid 원소 삽입
		else { //arr배열의 맨왼쪽 원소의 x좌표와 mid의 x좌표가 같으면
			if (arr[left].y < arr[mid].y) //y좌표를 비교하여 left의 y좌표가 더 작으면
				temp[tmp_pos++] = arr[left++]; //temp배열에 arr배열의 left 원소 삽입
			else //mid의 y좌표가 더 작으면
				temp[tmp_pos++] = arr[mid++]; //temp배열에 arr배열의 mid 원소 삽입
		}
	}
	while (left <= left_end)temp[tmp_pos++] = arr[left++]; //temp에 arr의 왼쪽원소부터 삽입
	while (mid <= right)temp[tmp_pos++] = arr[mid++]; //temp에 arr의 가운데 원소부터 삽입
	for (int i = 0; i < num_elements; i++) { //temp에 저장된 원소 arr에 복사
		arr[right] = temp[right];
		right -= 1;
	}
}

void merge_sort(int left, int right) {
	int mid;
	if (left < right) {
		mid = (left + right) / 2;
		merge_sort(left, mid); //왼쪽 segment 분할
		merge_sort(mid + 1, right); //오른쪽 segment 분할
		merge(left, mid + 1, right); //병합
	}
}

int main() {
	int n, x, y;
	cin >> n; //점의 개수 입력
	for (int i = 0; i < n; i++) {
		cin >> x >> y;
		arr.push_back(Point(x, y)); //입력받은 x,y 좌표값을 arr vector의 x,y값에 저장
		temp.push_back(Point(x, y)); //입력받은 x,y 좌표값을 temp vector의 x,y값에 저장
	}
	merge_sort(0, n - 1);
	for (int i = 0; i < n; i++) //합병정렬 결과 출력
		cout << arr[i].x << " " << arr[i].y << "\n";
}
