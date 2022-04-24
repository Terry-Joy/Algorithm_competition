#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,a[105];
ll dp[105][105][105];
char s[105];
int main(){
    scanf("%d",&n);
    scanf("%s",s+1);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int len=1;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            for(int k=0;k<n;++k){
                dp[i][j][k]=dp[i][j-1][0]+a[k+1];
                for(int x=i;x<j;++x){
                    if(s[x]==s[j]){
                        dp[i][j][k]=max(dp[i][j][k],dp[x+1][j-1][0]+dp[i][x][k+1]);
                    }
                }
            }
        }
    }
    cout<<dp[1][n][0]<<"\n";
    return 0;
}