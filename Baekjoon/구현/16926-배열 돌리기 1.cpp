#include <iostream>
#include <algorithm>


using namespace std;

int map[301][301];
int N, M, R;

//��, ��, ��, ��
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void rotate(int box) {

	for (int i = 0; i < box; i++) {   //�ڽ�����ŭ �ݺ�(1ĭ ����)(�������� start, start+1, start+2..)
		int startVal = map[i][i];       //�� �ڽ� ������ [0][0] -> [1][1] -> [2][2]...
		int r = i;
		int c = i;

		int k = 0;
		while (k < 4) {

			int nr = r + dr[k];     //map[nr][nc]�� �ű� ����� (map[r][c]�� �Űܾ� ��)
			int nc = c + dc[k];

			if (nr == i && nc == i) break;
			if (i <= nr && nr < N - i && i <= nc && nc < M - i) {

				//���ʷ� �ð� �ݴ�������� �ű�
				map[r][c] = map[nr][nc];
				r = nr;
				c = nc;

			}
			else {       //������ �ű� ĭ�� �迭 ���� �Ѿ������ �ش� ������ �� �ű�Ŷ� k ����
				k++;
			}
		}
		map[i + 1][i] = startVal; //ó���� �������� �������� �������� �� �ڸ��� �־���.

	}


}


int main() {

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = min(N, M) / 2;       //  �ڽ� ��

	for (int i = 0; i < R; i++) {       //�ݺ��� �ѹ��� 1ĭ �����ϴ°�. �� Rĭ ����
		rotate(cnt);
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}



	return 0;
}