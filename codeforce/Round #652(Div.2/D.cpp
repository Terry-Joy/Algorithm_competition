#include<bits/stdc++.h>
#define pb push_back
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
ll dp[2000010];
const int mod=1e9+7;
int main()
{
   int n;
   scanf("%d",&n);
   dp[1]=0;
   dp[2]=0;
   dp[3]=4;
   dp[4]=4;
   dp[5]=12;
   for(int i=6;i<=2000000;++i)
   {
      dp[i]=dp[i-1]+2*dp[i-2];
      if(i%3==0)dp[i]+=4; 
      dp[i]%=mod; 
   } 
   while(n--)
   {
      int x; 
      scanf("%d",&x); 
      printf("%lld\n",dp[x]);
   }
   return 0; 
}
