#include<iostream>
using namespace std;
int a[31][31];
int main()
{
	int n;
	a[1][1]=1;
	while(cin>>n)
	{
		for(int i=2;i<=n;++i)
		{
			a[i][1]=1;a[i][i]=1;
			for(int j=2;j<=i;++j)
			a[i][j]=a[i-1][j]+a[i-1][j-1];
		}
		for(int i=1;i<=n;++i)
		{
			for(int j=1;j<=i;++j)
			{
			if(j!=i)
			cout<<a[i][j]<<" " ;
			else cout<<a[i][j];
			} 
			cout<<endl;
		}
		cout<<endl;
	}
}


