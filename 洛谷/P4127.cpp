#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;
int a[20],mod;
ll dp[21][165][165];//dp[i][j][k]表示枚举到第i位前面的和为j,余数为k的个数

ll dfs(int pos,bool limit,int sum,int mod1)
{
   if(sum+9*(pos+1)<mod)return 0;//剪枝求和不能小于模数
   if(pos==-1)
    {
       if(sum==mod&&mod1==0)return 1;
       else return 0;
    } 
   if(!limit&&dp[pos][sum][mod1]!=-1)return dp[pos][sum][mod1];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up&&i+sum<=mod;++i)//剪枝
       ans+=dfs(pos-1,limit&&i==a[pos],sum+i,(mod1*10+i)%mod);
   if(!limit)dp[pos][sum][mod1]=ans;
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
    int j,k,f;
    for(int i=1;i<=9*pos;++i)
    {
        mod=i; 
        for(j=0;j<=pos;++j)
            for(k=0;k<=i;++k)
                for(f=0;f<=i;++f)
                    dp[j][k][f]=-1;
        ans+=dfs(pos-1,1,0,0);
    }
    return ans;
}

int main()
{ 
    ll x,y;
    scanf("%lld%lld",&x,&y);
    printf("%lld\n",solve(y)-solve(x-1));
    return 0;
}