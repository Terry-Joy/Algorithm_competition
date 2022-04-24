#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
const int N=1e4+10,M=2e4+10;
int head[N],ver[M],edge[M],next1[M],n,d[N],s,max_len,tot;
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa,int len)
{
   if(max_len<=len)
   {
      s=now,max_len=len; 
   } 
   for(int i=head[now];i;i=next1[i])
   {
      if(ver[i]!=fa)
      {
         dfs(ver[i],now,len+edge[i]);
         d[ver[i]]=max(d[ver[i]],len+edge[i]); 
      } 
   }
}
int main()
{
    while(~scanf("%d",&n))
    {
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0;
        memset(d,0,sizeof(d));
        for(int i=2;i<=n;++i)
        {
           int a,b;
           scanf("%d%d",&a,&b);
           add(i,a,b);
           add(a,i,b); 
        }
        s=0,max_len=0;
        dfs(1,0,0);
        dfs(s,0,0);
        dfs(s,0,0);
        for(int i=1;i<=n;++i)
            printf("%d\n",d[i]);
    } 
  return 0;  
}
```
第二种方法：
树形DP

void dp(int x,int fa){//以1为根下  d[x]表示从x出发走到x子树下的最长链
      for(int i=head[x];i;i=next1[i]){
	int y=ver[i];
	if(fa==y)continue;
	dp(y,now);
	ans=max(ans,d[x]+d[y]+edge[i]);		//更新最长链
	d[x]=max(d[x],d[y]+edge[i]);
      }
}


一个点在树上的最远路径只有2种可能，一种路径属于它的子树，一种是通过它的父亲节点一路往上，一种是通过它的父亲节点到子节点

所以要处理出每个点到子树的最远和次远，当是最远的时候，选次远，次远的时候选最远

代码：

```cpp
#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1e4+5,M=2e4+10;
int head[N],next1[M],ver[M],edge[M],tot,n,dp[N][3],id[N];
void dfs(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        if(ver[i]!=fa)
        { 
            dfs(ver[i],now);
            if(dp[now][0]<dp[ver[i]][0]+edge[i])
            {
                dp[now][0]=dp[ver[i]][0]+edge[i];
                id[now]=ver[i]; 
            }
        }
    }
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i],z=edge[i];
        if(y==fa)continue;
        if(id[now]==y)continue;
        dp[now][1]=max(dp[now][1],dp[y][0]+z); 
    } 
}
void dfs2(int now,int fa)
{
    for(int i=head[now];i;i=next1[i])
    {
        int y=ver[i],z=edge[i];
        if(fa==y)continue;
        if(y==id[now])
        {
            dp[y][2]=max(dp[now][2],dp[now][1])+z;
        } 
        else
        {
            dp[y][2]=max(dp[now][2],dp[now][0])+z; 
        }
        dfs2(y,now);
    } 
}
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
int main()
{
    while(scanf("%d",&n)!=EOF)
    {
        memset(dp,0,sizeof(dp));
        tot=0;
        for(int i=0;i<=n;++i)
            head[i]=0;
        for(int i=2;i<=n;++i)
        {
            int a,b;
            scanf("%d%d",&a,&b);
            add(i,a,b);
            add(a,i,b); 
        } 
        dfs(1,0);
        dfs2(1,0);
        for(int i=1;i<=n;++i)
            printf("%d\n",max(dp[i][0],dp[i][2]));
    }
    return 0;
}