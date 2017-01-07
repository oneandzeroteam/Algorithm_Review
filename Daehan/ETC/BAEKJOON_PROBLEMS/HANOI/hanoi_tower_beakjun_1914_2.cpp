#include<cstdio>
#pragma warning (disable:4996)
int n, k;
int d[50];

void hanoi(int x, int y, int p)
{
	if (p>0)
	{
		hanoi(x, 6 - x - y, p - 1);
		printf("%d %d\n", x, y);
		hanoi(6 - x - y, y, p - 1);
	}
}

int main()
{
	scanf("%d", &n);
	d[0] = k = 1;
	for (int i = 0; i<n; i++)
	{
		for (int p = 0; p<k; p++) d[p] = 2 * d[p];
		for (int p = 0; p<k; p++) d[p + 1] += d[p] / 10, d[p] %= 10;
		if (d[k]>0) k++;
	} d[0]--;
	for (int p = 0; p<k; p++) printf("%d", d[k - 1 - p]); printf("\n");
	if (n <= 20) hanoi(1, 3, n);
	return 0;
}
