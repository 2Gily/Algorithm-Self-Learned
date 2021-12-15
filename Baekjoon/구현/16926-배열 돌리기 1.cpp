#include <iostream>
#include <algorithm>


using namespace std;

int map[301][301];
int N, M, R;

//오, 아, 왼, 위
int dr[4] = { 0,1,0,-1 };
int dc[4] = { 1,0,-1,0 };

void rotate(int box) {

	for (int i = 0; i < box; i++) {   //박스수만큼 반복(1칸 전진)(시작점은 start, start+1, start+2..)
		int startVal = map[i][i];       //각 박스 시작은 [0][0] -> [1][1] -> [2][2]...
		int r = i;
		int c = i;

		int k = 0;
		while (k < 4) {

			int nr = r + dr[k];     //map[nr][nc]는 옮길 대상임 (map[r][c]로 옮겨야 함)
			int nc = c + dc[k];

			if (nr == i && nc == i) break;
			if (i <= nr && nr < N - i && i <= nc && nc < M - i) {

				//차례로 시계 반대방향으로 옮김
				map[r][c] = map[nr][nc];
				r = nr;
				c = nc;

			}
			else {       //다음에 옮길 칸이 배열 범위 넘어가버리면 해당 라인은 다 옮긴거라서 k 증가
				k++;
			}
		}
		map[i + 1][i] = startVal; //처음에 시작지점 빼놨던거 마지막에 빈 자리에 넣어줌.

	}


}


int main() {

	cin >> N >> M >> R;

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cin >> map[i][j];
		}
	}

	int cnt = min(N, M) / 2;       //  박스 수

	for (int i = 0; i < R; i++) {       //반복문 한번에 1칸 전진하는것. 총 R칸 전진
		rotate(cnt);
	}


	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			cout << map[i][j] << " ";
		}cout << "\n";
	}



	return 0;
}