#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
int n,m,cost[maxn],need[maxn],d[maxn],df[maxn],l[maxn],r[maxn];
bool is_ok(int x)
{
	for(int i=0;i<=n+1;++i)
		df[i]=0;
	for(int i=1;i<=x;++i)
	{
		df[l[i]]+=d[i];
		df[r[i]+1]-=d[i];
	}
	for(int i=1;i<=n;++i)
	{
		need[i]=need[i-1]+df[i];
		if(need[i]>cost[i])return false;
	}
	return true;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
		scanf("%d",&cost[i]);
	for(int i=1;i<=m;++i)
	 scanf("%d%d%d",&d[i],&l[i],&r[i]);
	 int left=1,right=m+1;
	 if(is_ok(right))
	 {cout<<"0";return 0;}
	 right=m+1;
	 while(left<right)
	 {
	 	int mid=(left+right)>>1;
	 	if(!is_ok(mid))right=mid;
	 	else left=mid+1;
	 }
	 cout<<"-1\n"<<right;
	 return 0;
}
