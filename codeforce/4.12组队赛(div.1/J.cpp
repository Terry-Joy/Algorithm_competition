#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<queue>
#include<stack>
#include<algorithm>
#include<vector>
#define ll long long
#define pb push_back
using namespace std;
const int maxn=1e5+10,maxm=1e5+10,INF=0x3f3f3f3f;
vector<int>s1[maxn];
vector<int>s2[maxn];
int d1[maxn],d2[maxn],deg1[maxn],deg2[maxn];
int n,m;
void bfs1()
{
   queue<int>q1;
   for(int i=1;i<=n;++i)d1[i]=INF;
   for(int i=1;i<=n;++i)if(deg1[i]==1)q1.push(i),d1[i]=0;
   while(q1.size())
   {
      int x=q1.front();q1.pop();
      for(auto&v:s1[x])
      {
         if(d1[v]>d1[x]+1)
         {
            d1[v]=d1[x]+1;
            q1.push(v);
         }
      } 
   } 
}
void bfs2()
{
   queue<int>q2;
   for(int i=1;i<=m;++i)d2[i]=INF;
   for(int i=1;i<=m;++i)if(deg2[i]==1)q2.push(i),d2[i]=0;
   while(q2.size())
   {
      int x=q2.front();q2.pop();
      for(auto&v:s2[x])
      {
         if(d2[v]>d2[x]+1)
         {
            d2[v]=d2[x]+1;
            q2.push(v);
         }
      } 
   } 
}
int main()
{
    scanf("%d",&n);
    for(int i=1;i<n;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       s1[a].pb(b),s1[b].pb(a);
       deg1[a]++;deg1[b]++; 
    }
    scanf("%d",&m);
    for(int i=1;i<m;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       s2[a].pb(b),s2[b].pb(a);
       deg2[a]++,deg2[b]++; 
    } 
    bfs1();bfs2();
    sort(d1+1,d1+1+n);
    sort(d2+1,d2+1+m);
    ll ans=0;
    for(int i=1;i<=n;++i)
    {
       int k1=lower_bound(d2+1,d2+1+m,d1[i])-d2;
       ans+=(d1[i]*1ll*(m-k1+1)); 
    }
    for(int i=1;i<=m;++i)
    {
       int k2=upper_bound(d1+1,d1+1+n,d2[i])-d1;
       ans+=(d2[i]*1ll*(n-k2+1)); 
    }
    double num=(double)ans/n/m;
    printf("%.12lf\n",num);
    return 0;
}
