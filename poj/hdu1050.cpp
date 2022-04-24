#include<iostream>
#include<cstring>
using namespace std;
int temp[210];
int main()
{
	int n;
	cin>>n;
	while(n--)
	{
		int a;
		cin>>a;
		memset(temp,0,sizeof(temp));
		while(a--)
		{
			int start,end;
			cin>>start>>end;
			if(start>end)
			{
				int i=start;
				start=end;
				end=i;
			}
			if(start%2==1)
			start=(start+1)/2;
			else if(start%2==0)
			start=start/2;
			if(end%2==1)
			end=(end+1)/2;
			else if(end%2==0)
			end=end/2;
			for(int i=start;i<=end;++i)
			temp[i]+=10;
		}
		int sum=0;
		for(int i=1;i<=200;++i)
		sum=max(sum,temp[i]);
		cout<<sum<<endl;
	}
	return 0;
}
