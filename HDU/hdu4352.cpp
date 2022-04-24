#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#define ll long long
using namespace std;
ll dp[19][1<<10][10],l,r;
int K,a[20];

int getsum(int s)
{
    int ans=0;
    while(s)
    {
       if(s&1)
          ans++;
       s>>=1; 
    }
    return ans;
}

int getstate(int s,int i)
{
   int j;
   bool flag=0;
   for(j=i;j<=9;++j)
   {
      if(s&(1<<j))//有比它大的且LIS长度相等的
      {
         flag=1;
         break; 
      } 
   } 
   int state;
   if(flag)                         //更新同长度LIS末尾最小元素
       state=((s^(1<<j))|(1<<i));
   else
       state=(s|(1<<i));
   return state;
}

ll dfs(int pos,bool limit,bool lead,int state)
{
   if(pos==-1)return getsum(state)==K;
   if(!limit&&!lead&&dp[pos][state][K]!=-1)return dp[pos][state][K];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   {
      int s=getstate(state,i);
      ans+=dfs(pos-1,limit&&i==a[pos],lead&&i==0,(lead&&i==0)?0:s); 
   } 
   if(!limit&&!lead)dp[pos][state][K]=ans;
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
   return dfs(pos-1,1,1,0);
}

int main()
{
   int t;
   scanf("%d",&t);
   memset(dp,-1,sizeof(dp));
   int k=0;
   while(t--)
   {
       scanf("%lld%lld%d",&l,&r,&K);
       printf("Case #%d: %lld\n",++k,solve(r)-solve(l-1));
   }
   return 0; 
}
