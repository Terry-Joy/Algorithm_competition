#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

int cnt[70][2];

int main()
{
   int t;
   scanf("%d",&t);
   while(t--)
   {
      int n,m,a;
      scanf("%d%d",&n,&m);
      memset(cnt,0,sizeof(cnt));
      for(int i=1;i<=n;++i)
         for(int j=1;j<=m;++j)
         { 
             scanf("%d",&a);
             if((i+j)==(n-i+1+m-j+1))continue;
             cnt[min(i+j,n-i+1+m-j+1)][a]++;
         }
      int k=(n+m+1)/2;
      int ans=0;
      for(int i=2;i<=k;++i)
          ans+=min(cnt[i][0],cnt[i][1]);
      printf("%d\n",ans);
   }
   return 0; 
}
