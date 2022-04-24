#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=2e5+10,M=4e5+10;
int head[N],next1[M],ver[M],tot,size[N],d[N],ans[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
    d[now]=d[fa]+1;
    for(int i=head[now];i;i=next1[i])
    {
       int y=ver[i];
       if(y==fa)continue;
       dfs(y,now);
       size[now]+=size[y]; 
    }
}
int main()
{ 
    int n,m,i,a,b;
    scanf("%d%d",&n,&m);
    for(i=1;i<n;++i)
    { 
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a);
    }
    for(i=1;i<=n;++i)
        size[i]=1;
    dfs(1,0);
    for(i=1;i<=n;++i)
        ans[i]=d[i]-size[i];
    sort(ans+1,ans+1+n);
    ll sum=0;
    for(i=n;i>=n-m+1;--i)
        sum+=1ll*ans[i];
    printf("%lld\n",sum);
    return 0;
}
