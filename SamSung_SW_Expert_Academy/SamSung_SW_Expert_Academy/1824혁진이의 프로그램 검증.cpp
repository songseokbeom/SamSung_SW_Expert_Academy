#include <stdio.h>
#include <stdlib.h>
#include <deque>
#include <algorithm>
#include <memory.h>
using namespace std;

struct info {
	int x;
	int y;
	int dir;
	int mem;
};

bool flag;
int dx[] = { -1, 0, 1, 0 }, dy[] = { 0, 1, 0, -1 };
char inst[21][21];
int check[21][21][16][4];
void solve();

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		flag = false;
		memset(check, -1, sizeof(check));
		solve();
		printf("#%d ", i);
		if (flag == false) printf("NO\n");
		else printf("YES\n");
	}

	return 0;
}

void solve()
{
	int r, c;

	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++)
		scanf("%s", inst[i]);
	
	deque<info> dq;
	info a;
	a.mem = 0, a.dir = 1, a.x = 0, a.y=0;
	dq.push_back(a);
	check[0][0][0][1] = 1;

	while(!dq.empty())
	{
		info g = dq.front();
		dq.pop_front();

		if (inst[g.x][g.y] == '<') g.dir = 3;
		else if (inst[g.x][g.y] == '>') g.dir = 1;
		else if (inst[g.x][g.y] == '^')	g.dir = 0;
		else if (inst[g.x][g.y] == 'v') g.dir = 2;
		else if (inst[g.x][g.y] == '_')
		{
			if (g.mem == 0) g.dir = 1;
			else g.dir = 3;
		}
		else if (inst[g.x][g.y] == '|')
		{
			if (g.mem == 0) g.dir = 2;
			else g.dir = 0;
		}
		else if (inst[g.x][g.y] == '@')
		{
			flag = true;
			break;
		}
		else if ('0' <= inst[g.x][g.y] && inst[g.x][g.y] <= '9') g.mem = inst[g.x][g.y] - '0';
		else if (inst[g.x][g.y] == '+') g.mem= (g.mem+1) % 16;
		else if (inst[g.x][g.y] == '-')
		{
			g.mem--;
			if (g.mem == -1) g.mem = 15;
		}
		else if (inst[g.x][g.y] == '?')
		{
			for (int i = 0; i < 4; i++)
			{
				info temp = g;
				temp.x = temp.x + dx[i], temp.y = temp.y + dy[i], temp.dir = i;

				if (temp.x < 0) temp.x = r - 1;
				if (temp.x >= r) temp.x = 0;
				if (temp.y < 0) temp.y = c - 1;
				if (temp.y >= c) temp.y = 0;

				if (check[temp.x][temp.y][temp.mem][temp.dir] == 1) continue;
				else 
				{
					check[temp.x][temp.y][temp.mem][temp.dir] = 1;
					dq.push_back(temp);
				}
			}
			continue;
		}

		g.x = g.x + dx[g.dir], g.y = g.y + dy[g.dir];
		if (g.x < 0) g.x = r - 1;
		if (g.x >= r) g.x = 0;
		if (g.y < 0) g.y = c - 1;
		if (g.y >= c) g.y = 0;
		
		if (check[g.x][g.y][g.mem][g.dir] == 1) continue;
		else
		{
			check[g.x][g.y][g.mem][g.dir] = 1;
			dq.push_back(g);
		}
	}
}