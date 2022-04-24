#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<stack>
#include<queue>
#include<algorithm>
#include<vector>
#include<map>
#include<set>
#define ll long long 
const int maxn=1e6+5;
struct Node{ 
    int x,y,h;
    ll val;
}node[maxn],a;
int gcd(int a,int b)
{
   return b?gcd(b,a%b):a; 
}
using namespace std;
bool cmp(Node a,Node b)
{
   if(a.x!=b.x)return a.x<b.x;
   if(a.y!=b.y)return a.y<b.y;
   return a.val<b.val;
}
int sum[maxn];
int main()
{
   int n;
   scanf("%d%d",&a.x,&a.y);
   scanf("%d",&n);
   for(int i=1;i<=n;++i)
   {
      scanf("%d%d%d",&node[i].x,&node[i].y,&node[i].h);
      node[i].x-=a.x;
      node[i].y-=a.y;
      node[i].val=1ll*node[i].x*node[i].x+1ll*node[i].y*node[i].y;
      int x=gcd(abs(node[i].x),abs(node[i].y));
      node[i].x/=x,node[i].y/=x; 
   }
   sort(node+1,node+1+n,cmp);
   //for(i=1;i<=n;++i)cout<<node[i].val<<" ";
   int i,j,k,f,ans=0,l,r,mid,q;
   for(i=1;i<=n;i=j)
   {
      for(j=i;j<=n&&node[i].x==node[j].x&&node[i].y==node[j].y;++j);
        k=0;
      for(f=i;f<j;++f)
      {
          if(!k||node[f].h>sum[k])
          {
             sum[++k]=node[f].h;
             continue; 
          }
          l=1,r=k;
          while(l<=r)
          {
             mid=l+r>>1;
             if(sum[mid]>=node[f].h)
             {
                q=mid;
                r=mid-1; 
             }
             else l=mid+1 ;
          }
          sum[q]=node[f].h;
      }
      //for(i=1;i<=n;++i)cout<<sum[i]<<endl;
      ans+=k;
   }
   printf("%d",ans);
   return 0; 
}
