#include<iostream>
#include<iomanip>
using namespace std;
int a[100][100];
int main()
{
	int n;
	while(cin>>n){
	a[1][1]=1;
	for(int i=2;i<=n;++i)
	{
		a[i][1]=1;a[i][i]=1;
		for(int j=2;j<=i-1;++j)
		a[i][j]=a[i-1][j]+a[i-1][j-1];
	}
	for(int i=1;i<=n;++i)
	{	
		for(int j=1;j<=i;++j)
		{
			if(j!=i)
		cout<<a[i][j]<<" ";
		else cout<<a[i][j]<<endl;
	}
	}
	cout<<endl;
	}
	return 0;
}
 
