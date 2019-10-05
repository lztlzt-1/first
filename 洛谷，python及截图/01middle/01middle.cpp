/*#include<stdio.h>
int main() {
	int m, n;
	int i, j, k;
	int dx[10001], dy[10001];
	int a[1001][200];
	int b[200][200];
	int date;
	int bs = 0;
	int al = 1;
	int s = 0;
	scanf("%d %d", &n, &m);
	for (i = 0;i < n;i++) {
		scanf("%d", &date);
		for (j = n - 1;j >= 0;j--) {
			a[i][j] = date % 10;
			date = date / 10;
		}

	}
	for (i = 0;i < m;i++) {
		scanf("%d %d", &dx[i], &dy[i]);
		dx[i] = dx[i] - 1;
		dy[i] = dy[i] - 1;
		s = s + 1;
	}
	for (i = 0;i < n;i++) {
		for (j = 0;j < n;j++) {
			b[i][j] = 0;
		}
	}

	for (k = 0;k < s;k++) {
		b[dx[k]][dy[k]] = 1;
		while (al != n * n) {
			for (i = 0;i < n;i++) {
				for (j = 0;j < n;j++) {
					if (b[i][j] == 1) {
						if (i - 1 >= 0 && a[i][j] != a[i - 1][j] && b[i - 1][j] == 0) {
							b[i - 1][j] = 1;
							bs = bs + 1;
							al = al + 1;
						}
						if (i + 1 < n && a[i][j] != a[i + 1][j] && b[i + 1][j] == 0) {
							b[i + 1][j] = 1;
							bs = bs + 1;
							al = al + 1;
						}
						if (j - 1 >= 0 && a[i][j] != a[i][j - 1] && b[i][j - 1] == 0) {
							b[i][j - 1] = 1;
							bs = bs + 1;
							al = al + 1;
						}
						if (j + 1 <= n && a[i][j] != a[i][j + 1] && b[i][j + 1] == 0) {
							b[i][j + 1] = 1;
							bs = bs + 1;
							al = al + 1;
						}
						b[i][j] = 2;
					}
				}
			}
		}
		printf("%d\n", bs + 1);
		bs = 0;
		for (i = 0;i < n;i++) {
			for (j = 0;j < n;j++) {
				b[i][j] = 0;
			}
		}
	}
}*/
#include<cstdio>////上面的是我的思路，没问题但超时了，下面是题解看完后的思路，直接用了C++的库
#include<cstring>
int n, m, ans[100002], x, y, f[1002][1002];
char s[1002][1002];
void dfs(int r, int c, int z, int num) {
	if (r < 0 || r >= n || c < 0 || c >= n || f[r][c] != -1 || s[r][c] - '0' != z)
		return;
	f[r][c] = num;
	ans[num]++;
	dfs(r - 1, c, !z, num);
	dfs(r + 1, c, !z, num);
	dfs(r, c - 1, !z, num);
	dfs(r, c + 1, !z, num);
}
int main()
{
	int i, j;
	scanf("%d%d", &n, &m);
	for (i = 0;i < n;i++)
		scanf("%s", s[i]);
	memset(f, -1, sizeof(f));
	for (i = 0;i < m;i++)
	{
		scanf("%d%d", &x, &y);x--;y--;
		if (f[x][y] == -1)dfs(x, y, s[x][y] - '0', i);
		else 
			ans[i] = ans[f[x][y]];
	}
	for (i = 0;i < m;i++)
		printf("%d\n", ans[i]);
	return 0;
}