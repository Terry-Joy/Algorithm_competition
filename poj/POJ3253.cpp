#include<cstdio>
#include<queue>
#include<algorithm>
#include<iostream>

using namespace std;
long long n,x,y,a;long long sum=0;
priority_queue<int,vector<int>,greater<int> >q; 
int main()
{
	scanf("%d",&n);
	while(n--)
	{
		scanf("%lld",&a);
		q.push(a);
	}
	while(q.size()>1)
	{
		x=q.top();q.pop();
		y=q.top();q.pop();
		sum+=x+y;
		q.push(x+y);
	}
	printf("%lld",sum);
	return 0;
} 
