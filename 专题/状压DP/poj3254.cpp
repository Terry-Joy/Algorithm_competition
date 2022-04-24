#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[13][1<<12];
int st[1<<12],mp[13];
const int mod=1e8;
bool adj(int x)             //判断不相邻
{
   return (x&(x<<1)); 
}

bool is(int i,int j)
{
   return (st[i]&mp[j]); 
}

int main()
{
   int m,n,a;
   scanf("%d%d",&m,&n);
   for(int i=1;i<=m;++i)
      for(int j=1;j<=n;++j)
      {
         scanf("%d",&a); 
         if(!a)
          mp[i]+=(1<<j-1);       //把每一行不能状态记录下来
      } 
   int cnt=0;
   for(int i=0;i<(1<<n);++i)
   {
      if(!adj(i))
        st[++cnt]=i;        //记录每一行不相邻的状态
   }
   for(int i=1;i<=cnt;++i)
   {
      if(!is(i,1))
        dp[1][i]=1;         //先看第一个和自己是否满足
   }
   for(int i=2;i<=m;++i)
   {
       for(int j=1;j<=cnt;++j)//当前行
       {
          if(is(j,i))continue;//自己和自己的限制
          for(int k=1;k<=cnt;++k)   //上一行
          {
              if(is(k,i-1))continue;//看看头上和自己的限制
              if(!(st[j]&st[k]))//上下相邻
                  dp[i][j]=(dp[i][j]+dp[i-1][k])%mod;
          } 
       } 
   }
   int ans=0;
   for(int i=1;i<=cnt;++i)
       ans=(ans+dp[m][i])%mod;
   printf("%d\n",ans);
   return 0; 
}
