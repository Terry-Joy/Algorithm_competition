#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
string s;
ll dp[105][105][105];
int a[105];
ll dfs(int l,int r,int k)
{
   if(l>r)return 0;
   if(l==r)return a[k+1];
   if(dp[l][r][k]!=-1)return dp[l][r][k];
   ll ans=dfs(l+1,r,0)+a[k+1]; 
   for(int i=l+1;i<=r;++i)
       if(s[l]==s[i])ans=max(ans,dfs(l+1,i-1,0)+dfs(i,r,k+1));
   dp[l][r][k]=ans;
   return ans;
}
int main()
{
   int n;
   scanf("%d",&n);
   cin>>s; 
   for(int i=1;i<=n;++i)
       scanf("%d",&a[i]);
   memset(dp,-1,sizeof(dp));
   cout<<dfs(0,n-1,0)<<endl;
   return 0; 
}
