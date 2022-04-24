#include<iostream>
#include<cstdio>
using namespace std;
const int N=6010;
int head[N],ver[N],next1[N],tot,dp[N][2],in[N],out[N],root;
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x)
{
    for(int i=head[x];i;i=next1[i])
    {
       dfs(ver[i]);
       dp[x][0]+=max(dp[ver[i]][1],dp[ver[i]][0]);
       dp[x][1]+=dp[ver[i]][0]; 
    }
}
int main()
{ 
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&dp[i][1]);
    for(int i=1;i<n;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(b,a);
       in[a]++;
    }
    for(int i=1;i<=n;++i)
    {
        if(!in[i])
        {
		   root=i;
       		 break;
		}
    }
    dfs(root);
    int ans=-1;
    ans=max(ans,max(dp[root][0],dp[root][1]));
    cout<<ans<<endl;
    return 0;
}
