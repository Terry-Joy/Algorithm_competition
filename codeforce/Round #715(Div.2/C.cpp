#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2005;
int n,t,a[maxn];
ll dp[maxn][maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    for(int len=2;len<=n;++len){
        for(int i=1;i+len-1<=n;++i){
            int j=i+len-1;
            dp[i][j]=min(dp[i+1][j],dp[i][j-1])+a[j]-a[i];
        }
    }
    cout<<dp[1][n]<<"\n";
    return 0;
}