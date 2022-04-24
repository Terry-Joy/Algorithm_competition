#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

const int maxn=2e5+10;

int sum01[maxn],sum10[maxn],INF=0x7FFFFFFF,a[maxn],b[maxn],c[maxn];
ll ans=0;
vector<int>G[maxn];
void dfs(int now,int fa,int mn)
{
   sum01[now]=(b[now]==0&&c[now]==1);
   sum10[now]=(b[now]==1&&c[now]==0);
   for(auto&v:G[now])
   {
      if(v==fa)continue;
      dfs(v,now,min(mn,a[now]));
      sum01[now]+=sum01[v];
      sum10[now]+=sum10[v];      
   } 
   if(a[now]<mn)//贪心的选
   {
        int cnt=min(sum01[now],sum10[now]);
        ans+=2ll*a[now]*cnt;
        sum01[now]-=cnt;
        sum10[now]-=cnt; 
   }
}
int main()
{
   int n;
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
      scanf("%d%d%d",&a[i],&b[i],&c[i]);
   int a,b;
   for(int i=1;i<n;++i)
   {
       scanf("%d%d",&a,&b);
       G[a].push_back(b); 
       G[b].push_back(a);
   } 
   dfs(1,0,INF);
   if(sum01[1]!=0||sum10[1]!=0)
       puts("-1");
   else
       printf("%lld\n",ans);
   return 0; 
}
