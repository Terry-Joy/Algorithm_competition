#include<cstdio>
#include<queue>
using namespace std;
int n,k,a;
char c;
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	while(scanf("%d%d",&n,&k)!=EOF)
	{
		while(!q.empty())
		q.pop();
		while(n--)
		{
			getchar();
			scanf("%c",&c);
			if(c=='I')
			{
				scanf("%d",&a);
				q.push(a);
				if(q.size()==k+1)
				q.pop();
			}
			else if(c=='Q')
			printf("%d\n",q.top());
		}
	}
	return 0;
} 
