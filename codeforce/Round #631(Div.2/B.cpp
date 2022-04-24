#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long 
using namespace std;
const int maxn=2e5+10;
int a[maxn],vis[maxn],ans[5][5];
int n;
bool check(int l1,int r1)
{
   for(int i=1;i<=n;++i)vis[i]=0;
   for(int i=1;i<=l1;++i)vis[a[i]]=1;
   for(int i=1;i<=l1;++i)
      if(vis[i]==0)
         return 0;
   for(int i=1;i<=r1;++i)
      vis[i]=0;
   for(int i=l1+1;i<=n;++i)
        vis[a[i]]=1;
   for(int i=1;i<=r1;++i)
      if(vis[i]==0)return 0;
   return 1; 
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
       scanf("%d",&n);
       int mx=-1;
       int cnt=0;
       for(int i=1;i<=n;++i)
       {
          scanf("%d",&a[i]);
          mx=max(mx,a[i]); 
       }
       if(check(mx,n-mx))
       {
          cnt++;
          ans[cnt][1]=mx;
          ans[cnt][2]=n-mx; 
       }
       if(mx*2!=n&&check(n-mx,mx))
       {
          cnt++;
          ans[cnt][1]=n-mx;
          ans[cnt][2]=mx; 
       }
       printf("%d\n",cnt);
       for(int i=1;i<=cnt;++i)
           printf("%d %d\n",ans[i][1],ans[i][2]);
    }
    return 0;
}
