#include<iostream>
#include<algorithm>
using namespace std;
struct cow
{
	int start;
	int end;
};
cow a[50010];
int is_exit[50010]; 
bool cmp1(cow x,cow y)
{
	return x.end<y.end;
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	cin>>a[i].start>>a[i].end;
	sort(a+1,a+n+1,cmp1);
	int k=n-1,temp,ans=0,j;
		for(j=1;k>0;++j)
		{
			for(int i=1;i<=n;++i)
			{
				if(i==1&&!is_exit[i])
				{
					temp=a[i].end;
					is_exit[i]=j;
				}
				else
				{
					if(a[i].start>temp&&!is_exit[i])
					{
						temp=a[i].end;
						is_exit[i]=j;
						k--;
						if(k<=0)
						{
						cout<<j<<endl;
						break;
						}
					}
				}
			}
			for(int i=1;i<=n;++i)
			if(!is_exit[i])
			{
				is_exit[i]=j+1;
				temp=a[i].end;
				k--;
				if(k<=0)
				{	
					cout<<j+1<<endl;
					break;
				}
				break;
			}
		}
	if(j==1)
	{
		cout<<"1"<<endl;
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;++i)
	cout<<is_exit[i]<<endl;
	return 0;
}
