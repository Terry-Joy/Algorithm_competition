#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
int dp[maxn][maxn],g[maxn],n,a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)dp[i][i]=a[i];
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            for(int k=i;k<j;++k){
                if(dp[i][k]&&dp[i][k]==dp[k+1][j])dp[i][j]=dp[i][k]+1;
            }
        }
    }
    memset(g,0x3f,sizeof(g));
    g[0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<i;++j){
            if(dp[j+1][i])g[i]=min(g[j]+1,g[i]);
        }
    }
    cout<<g[n]<<"\n";
    return 0;
}