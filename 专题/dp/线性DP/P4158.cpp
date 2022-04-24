#include<bits/stdc++.h>

using namespace std;
int f[52][2505],g[52][52][52],n,m,t,sum[52][52];
char s[52][52];
int main(){
    scanf("%d%d%d",&n,&m,&t);
    for(int i=1;i<=n;++i)scanf("%s",s[i]+1);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            sum[i][j]=sum[i][j-1]+(s[i][j]=='1');
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(m,t);++j){
            for(int k=j;k<=m;++k){
                for(int d=j-1;d<k;++d)
                    g[i][j][k]=max(g[i][j][k],g[i][j-1][d]+max(sum[i][k]-sum[i][d],k-d-sum[i][k]+sum[i][d]));
            }
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=min(i*m,t);++j){
            for(int k=0;k<=min(j,m);++k)
                f[i][j]=max(f[i][j],f[i-1][j-k]+g[i][k][m]);
        }
    }
    cout<<f[n][t];
}