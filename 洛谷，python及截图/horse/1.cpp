#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>

using namespace std;//开始使用C写的，后来发现C没有bool，所以改成C++，但里面的其他语句全是C的，不加C++，不知道那个库里有bool，所以直接把前面的库复制了
int main() {
	
	int m, n;
	int x, y;
	int a[401][401];
	bool b[401][401];
	int i, j;
	int s = 0;
	int step = 1;
	scanf("%d %d %d %d", &m, &n, &x, &y);
	x=x-1;
	y=y-1;
	for (i = 0;i < m;i++) {
		for (j = 0;j < n ;j++) {
			a[i][j] = 0;
			b[i][j]=true;
		}

	}

	a[x][y] = -2;
	while (step < 500) {
		for (i = 0;i < m;i++) {
			for (j = 0;j < n;j++) {
				if (a[i][j]!=0) {//
					if ((i - 2 >= 0) && (j - 1 >= 0) && a[i - 2][j - 1] == 0&&b[i][j]==true) {
						a[i - 2][j - 1] =  step;
						b[i-2][j-1]=false;
					}
					if ((i - 1 >= 0) && (j - 2 >= 0) && a[i - 1][j - 2] == 0&&b[i][j]==true) {
						a[i - 1][j - 2] =  step;
						b[i-1][j-2]=false;
					}
					if ((i - 2 >= 0) && (j + 1 <= n) && a[i - 2][j + 1] == 0&&b[i][j]==true) {
						a[i - 2][j + 1] =  step;
						b[i - 2][j + 1]=false;
					}
					if ((i + 1 <= m) && (j - 2 >= 0) && a[i + 1][j - 2] == 0&&b[i][j]==true) {
						a[i + 1][j - 2] =  step;
						b[i + 1][j - 2]=false;
					}
					if ((i + 2 <= m) && (j - 1 >= 0) && a[i + 2][j - 1] == 0&&b[i][j]==true) {
						a[i + 2][j - 1] =  step;
						b[i + 2][j - 1]=false;
					}
					if ((i - 1 >= 0) && (j + 2 <= n) && a[i - 1][j + 2] == 0&&b[i][j]==true) {
						a[i - 1][j + 2] =  step;
						b[i - 1][j + 2]=false;
					}
					if ((i + 2 <= m) && (j + 1 <= n) && a[i + 2][j + 1] == 0&&b[i][j]==true) {
						a[i + 2][j + 1] =  step;
						b[i + 2][j + 1]=false;
					}
					if ((i + 1 <= m) && (j + 2 <= n) && a[i + 1][j + 2] == 0&&b[i][j]==true) {
						a[i + 1][j + 2] =  step;
						b[i + 1][j + 2]=false;
					}

				}
			}
		}
		step = step + 1;
		for(i=0;i<m;i++){
			for(j=0;j<n;j++){
				b[i][j]=true;
			}
		}
	}
	for (i = 0;i < m;i++) {
		for (j = 0;j < n;j++) {
			if (a[i][j] == 0) {
				a[i][j] = -1;
			}
			if (a[i][j] == -2) {
				a[i][j] = 0;
			}
		}
	}
	for (i = 0;i < m;i++) {
		for (j = 0;j < n-1;j++) {
			printf("%-5d", a[i][j]);
		}
		printf("%-5d\n",a[i][j]);
	}

}