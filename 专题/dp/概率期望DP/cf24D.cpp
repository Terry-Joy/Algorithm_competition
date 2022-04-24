#include<bits/stdc++.h>

using namespace std;
const int maxn=1005;
double dp[1005][1005],a[1005][1005];
int n,m,x,y;
void gauss(){ //回代法高斯消元
    for(int i=1;i<=m;++i){ 
        double tmp=1.0/a[i][i];
        a[i][i]*=tmp;
        a[i][m+1]*=tmp;
        if(i==m)break;
        a[i][i+1]*=tmp;
        tmp=a[i+1][i];
        a[i+1][i]=0;
        a[i+1][i+1]-=a[i][i+1]*tmp;
        a[i+1][m+1]-=a[i][m+1]*tmp;
    }
    for(int i=m-1;i>=1;--i){ 
        a[i][m+1]-=a[i+1][m+1]*a[i][i+1];
    }
}
int main(){ 
    scanf("%d%d",&n,&m);
    scanf("%d%d",&x,&y);
    if(m==1){ 
        dp[x][y]=(n-x)*2;
    }
    else{ 
        for(int i=n-1;i>=x;--i){ 
            a[1][1]=a[m][m]=1;
            a[1][2]=a[m][m-1]=-0.5;
            a[1][m+1]=0.5*dp[i+1][1]+1.5;
            a[m][m+1]=0.5*dp[i+1][m]+1.5;
            for(int j=2;j<m;++j){ 
                a[j][j]=1;
                a[j][j-1]=-1.0/3;
                a[j][j+1]=-1.0/3;
                a[j][m+1]=dp[i+1][j]/3+4.0/3;
            }
            gauss();
            for(int j=1;j<=m;++j)dp[i][j]=a[j][m+1];
        }
    }
    printf("%.10lf",dp[x][y]);
    return 0;
}
