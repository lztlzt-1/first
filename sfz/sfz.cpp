#include<stdio.h>
#include<stdlib.h>
#include<time.h>
int main(){
	srand(time(0));
	int a[10];
	int i;
	int b[19];
	a[0]=330100;
	b[0]=3;
	b[1]=3;
	b[2]=0;
	b[3]=1;
	b[4]=0;
	b[5]=0;
	a[1]=rand()%10+2000;
	for(i=9;i>=6;i--){
		b[i]=a[1]%10;
		a[1]=a[1]/10;
	}
	a[2]=rand()%12+1;
	for(i=11;i>=10;i--){
		b[i]=a[2]%10;
		a[2]=a[2]/10;
	}
	if(a[2]==1||a[2]==3||a[2]==5||a[2]==7||a[2]==8||a[2]==10||a[2]==12){
		a[3]=rand()%31+1;
	}else if(a[2]==2){
		if(a[1]%400==0||(a[1]%4==0&&a[1]%100!=0))
			a[3]=rand()%29+1;
		else
			a[3]=rand()%28+1;
	}else
		a[3]=rand()%30+1;
	for(i=13;i>=12;i--){
		b[i]=a[3]%10;
		a[3]=a[3]/10;
	}
	a[4]=0;//����λ����0��
	b[14]=0;
	b[15]=0;
	a[5]=rand()%10;
	b[16]=a[5];
	a[6]=(b[0]*7+b[1]*9+b[2]*10+b[3]*5+b[4]*8+b[5]*4+b[6]*2+b[7]+b[8]*6+b[9]*3+b[10]*7+b[11]*9+b[12]*10+b[13]*5+b[14]*8+b[15]*4+b[16]*2)%11;
	if(a[6]==0)
		a[6]=1;
	else if(a[6]==1)
		a[6]=0;
	else if(a[6]==2)
		a[6]=10;
	else if(a[6]==3)
		a[6]=9;
	else if(a[6]==4)
		a[6]=8;
	else if(a[6]==5)
		a[6]=7;
	else if(a[6]==6)
		a[6]=6;
	else if(a[6]==7)
		a[6]=5;
	else if(a[6]==8)
		a[6]=4;
	else if(a[6]==9)
		a[6]=3;
	else if(a[6]==10)
		a[6]=2;//�ŷ������й��ɵġ���
	b[17]=a[6];
	for(i=0;i<=17;i++){
		if(b[i]==10){
			printf("%c",'X');
		}else
			printf("%d",b[i]);
	}

}
