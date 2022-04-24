#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll dp[maxn][1<<7];
typedef long long ll;
struct Node{
    int a,s[7];
    bool operator<(const Node&A){
        return a>A.a;
    }
}node[maxn];
int main(){
    int n,p,k;
    scanf("%d%d%d",&n,&p,&k);
    for(int i=1;i<=n;++i)
        scanf("%d",&node[i].a);
    for(int i=1;i<=n;++i)
        for(int j=0;j<p;++j)
            scanf("%d",&node[i].s[j]);
    sort(node+1,node+1+n);
    memset(dp,0xc0,sizeof(dp));
    dp[0][0]=0;
    for(int i=1;i<=n;++i){
        for(int j=0;j<(1<<p);++j){
            int cnt=0;
            for(int k=0;k<p;++k)
                cnt+=(bool)(j&(1<<k));
            if(i<=k+p&&i-cnt<=k)dp[i][j]=max(dp[i][j],dp[i-1][j]+node[i].a);//当前作为观众
            else dp[i][j]=dp[i-1][j];//当前啥都不选
            for(int k=0;k<p;++k)
                if(j&(1<<k))dp[i][j]=max(dp[i][j],dp[i-1][j-(1<<k)]+node[i].s[k]);//当前选k个中
        }
    }
    cout<<dp[n][(1<<p)-1]<<endl;
    return 0;
}
