#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;

int dp[105][105][105],sta[1<<10+2],mp[105],num[1<<10];
char s[105][12];

bool adj(int x)
{
   if(((x&(x<<1))==0)&&((x&(x<<2))==0))
       return 1;
   return 0;
}

bool is(int i,int j)
{
    return (mp[i]&sta[j]);
}

int cal(int x)
{
   int cnt=0;
   for(;x;x-=x&-x)
      cnt++; 
   return cnt;
}

int main()
{
   int n,m,cnt=0;
   scanf("%d%d",&n,&m);
   for(int i=1;i<=n;++i)
       scanf("%s",s[i]+1);
   for(int i=1;i<=n;++i)
       for(int j=1;j<=m;++j)
          if(s[i][j]=='H')mp[i]+=(1<<j-1);
   for(int i=0;i<1<<m;++i)
   {
       if(adj(i)) 
         sta[++cnt]=i,num[cnt]=cal(i);
   }
   memset(dp,-1,sizeof(dp));
   int ans=0;
   for(int i=1;i<=cnt;++i)
   	{
		if(is(1,i)==0)
			dp[1][i][1]=num[i];
		ans=max(ans,dp[1][i][1]);   		
   }	
   for(int i=2;i<=n;++i)
   {
   		for(int j=1;j<=cnt;++j)			 
   		{
   			if(is(i,j))continue;			//自己不能违背 
   			for(int k=1;k<=cnt;++k)
   			{
   				if((is(i-1,k)==0)&&((sta[j]&sta[k])==0))	//自己和上一个 
   				{
   					int last=0;
   					for(int f=1;f<=cnt;++f)
   					{//自己和上一个 自己和上上个 
   						if((is(i-2,f)==0)&&(dp[i-1][k][f]!=-1)&&(sta[j]&sta[f])==0)
   							last=max(last,dp[i-1][k][f]);
					}
					dp[i][j][k]=max(dp[i][j][k],last+num[j]);
					if(i==n)
						ans=max(ans,dp[i][j][k]);   
				}
			}
		}
   }
   	printf("%d\n",ans);
   return 0; 
}
