#include <stdio.h>
#include <deque>
using namespace std;

void solve();
int sum;

int main()
{
	int t;

	scanf("%d", &t);
	for (int i = 0; i < t; i++)
	{
		sum = 0;
		solve();
		printf("#%d %d\n", i + 1, sum);
	}

	return 0;
}

void solve()
{
	int k, temp;
	deque<int> dq;
	scanf("%d", &k);

	for (int i = 0; i < k; i++)
	{
		scanf("%d", &temp);
		if (temp == 0) dq.pop_back();
		else dq.push_back(temp);
	}
	for (int i = 0; i < dq.size(); i++)
		sum += dq.at(i);
}