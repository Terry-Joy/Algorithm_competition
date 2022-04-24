#include<bits/stdc++.h>

using namespace std;
double mp[15][15],a[15][15],sum[15];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n+1;++i)
        for(int j=1;j<=n;++j)
            scanf("%lf",&mp[i][j]);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=n;++j)
            a[i][j]=2*(mp[i][j]-mp[i+1][j]),sum[i]+=(mp[i][j]*mp[i][j]-mp[i+1][j]*mp[i+1][j]);
            a[i][n+1]=sum[i];
    }
    for(int i=1;i<=n;++i){
        int mx=i;
        for(int j=i+1;j<=n;++j){
            if(fabs(a[j][i])>fabs(a[mx][j]))
            mx=j;
        }
        for(int j=1;j<=n+1;++j)
           swap(a[i][j],a[mx][j]);
           for(int j=1;j<=n;++j){
            if(j!=i){
               double tmp=a[j][i]/a[i][i];
               for(int k=i+1;k<=n+1;++k)
               a[j][k]-=tmp*a[i][k];
            }
        }
    }
    for(int i=1;i<=n;++i)
        printf("%.3f ",a[i][n+1]/a[i][i]);
    return 0;
}