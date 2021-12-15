#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
#include <cstdio>
#include <cmath>
#include <climits>
#define endl "\n"

using namespace std;

int A, B, N, M;

int check[102][102];

int dx[] = { -1,0,1,0 };
int dy[] = { 0,1,0,-1 };

struct Robot {
	int x;
	int y;
	int dir;
};

vector<Robot> vt;

void init()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
}

int main() 
{
	init();
	cin >> A >> B;
	cin >> N >> M;

	int x, y, dir;
	char d;

	//index 1���� �����ϱ����� �ƹ� �� �־���
	vt.push_back({ -1, -1, -1 });

	for (int i = 1; i <= N; i++) 
	{
		cin >> x >> y >> d;

		if (d == 'N') dir = 1;
		else if (d == 'E') dir = 2;
		else if (d == 'S') dir = 3;
		else dir = 0;

		vt.push_back({ x, y, dir });
		check[x][y] = i;
	}


	int num;
	char order;
	int orderCnt;

	int crashWall = 0; //���� �ε��� �κ� ��ȣ�� ����
	int lastRobot = 0; //�ٸ� �κ��� �ε��� ���� �̵� �κ��� ����
	int crashRobot = 0; //���� �̵����� �κ��� �ε��� �ٸ� �κ��� ��ȣ�� ����


	while (M--) 
	{
		cin >> num >> order >> orderCnt;

		//�߸��� ����� �߻��ؼ� ���̳� �κ��� �ε��� ��� �Ѿ�� �Է¸� ��� �޴´�.
		if (crashWall || crashRobot) continue;

		x = vt[num].x;
		y = vt[num].y;
		dir = vt[num].dir;

		//��� �ݺ� Ƚ����ŭ �ݺ�
		while (orderCnt--) 
		{
			if (order == 'L') 
			{
				//���� 90�� ȸ��
				dir = (dir + 3) % 4;
				vt[num].dir = dir;
			}
			else if (order == 'R') 
			{
				//������ 90�� ȸ��
				dir = (dir + 1) % 4;
				vt[num].dir = dir;
			}
			else if (order == 'F') 
			{

				//���� ��ġ ����ش�.
				check[x][y] = 0;

				x = x + dx[dir];
				y = y + dy[dir];

				if (x < 1 || y < 1 || x > A || y > B) 
				{
					//���� �ε���
					crashWall = num;
					break;
				}
				else if (check[x][y] != 0)
				{
					//�κ��� �ε���
					lastRobot = num;
					crashRobot = check[x][y];
					break;
				}
				else 
				{
					//�̵�
					vt[num].x = x;
					vt[num].y = y;
					check[x][y] = num;
				}
			}

		}
	}

	if (crashWall) cout << "Robot " << crashWall << " crashes into the wall" << endl;
	else if (crashRobot) cout << "Robot " << lastRobot << " crashes into robot " << crashRobot << endl;
	else cout << "OK" << endl;

	return 0;
}
