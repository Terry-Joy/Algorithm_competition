#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
pair<string,int>a[100005];
int n,m,x;char s[6];
int cal(int bit,int now)
{
	for(int i=1;i<=n;++i){
		int x=(a[i].second>>bit)&1;
		if(a[i].first=="AND")now&=x;
		else if(a[i].first=="OR")now|=x;
		else now^=x;
	}
	return now;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;++i)
	{
		scanf("%s%d",s,&x);
		a[i]=make_pair(s,x);
	}
	int val=0,ans=0;
	for(int i=29;i>=0;--i)
	{
		int res0=cal(i,1),res1=cal(i,0);
		if(val+(1<<i)<=m&&res0>res1)
		val+=1<<i,ans+=res0<<i;
		else ans+=res1<<i;
	}
	printf("%d",ans);
	return 0;	
}
