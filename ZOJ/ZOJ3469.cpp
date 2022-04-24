#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=1010;
const int INF=0x3f3f3f3f;
struct Node
{
    int x,b; 
    bool operator<(const Node&a)
    {
        return x<a.x; 
    }
}node[maxn];
int dp[maxn][maxn][2];
int sum[maxn];
int main()
{
    int n,v,X;
    while(~scanf("%d%d%d",&n,&v,&X))
    {
        for(int i=1;i<=n;++i)
            scanf("%d%d",&node[i].x,&node[i].b); 
        node[++n].x=X;						//记得加上餐馆这个点 
        node[n].b=0;
        sort(node+1,node+1+n);
        sum[0]=0;
        for(int i=1;i<=n;++i)
            for(int j=i;j<=n;++j)
                dp[i][j][0]=dp[i][j][1]=INF;
        for(int i=1;i<=n;++i)
        {    
            sum[i]=sum[i-1]+node[i].b; 
            if(node[i].x==X&&node[i].b==0)
                dp[i][i][0]=dp[i][i][1]=0;
        }   
        for(int len=2;len<=n;++len)
        {
            for(int i=1;i+len-1<=n;++i)
            {
                int j=i+len-1;
                dp[i][j][0]=min(dp[i][j][0],min(dp[i+1][j][0]+(node[i+1].x-node[i].x)*(sum[i]+sum[n]-sum[j]),dp[i+1][j][1]+(node[j].x-node[i].x)*(sum[i]+sum[n]-sum[j])));
                dp[i][j][1]=min(dp[i][j][1],min(dp[i][j-1][1]+(node[j].x-node[j-1].x)*(sum[i-1]+sum[n]-sum[j-1]),dp[i][j-1][0]+(node[j].x-node[i].x)*(sum[i-1]+sum[n]-sum[j-1])));
            } 
        }
        printf("%d\n",min(dp[1][n][0],dp[1][n][1])*v);//防止溢出 
    }
    return 0; 
}
