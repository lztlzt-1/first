#include<stdio.h>

int main() {
	int a[30000];//�������߻�û���ԣ�ֻ���Ե�20000
	int i, j, n = 0, n1 = 0, jw = 0;
	int theInput;
	a[0] = 1;
	for (i = 1;i < 30000;i++) {
		a[i] = 0;
	}//��ʼ��
	scanf("%d", &theInput);
	for (i = 1;i <= theInput;i++) {
		for (j = 0;j <= n;j++) {
			a[j] = a[j] * i + jw;
			jw = 0;
			if (a[j] > 10000) {
				jw = a[j] / 10000;
				a[j] = a[j] % 10000;
				if(a[n+1]==0)
					n=n+1;//������
				if (i == theInput && a[n] == 0 && j == n) {
					
					break;
				}

			}

		}
	}//�׳ˣ�ÿ������Ԫ�ش洢4λ

	a[n] = a[n] + jw;
	jw = 0;

	for (i = n;i >= 0;i--) {
		if (a[i] <= 0) {
			n = n - 1;

		}
		else {
			break;
		}
	}
	printf("%d", a[n]);
	for (i = n - 1;i >= 0;i--) {

		printf("%04d", a[i]);

	}
}