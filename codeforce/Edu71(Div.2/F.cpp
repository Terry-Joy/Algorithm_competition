#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
#define ll long long
using namespace std;
const int mod=710;
ll p[1000][1000];int ans[500010],maxn;
int main()
{
   int q,cnt,x,y;
   scanf("%d",&q);
   for(int i=1;i<=q;++i)
   {
      scanf("%d%d%d",&cnt,&x,&y);
      if(cnt==1)
      {
         ans[x]+=y;maxn=max(maxn,x);
         for(int i=1;i<=mod;++i)
             p[i][x%i]+=y;
      } 
      else
      {
         if(x<=mod)
            printf("%d\n",p[x][y]);
         else 
         { 
            int num=0;
            for(int j=y;j<=maxn;j+=x)
               num+=ans[j]; 
            printf("%d\n",num);
         } 
      }
   }
   return 0; 
}
