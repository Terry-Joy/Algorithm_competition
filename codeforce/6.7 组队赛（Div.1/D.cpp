#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1010;
ll head[maxn],next1[10*maxn],ver[10*maxn],edge[10*maxn],tot=0,cnt=0;
ll d[maxn][maxn],dp[maxn],s[maxn],u[maxn],t[maxn],n,m;
typedef pair<ll,int>P;
const ll INF=1e15;
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dijkstra(int k,int n)
{
    priority_queue<P,vector<P>,greater<P> >q;
    for(int i=1;i<=n;++i)
        d[k][i]=INF;
    d[k][k]=0;
    q.push(P{d[k][k],k});
    while(q.size())
    {
       P x=q.top();q.pop();
       int y=x.second;
       if(d[k][y]<x.first)continue;
       for(int i=head[y];i;i=next1[i])
       {
          int z=edge[i],v=ver[i];
          if(d[k][v]>d[k][y]+z) 
          {
             d[k][v]=d[k][y]+z;
             q.push((P){ d[k][v],v}); 
          }
       } 
    }
}
bool check(ll mid)
{
   dp[0]=0;
   for(int i=1;i<=cnt;++i)
      dp[i]=INF;
   for(int i=0;i<=cnt-1;++i)
   {
      ll a=dp[i],ans=0,maxs=INF;
      for(int j=i+1;j<=cnt;++j)
      {
         if(j==i+1)ans+=d[1][u[j]];
         else ans+=d[u[j-1]][u[j]];
         a=max(a,t[j]);
         maxs=min(maxs,mid-ans+s[j]);
         ll rest=a+ans-s[j];
         if(mid>=rest&&a<=maxs)dp[j]=min(dp[j],a+ans+d[u[j]][1]);
         else 
             break;
      } 
   } 
   return dp[cnt]<INF;
}
int main()
{
   scanf("%d%d",&n,&m);
   ll a,b,c;
   for(int i=1;i<=m;++i)
   {
       scanf("%lld%lld%lld",&a,&b,&c);
       add(a,b,c);
       add(b,a,c);
   } 
   for(int i=1;i<=n;++i)
       dijkstra(i,n);
   scanf("%lld",&cnt);
   for(int i=1;i<=cnt;++i)
      scanf("%lld%lld%lld",&s[i],&u[i],&t[i]);
   ll l=0,r=INF;
   while(l<r)
   {
      ll mid=l+r>>1;
      if(check(mid))r=mid;
      else l=mid+1; 
   }
   /*for(int i=1;i<=n;++i)
   for(int j=1;j<=n;++j)
       cout<<d[i][j]<<"<<<"<<endl;*/
   printf("%lld\n",r);
   return 0; 
}
