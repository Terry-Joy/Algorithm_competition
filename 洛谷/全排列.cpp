#include<iostream>
#include<algorithm>
using namespace std;
int a[100];
int main()
{
	int n;
	cin>>n;
	for(int i=0;i<n;++i)
	cin>>a[i];
	sort(a,a+n);
	do
	{
		for(int i=0;i<n;++i)
		printf("%d ",a[i]);
		putchar('\n'); 
	}while(next_permutation(a,a+n));
	return 0;
}
