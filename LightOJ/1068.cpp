#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[12][93][93];//pos mod %k
int a[12];

int dfs(int pos,bool limit,int mod,int k,int mod2)
{
   if(pos==-1)return (mod==0&&mod2==0);
   if(!limit&&dp[pos][mod][mod2]!=-1)return dp[pos][mod][mod2];
   int ans=0;
   int up=limit?a[pos]:9;
   for(int i=0;i<=up;++i) 
       ans+=dfs(pos-1,limit&&i==a[pos],(mod+i)%k,k,(mod2*10+i)%k);
   if(!limit)dp[pos][mod][mod2]=ans;
   return ans;
}

int solve(int x,int k)
{ 
    int pos=0;
    while(x)
    {
       a[pos++]=x%10;
       x/=10; 
    }
    return dfs(pos-1,1,0,k,0);
}

int main()
{
   int t,f=0;
   scanf("%d",&t);
   while(t--)
   {
      int l,r,k;
      memset(dp,-1,sizeof(dp));
      scanf("%d%d%d",&l,&r,&k);
      if(k>93)
      	printf("Case %d: %d\n",++f,0);
      else
      	printf("Case %d: %d\n",++f,solve(r,k)-solve(l-1,k)); 
   }
   return 0; 
}
