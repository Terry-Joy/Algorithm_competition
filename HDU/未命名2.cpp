#include<cstdio>
#include<queue>
#include<iostream>
using namespace std;
int n,a,ans;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	while(cin>>n)
	{
	ans=0;
	for(int i=1;i<=n;++i)
	{
		cin>>a;
		q.push(a);
	}
	for(int i=1;i<=n-1;++i)
	{
		int x=q.top();q.pop();
		int y=q.top();q.pop();
		ans+=x+y;
		q.push(x+y);
	
	}
	cout<<ans<<"\n";
	}
	return 0;
}

