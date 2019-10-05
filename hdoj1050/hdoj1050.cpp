#include<stdio.h>//思路就是将走廊的一点走过几次统计出来，寻找最大的
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
	}//初始化
	scanf("%d\n", &T);
	for (i = 0;i < T;i++) {
		scanf("%d\n",&N);
		for (j = 0;j < N;j++) {
			scanf("%d %d", &a[j], &b[j]);
			swap(&a[j], &b[j]);
			a[j]=(a[j]+1)/2;
			b[j]=(b[j]+1)/2;//1，2共用一个走廊，所以缩短
			for(k=a[j];k<=b[j];k++){
				c[k]=c[k]+1;
			}//走廊要用就加1
		}
		k=0;
		for(j=0;j<200;j++){
			if(c[k]<c[j]){
				k=j;
			}//选择最大的
		}
		printf("%d\n",c[k]*10);
		for(k=0;k<200;k++){
		c[k]=0;
	}
	}
}