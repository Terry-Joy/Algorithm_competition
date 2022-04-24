#include<cstdio>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn=1e4+10;
priority_queue<int>q;
struct sta
{
	int a,b;
}station[maxn];
int n,l,p,ans;
bool cmp(sta x,sta y)
{
	return x.a>y.a;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	scanf("%d%d",&station[i].a,&station[i].b);
	scanf("%d%d",&l,&p);
	sort(station+1,station+n+1,cmp);
	station[n+1].a=station[n+1].b=0;
	int pos=0;
	for(int i=1;i<=n+1;++i)
	{
		int d=l-station[i].a-pos;
		while(p-d<0)
		{
			if(q.empty())
			{
				printf("-1");
				return 0;
			}
			else 
			{
				p+=q.top();
				q.pop();
				ans++;
			}
		}
		pos=l-station[i].a;
		p-=d;
		q.push(station[i].b);
	}
	printf("%d\n",ans);
	return 0;
}
