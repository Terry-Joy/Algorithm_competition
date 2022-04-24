#include<cstdio>
#include<cmath>
#include<cstring>
#include<iostream>
#include<algorithm>
int n,stick[100],is_used[100],sum,ans,num,number=0;
using namespace std;
bool dfs(int k,int len,int last)
{
	if(k>number)return true;
	if(len==num)return dfs(k+1,0,0);
	int fail=0;
	for(int i=last;i<n;++i)
	if(!is_used[i]&&len+stick[i]<=num&&fail!=stick[i])
	{
		is_used[i]=1;
		if(dfs(k,len+stick[i],i+1))return true;
		is_used[i]=0;
		fail=stick[i];
		if(len==0)return false;
	}
	return false;
}
bool cmp1(int x,int y)
{
	return x>y;
}
int main()
{
	scanf("%d",&n);
		ans=0,sum=0;
		memset(is_used,0,sizeof(is_used));
		for(int i=0;i<n;++i)
		{
			scanf("%d",&stick[i]);
			sum+=stick[i];
			ans=max(stick[i],ans);
		}
		sort(stick,stick+n,cmp1);
		for(num=ans;num<=sum;++num)
		{
			if(sum%num)continue;
			number=sum/num;
			if(dfs(1,0,0))break;
		}
		printf("%d\n",num);
	return 0;
}
