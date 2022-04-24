#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
#include<cmath>
#include<vector>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
typedef long long ll;
using namespace std;
ll dp[15][15][10][57];//pos 前面有多少个小于i i 前面总逆序对个数
int a[16];

ll dfs(int pos,int val,int sum,bool limit,bool lead,int d)
{
   if(pos==-1)return sum;
   if(!limit&&!lead&&dp[pos][val][d][sum]!=-1)return dp[pos][val][d][sum];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   {
      if(i==0&&lead)
         ans+=dfs(pos-1,val,sum,limit&&i==a[pos],1,d);
      else
         ans+=dfs(pos-1,val+((i<d)?1:0),sum+((i==d)?val:0),limit&&i==a[pos],lead&&i==0,d); 
   } 
   if(!limit&&!lead)dp[pos][val][d][sum]=ans;
   return ans;
}

ll solve(ll x)
{
   int pos=0;
   while(x)
   {
      a[pos++]=x%10;
      x/=10; 
   } 
   ll ans=0;
   for(int i=1;i<=9;++i)
    ans+=dfs(pos-1,0,0,1,1,i);
   return ans; 
}

int main()
{
   int t;
   scanf("%d",&t);
   int k=0;
   memset(dp,-1,sizeof(dp));
   while(t--)
   {
      ll l,r;
      scanf("%lld%lld",&l,&r);
      printf("Case %d: %lld\n",++k,solve(r)-solve(l-1));  
   } 
   return 0; 
}
