#include<cstdio>
#include<algorithm>
using namespace std;
struct cow
{
	int start;
	int end;
}a[25010];
bool cmp1(cow x,cow y)
{
	if(x.start==y.start)
		return x.end>y.end;
	return x.start<y.start;
}
int main() 
{
	freopen("1.out","w",stdout);
	int n,t;
	scanf("%d%d",&n,&t);
	for(int i=0;i<n;++i)
		scanf("%d%d",&a[i].start,&a[i].end);
	cout<<n<<t<<endl;
	for(int i=0;i<n;++i)
		printf("%d %d\n",a[i].start,a[i].end);
	sort(a,a+n,cmp1);
	if(a[0].start>1)
	{
		printf("-1");
		return 0;
	}
	int i=0,now=0,maxn=0,ans=1;
	int e=a[0].end;
	while(e<t)
	{
		for(i=now+1;a[i].start<=a[now].end;++i)
			if(a[i].end>a[maxn].end)
				maxn=i;
		if(now==maxn) break;
		ans++;
		now=maxn;
		e=a[maxn].end;
	}
	if(e<t)
		printf("-1");
	else 
		printf("%d",ans);
	return 0;
}
