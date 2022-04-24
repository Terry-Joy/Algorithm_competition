#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long
using namespace std;
char s[2005];
int m,d;
ll dp[2002][2002][2];//pos mod bits 假如用pos代表奇偶的话的话可以不用加第三维
int a[2002],b[2002];
const int MOD=1e9+7;

ll dfs(int pos,bool limit,bool lead,bool bits,int mod)
{
   if(pos==-1)return (mod==0);
   if(!limit&&!lead&&dp[pos][mod][bits]!=-1)return dp[pos][mod][bits];
   int up=limit?a[pos]:9;
   ll ans=0;
   for(int i=0;i<=up;++i)
   { 
       if(lead&&i!=0)
           if(i==d)continue;

       if(!lead) //奇数偶数位判断
       {
          if(!bits&&i!=d)continue;//有continue不用带is这一维
          if(bits==1&&i==d)continue;
       }
       ans=(ans+dfs(pos-1,limit&&i==a[pos],lead&&i==0,lead?0:bits^1,(mod*10+i)%m))%MOD;
   }
   if(!limit&&!lead)dp[pos][mod][bits]=ans;
   return ans;
}

int main()
{
   memset(dp,-1,sizeof(dp));
   scanf("%d%d",&m,&d);
   scanf("%s",s);
   int len1=strlen(s);
   ll ans=0;
   for(int i=0;i<len1;++i)
   {     
       b[i]=s[len1-i-1]-'0';
   }
   scanf("%s",s);
   int len2=strlen(s);
   for(int i=0;i<len2;++i)
       a[i]=s[len2-i-1]-'0';
   ans+=dfs(len2-1,1,1,0,0);
   for(int i=0;i<len1;++i)
       a[i]=b[i];

      int k=0;
      while(a[k]<1)k++;//单独判断边界更快
      while(k)
      {
         a[k]--;
         if(a[k]==0&&k==(len1-1))len1--;
         k--;
         a[k]+=10; 
      }
      a[k]-=1;
   ans-=dfs(len1-1,1,1,0,0);
   printf("%lld",(ans+MOD)%MOD);
   return 0; 
}
