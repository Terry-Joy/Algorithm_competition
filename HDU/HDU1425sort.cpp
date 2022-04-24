#include<iostream>
#include<algorithm>
using namespace std;
const int max_1=1e7;
int a[max_1];
int cmp2(int x,int y)
{
	return x>y;
}
int main()
{
	int n,m;
	while(scanf("%d %d",&n,&m)!=EOF)
	{	
	for(int i=0;i<n;++i)
	scanf("%d",&a[i]);
	sort(a,a+n,cmp2);
	for(int i=0;i<m;++i)
	{
		if(i!=m-1)
		printf("%d ",a[i]);
		else printf("%d\n",a[i]);
	}
	}
	return 0;
} 


