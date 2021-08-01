// Date	 : 2021-07-31
// Title : 
// BOJ	 : 
// Genre : 
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#define endl "\n"

using namespace std;

int mylower_bound(int * arr, int n, int key)
{
	int start = 0;
	int end = n;

	int mid = n;
	while (end - start > 0) {  //start 가 end 와 같지 않고, 넘지 않을 때
		mid = (start + end) / 2;    //중앙 index

		if (arr[mid] < key) { //key 값이 중앙 값보다 크면
			start = mid + 1;//mid 보다 오른쪽으로
		}
		else {  //key 값이 중앙값보다 작거나 같으면
			end = mid - 1;  //mid 포함 왼쪽 (포함하는 이유는 key값과 같은게 없을 때 큰수중 가장 작은값을 위해)
		}

	}
	// 몇번째가 아니라 해당 Index를 반환하고 싶으면 end + 1, start + 1 대신 end, start를 넣자
	return end + 1;
}

int myupper_bound(int *arr, int n, int key)
{
	int start = 0;
	int end = n;
	int mid;

	while (end - start > 0) {
		mid = (start + end) / 2;

		if (arr[mid] <= key) {    //lower_bound와 다른 점은 여기 '=' 하나
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	// 몇번째가 아니라 해당 Index를 반환하고 싶으면 end + 1, start + 1 대신 end, start를 넣자
	return end + 1;
}

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main(void)
{
	init();
	int arr1[5] = { 4,6,9,11,15 };
	int arr2[5] = { 4,5,9,11,15 };
	int cnt = 0;
	for (int i = 0; i < sizeof(arr1) / arr1[0]; i++)
	{
		int X = 3;
		int left_idx = mylower_bound(arr2, sizeof(arr2) / arr2[0], abs(arr1[i] - X));
		int right_idx = myupper_bound(arr2, sizeof(arr2) / arr2[0], abs(arr1[i] + X));
		cnt += right_idx - left_idx;
		cout << abs(arr1[i] - X) << " <= " << arr2[left_idx - 1] << " " << arr2[right_idx - 2] << " <= " << abs(arr1[i] + X) << endl;
	}

	cout << cnt << endl;

	return 0;
}