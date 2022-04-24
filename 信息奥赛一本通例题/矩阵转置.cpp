#include<iostream>
#include<iomanip>
using namespace std;
int a[4][4];
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=n;++j)
	cin>>a[i][j];
	for(int i=1;i<=n;++i)
	{
		cout.setf(ios::left);
		for(int j=1;j<=n;++j)
			cout<<setw(5)<<a[j][i];
		cout<<endl;
	}
	return 0;
} 

