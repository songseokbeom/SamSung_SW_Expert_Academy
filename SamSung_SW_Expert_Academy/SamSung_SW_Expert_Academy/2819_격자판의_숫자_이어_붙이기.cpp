#include <stdio.h>
#include <memory.h>
using namespace std;

void solve();
void dfs(int x, int y, int idx);

int check[10][10][10][10][10][10][10], box[4][4], temp[7], result;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		result = 0;
		memset(check, 0, sizeof(check));
		memset(temp, 0, sizeof(temp));
		solve();
		printf("#%d %d\n", i, result);
	}

	return 0;
}

void solve()
{
	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			scanf("%d", &box[i][j]);

	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			temp[0] = box[i][j];
			dfs(i, j, 1);
		}
	}
}

void dfs(int x, int y, int idx)
{
	if (idx == 7)
	{
		if (check[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]] == 0)
		{
			result++;
			check[temp[0]][temp[1]][temp[2]][temp[3]][temp[4]][temp[5]][temp[6]] = 1;
		}
		return;
	}

	for (int i = 0; i < 4; i++)
	{
		int tx = x + dx[i], ty = y + dy[i];

		if (tx < 0 || tx>3 || ty < 0 || ty>3) continue;
		temp[idx] = box[tx][ty];
		dfs(tx, ty, idx + 1);
	}
}