#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;

ll dp[20][20][3100];//dp[i][j][k]表示第i位 j为平衡点 k为当前总和 
int a[20];

ll dfs(int pos,bool limit,int sum,int mid)
{
   if(pos==-1)return sum==0;
   if(!limit&&dp[pos][mid][sum+1540]!=-1)return dp[pos][mid][sum+1540];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   {
      if(pos>mid)ans+=dfs(pos-1,limit&&i==a[pos],sum+i*(pos-mid),mid);
      else if(pos<mid)ans+=dfs(pos-1,limit&&i==a[pos],sum-i*(mid-pos),mid); 
      else ans+=dfs(pos-1,limit&&(i==a[pos]),sum,mid);
   }
   if(!limit)dp[pos][mid][sum+1540]=ans;
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
   for(int i=pos-1;i>=0;--i)
   {
      ans+=dfs(pos-1,1,0,i);
   }
   return ans-pos+1;
}

int main()
{
   int t;
   scanf("%d",&t);
   ll x,y;
   memset(dp,-1,sizeof(dp));
   while(t--)
   {
      scanf("%lld%lld",&x,&y);
      printf("%lld\n",solve(y)-solve(x-1)); 
   }
   return 0; 
}
