#include<stdio.h>
#include<string.h>//填色

int main() {//思路大概是将0变成2，再将边缘的2变成0，将与0碰到的2都变成0
    int n;
    scanf("%d\n", &n);
    int i, j;
	int k;
	int s=0;
	int l,r;
	int low ,up;
    int a[31][31];
	int flag = 0;
    for (i = 0;i < n;i++) {
        for (j = 0;j < n-1;j++) {
            scanf("%d ", &a[i][j]);
        }

            scanf("%d", &a[i][j]);
    }
    for(i=0;i<n-1;i++){
        for(j=0;j<n;j++){
            if(a[i][j]==0){
                a[i][j]=2;
            }
        }
    }
    for(j=0;j<n;j++){
        if(a[0][j]==2){
            a[0][j]=0;
        }
        
    }
    for(i=1;i<n-1;i++){
        if(a[i][0]==2){
            a[i][0]=0;
        }
        for(j=1;j<n;j++){
            if((a[i-1][j]==0||a[i][j-1]==0)&&a[i][j]==2){
                a[i][j]=0;
            }
        }
    }
    for(i=n-2;i>=1;i--){
        if(a[i][n-1]==2){
            a[i][n-1]=0;
        }
        for(j=n-2;j>0;j--){
            if((a[i+1][j]==0||a[i][j+1]==0)&&a[i][j]==2){
                a[i][j]=0;
            }
        }
    }
    
    for (i = 0;i < n;i++) {
        for (j = 0;j < n - 1;j++) {
            printf("%d ", a[i][j]);
        }

           printf("%d\n", a[i][j]);




    }
}
