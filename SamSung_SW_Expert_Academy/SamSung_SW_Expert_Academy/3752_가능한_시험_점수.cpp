#include <stdio.h>
#include <memory.h>
#include <algorithm>
using namespace std;

int cache[10001], score[100], n, result;

void solve();

int main()
{
	int t;
	scanf("%d", &t);

	for (int i = 1; i <= t; i++)
	{
		result = 0;
		memset(cache, 0, sizeof(cache));
		solve();
		printf("#%d %d\n", i, result);
	}

	return 0;
}

void solve()
{
	int sum = 0;

	scanf("%d", &n);

	for (int i = 0; i < n; i++)
	{
		scanf("%d", &score[i]);
		sum += score[i];
	}
	cache[0] = 1;

	for (int i = 0; i < n; i++)
		for (int j = sum; j >= 0; j--)
			if (cache[j] == 1) cache[j + score[i]] = 1;

	for (int i = 0; i <= sum; i++)
		if (cache[i] == 1) result++;
}