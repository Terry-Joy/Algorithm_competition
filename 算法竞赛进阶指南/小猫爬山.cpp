#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int c[20],cab[20];
int n,w,ans; 
void dfs(int cat,int cnt)
{
	if(cnt>=ans)return;
	if(cat==n+1){
		ans=min(ans,cnt);
		return;
	}
	for(int i=1;i<=cnt;++i)
	{
		if(cab[i]+c[cat]<=w)
		{
			cab[i]+=c[cat];
			dfs(cat+1,cnt);
			cab[i]-=c[cat];
		}
	}
	cab[cnt+1]=c[cat];
	dfs(cat+1,cnt+1);
	cab[cnt+1]=0;
}
bool cmp(int a,int b)
{
	return a>b;
}
int main()
{
	scanf("%d%d",&n,&w);
	for(int i=1;i<=n;++i)
		scanf("%d",&c[i]);
	sort(c+1,c+n+1,cmp);
	ans=n;
	dfs(1,0);
	cout<<ans;
	return 0;
} 
