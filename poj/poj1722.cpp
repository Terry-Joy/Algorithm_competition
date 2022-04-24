#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
const int maxn=110;
const int base=10005;
int dp[maxn][base<<1],ans[maxn],now,cnt,a[maxn];
int main()
{
   int n,t;
   scanf("%d%d",&n,&t);
   for(int i=1;i<=n;++i) 
       scanf("%d",&a[i]);
   dp[1][a[1]+base]=1;
   dp[2][a[1]-a[2]+base]=-1;
   for(int i=3;i<=n;++i)
       for(int j=-10000+base;j<=10000+base;++j){
           if(dp[i-1][j]!=0){ 
               dp[i][j+a[i]]=1;
               dp[i][j-a[i]]=-1; 
           } 
       } 
   now=t+base;
   for(int i=n;i>=2;--i){ 
       ans[i]=dp[i][now];
       if(ans[i]==1) 
           now-=a[i];
       else if(ans[i]==-1) 
           now+=a[i];
   } 
   int cnt=0;
   for(int i=2;i<=n;++i) 
       if(ans[i]==1){ 
          printf("%d\n",i-cnt-1);
          cnt++; 
       }
   for(int i=2;i<=n;++i) 
       if(ans[i]==-1)
          puts("1");
   return 0; 
}
