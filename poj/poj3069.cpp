#include<iostream>
#include<algorithm>
using namespace std;
int army[1010];
int main()
{
	int r,n;
	while(cin>>r>>n)
	{
		if(r==-1&&n==-1)
		break;
		for(int i=0;i<n;++i)
		cin>>army[i];
		sort(army,army+n);
		int i=0,ans=0;
		while(i<n)
		{
			int temp=army[i++];
			while(i<n&&army[i]-temp<=r)
			++i;
			int p=army[i-1];
			while(i<n&&army[i]-p<=r)++i;
			ans++;
		}
		cout<<ans<<endl;
	}
	return 0;
}
