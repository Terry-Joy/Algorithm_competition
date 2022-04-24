#include<cstdio>
#include<cmath>
#include<algorithm> 
using namespace std;
struct node
{
	int time;
	int xi;
};
node x[100010];
bool cmp1(node q,node w)
{
	return q.time<w.time;
}
int main()
{
	int n,a;
	scanf("%d",&n);
	int k=n;
	while(n--)
	{
		scanf("%d",&a);
		for(int i=0;i<a;++i)
		scanf("%d%d",&x[i].time,&x[i].xi);
		sort(x,x+a,cmp1);
		double ans=0,tef;
		for(int i=0;i<a-1;++i)
		{
			tef=abs(x[i].xi-x[i+1].xi)*1.0/(x[i+1].time-x[i].time)*1.0;
			if(tef>ans)
			ans=tef;
		}
		printf("Case #%d: %.2lf\n",k-n,ans);
	}	
	return 0;
} 
