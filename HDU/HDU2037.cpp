#include<iostream>
#include<algorithm>
using namespace std;
struct tv
{
	int a;
	int b;
};
tv le[100000];
bool cmp2(tv x,tv y)
{
	return x.b<y.b;
}
int main()
{
	int n;
	while(cin>>n&&n)
	{
		for(int i=0;i<n;++i)
		cin>>le[i].a>>le[i].b;
		sort(le,le+n,cmp2);
		int end=le[0].b,num=1;
		for(int i=1;i<n;++i)
		{
		if(le[i].a>=end)
			{
				num++;
				end=le[i].b;
			}
			
		}
		cout<<num<<endl;
	}
	return 0;
}
