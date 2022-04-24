#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
const int MOD=2520;
ll dp[19][2525][50];//dp[i][j][k]表示第i位模数为j 前面的最小公倍数为k的个数
int a[20],map[2525],cnt=0;

inline int gcd(int a,int b)
{
   return  b?gcd(b,a%b):a;
}

inline int lcm(int a,int b)
{
   if(a==0||b==0)return a+b;
   return a*b/gcd(a,b); 
}

ll dfs(int pos,bool limit,int now_lcm,int sum)
{
    if(pos==-1)return (sum%now_lcm==0);
    if(!limit&&dp[pos][sum][map[now_lcm]]!=-1)return dp[pos][sum][map[now_lcm]];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i)
    {
        ans+=dfs(pos-1,limit&&(i==a[pos]),lcm(now_lcm,i),(sum*10+i)%MOD);
    }
    if(!limit)dp[pos][sum][map[now_lcm]]=ans;
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
   for(int i=1;i<=MOD;++i)
   {
      if(MOD%i==0)
         map[i]=++cnt; 
   }
   scanf("%d",&t);
   memset(dp,-1,sizeof(dp));
   while(t--)
   {
       ll l,r;
       scanf("%lld%lld",&l,&r);
       printf("%lld\n",solve(r)-solve(l-1));
   }
   return 0; 
}
