#include<cstdio>
using namespace std;
int n;
int a[100000];
int pointer[100000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;++i)
	scanf("%d",&a[i]);
	int max_1=a[0];
	int max_2;
	int i=1;
	while(i<n)
	{
		if(a[i]>a[i-1])
		max_1+=a[i];
		else 
		{
			max_2=max(max_2,max_1);
			max_1=0;
		}
		++i;
	}

}
