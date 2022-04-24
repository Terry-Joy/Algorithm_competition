#include<iostream>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
struct map
{
	int x;
	int y;
};
struct map2
{
	double left;
	double right;
};
map number[1010];
map2 sum[1010];
bool cmp1(map2 a,map2 b)
{
	if (a.left==b.left)
		return a.right>b.right;
	return a.left<b.left;
}
int main()
{
	int n,a,f; 
	int ans=0;
	while(cin>>n>>a)
	{
		if(n==0&&a==0)
		break;
		ans++;
	for(int i=1;i<=n;++i)
	{
		cin>>number[i].x>>number[i].y;
		if(number[i].y>a)
		f=1;
	}
	if(f)
		{
		cout<<"Case: "<<ans<<": -1"<<endl;
		f=0;
		}
	else 
	{
		for(int i=1;i<=n;++i)
		{
			sum[i].left=number[i].x-sqrt(a*a*1.0-1.0*number[i].y*number[i].y);
			sum[i].right=number[i].x+sqrt(a*a*1.0-1.0*number[i].y*number[i].y);
		}
		sort(sum+1,sum+n+1,cmp1);
		int j=2;
		int num=1;
		int temp=sum[1].right;
		while(j<=n)
		{
			if(sum[j].left<=temp);
			else if(sum[j].left>temp)
			{
				num++;
				temp=sum[j].right;
			}
			++j;
		}
		cout<<"Case: "<<ans<<": "<<num<<endl;
	}
	}
	return 0;
}
 
