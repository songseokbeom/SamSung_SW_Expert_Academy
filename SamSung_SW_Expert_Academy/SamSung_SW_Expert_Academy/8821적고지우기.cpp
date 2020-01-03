#include <stdio.h>

int t, q;
void solve();
char str[10001];

int main()
{
	scanf("%d", &t);

	for (q = 1; q <= t; q++)
		solve();

	return 0;
}

void solve()
{
	int sum=0, check[] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };

	scanf("%s", str);

	for (int i = 0; str[i] != '\0'; i++)
	{
		if (check[str[i] - '0'] == 1) check[str[i] - '0'] = 0;
		else check[str[i] - '0'] = 1;
	}
	for (int i = 0; i <= 9; i++) sum += check[i];
	printf("#%d %d\n", q, sum);
}