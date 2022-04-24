#include<bits/stdc++.h>
  
using namespace std;
typedef long long ll;
int dp[105][1805][2][2][2];
int mod=1e9+7;
int a[105];
char s[105];
int dfs(int pos,int sum,bool sa,bool sb,int limit){
    if(pos==-1)return sum>900;
    if(sum+(pos+1)*9<=900)return 0;
    if(dp[pos][sum][sa][sb][limit]!=-1)return dp[pos][sum][sa][sb][limit];
    int up1=sa?a[pos]:9;
    int up2=sb?a[pos]:9;
    int ans=0;
    if (limit)
    {
        for(int i=0;i<=up1;++i){
            for(int j=0;j<=up2;++j){
                ans=(ans+dfs(pos-1,sum+i-j,sa&&(i==up1),sb&&(j==up2),1));
                if(ans>=mod)ans-=mod;
            }
        }
    } else
    {
        for(int i=0;i<=up1;++i){
            for(int j=i;j<=up2;++j){
                ans=(ans+dfs(pos-1,sum+i-j,sa&&(i==up1),sb&&(j==up2),i<j));
                if(ans>=mod)ans-=mod;
            }
        }
    }
    dp[pos][sum][sa][sb][limit]=ans;
    return ans;
}
int main()
{
   scanf("%s",s);
   memset(dp,-1,sizeof(dp));
   int ps=0,len=strlen(s);
   for(int i=len-1;i>=0;--i)
      a[ps++]=s[i]-'0';
   printf("%d\n",dfs(ps-1,900,1,1,0));
   return 0;
}
