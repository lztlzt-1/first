#include<stdio.h>//˼·���ǽ����ȵ�һ���߹�����ͳ�Ƴ�����Ѱ������
void swap(int* a, int* b) {
	if (*a > *b) {
		int t;
		t = *a;
		*a = *b;
		*b = t;
	}
}

int main(){
	int T, N, i, j, len,k;
	int a[200], b[200],c[200];
	for(i=0;i<200;i++){
		c[i]=0;
	}//��ʼ��
	scanf("%d\n", &T);
	for (i = 0;i < T;i++) {
		scanf("%d\n",&N);
		for (j = 0;j < N;j++) {
			scanf("%d %d", &a[j], &b[j]);
			swap(&a[j], &b[j]);
			a[j]=(a[j]+1)/2;
			b[j]=(b[j]+1)/2;//1��2����һ�����ȣ���������
			for(k=a[j];k<=b[j];k++){
				c[k]=c[k]+1;
			}//����Ҫ�þͼ�1
		}
		k=0;
		for(j=0;j<200;j++){
			if(c[k]<c[j]){
				k=j;
			}//ѡ������
		}
		printf("%d\n",c[k]*10);
		for(k=0;k<200;k++){
		c[k]=0;
	}
	}
}