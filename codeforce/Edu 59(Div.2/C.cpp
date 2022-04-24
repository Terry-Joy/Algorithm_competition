#include<iostream>
#include<cstdio>
#include<queue>
#define int long long 
using namespace std;
priority_queue<int> q;
int arr[200005];
char s[200005];
int32_t main()
{
	 int k,n;
	 scanf("%lld%lld",&k,&n);
	 for(int i=1;i<=k;i++)
	 scanf("%lld",&arr[i]);
	 scanf("%s",s+1);
	 long long ans=0;
	 for(int i=1;i<=k;i++)
	 {
	 	if(i==1||s[i]==s[i-1]) q.push(arr[i]);
	 	else
	 	{
	 		int tot=n;
	 		while(!q.empty())
	 		{
	 			if(tot)
	 			{
	 				ans+=q.top();
	 				tot--;
	 			}
	 			q.pop();
	 		}
	 		q.push(arr[i]);
	 	}
	 }
	 int tot=n;
	 		while(!q.empty())
	 		{
	 			if(tot)
	 			{
	 				ans+=q.top();
	 				tot--;
	 			}
	 			q.pop();
	 		}
	 printf("%lld\n",ans);
}
