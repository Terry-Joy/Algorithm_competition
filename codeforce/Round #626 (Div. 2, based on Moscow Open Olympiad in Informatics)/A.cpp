#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<queue>
#include<vector>
using namespace std;
int a[110],cnt[110],cnt2[110];
int main()
{
	int n;
	scanf("%d",&n);
	int t;
	while(n--)
	{
		int j=0,k=0;
		scanf("%d",&t);
		for(int i=1;i<=t;++i)
		{
			scanf("%d",&a[i]);
			if(a[i]%2==1)
				cnt[++j]=i;
			else 
				cnt2[++k]=i;
		}
		if(k>0)
		{
			cout<<"1"<<endl;
			cout<<cnt2[1];
		}
		else if(j==1)
			cout<<"-1";
		else if(j%2==1)
		{
			cout<<j-1<<endl;
			for(int i=1;i<=j-1;++i)
			{
				cout<<cnt[i]<<" ";
			}
		}
		else {
			cout<<j<<endl;
			for(int i=1;i<=j;++i)
			{
				cout<<cnt[i]<<" ";
			}
		}
		putchar('\n');	
	}	
	return 0;
} 
