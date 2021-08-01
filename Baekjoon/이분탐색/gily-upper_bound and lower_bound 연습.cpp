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
	while (end - start > 0) {  //start �� end �� ���� �ʰ�, ���� ���� ��
		mid = (start + end) / 2;    //�߾� index

		if (arr[mid] < key) { //key ���� �߾� ������ ũ��
			start = mid + 1;//mid ���� ����������
		}
		else {  //key ���� �߾Ӱ����� �۰ų� ������
			end = mid - 1;  //mid ���� ���� (�����ϴ� ������ key���� ������ ���� �� ū���� ���� �������� ����)
		}

	}
	// ���°�� �ƴ϶� �ش� Index�� ��ȯ�ϰ� ������ end + 1, start + 1 ��� end, start�� ����
	return end + 1;
}

int myupper_bound(int *arr, int n, int key)
{
	int start = 0;
	int end = n;
	int mid;

	while (end - start > 0) {
		mid = (start + end) / 2;

		if (arr[mid] <= key) {    //lower_bound�� �ٸ� ���� ���� '=' �ϳ�
			start = mid + 1;
		}
		else {
			end = mid - 1;
		}

	}
	// ���°�� �ƴ϶� �ش� Index�� ��ȯ�ϰ� ������ end + 1, start + 1 ��� end, start�� ����
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