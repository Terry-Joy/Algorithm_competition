#include<iostream>
using namespace std;
int main()
{
	int n,a,b;
	cin>>n;
	while(n--)
	{
		cin>>a>>b;
		
		for(int j=1;j<=a;++j)
		{
		for(int k=1;k<=a;++k)
		{
			if(j==k||k==a-j+1)
			printf("X");
			else printf(" ");
			if(j<=a/2&&k==a-j+1||j>a/2&&k==j)
			break;
		}
			printf("\n"); 
		}
		int i;
		for(i=2;i<=b;++i)
		{
		for(int j=2;j<=a;++j)
		{
			int k;
		for(k=1;k<=a;++k)
		{
			if(j==k||k==a-j+1)
			printf("X");
			else printf(" ");
			if(j<=a/2&&k==a-j+1||j>a/2&&k==j)
			break;
			
		}
		
			printf("\n"); 
		}
		
		}
		if(i!=b)
		printf("\n");
	}
	return 0;
}
