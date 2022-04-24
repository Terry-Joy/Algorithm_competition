#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;

ll dp[2010][11][2];
const ll mod=1e9+7;
char s1[2010],s2[2010];
int len1,len2;
int a[2010];
ll dfs(int pos,bool limit,bool lead,int pre,int pre2,bool is)
{
    if(pos==-1)return is;
    if(!limit&&!lead&&pre2!=-1&&dp[pos][pre][is]!=-1)return dp[pos][pre][is];
    int up=limit?a[pos]:9;
    ll ans=0;
    for(int i=0;i<=up;++i)
    {
       ans=(ans+dfs(pos-1,limit&&(i==a[pos]),lead&&(i==0),i,(lead==1)?-1:pre,is||((pre==i)&&(lead==0||(i!=0)))||((pre2==i&&(lead==0||i!=0)))))%mod; 
    }
    if(!limit&&!lead&&pre2!=-1)dp[pos][pre][is]=ans;
    return ans%mod;
}

ll solve(int x)
{
    if(x==1)
    {
       for(int i=0;i<len1;++i)
           a[i]=s1[len1-i-1]-'0';   
       if(a[0]>=1)a[0]-=1;
	   else
	   {
	   		int k=1;
	   		while(a[k]<1)k++;
	   		if((k==len1-1)&&(a[k]==1))len1--;
	   		a[k]-=1;
	   		a[k-1]+=10;
	   		while(k!=0)
	   		{
	   			k--;
	   			a[k]-=1;
	   			if(k!=0)
	   			a[k-1]+=10;
			}
		} 
       return dfs(len1-1,1,1,-1,-1,0);
    }
    else if(x==2)
    {
        for(int j=0;j<len2;++j)
            a[j]=s2[len2-j-1]-'0';
        return dfs(len2-1,1,1,-1,-1,0);
    }
}

int main()
{
   memset(dp,-1,sizeof(dp));
   scanf("%s%s",s1,s2);
   len1=strlen(s1),len2=strlen(s2);
   printf("%lld\n",(solve(2)-solve(1)+mod)%mod);
   return 0; 
}