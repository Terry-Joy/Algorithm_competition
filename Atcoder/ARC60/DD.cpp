#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=20;
int t;
int n;
int a[maxn];
int f[maxn][maxn];
int main()
{
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>t;
	while (t--)
	{
		cin>>n;
		for (int i=1;i<=n;i++) cin>>a[i];
		memset(f,0x3f,sizeof(f));
		for (int i=1;i<=n;i++) f[i][i]=a[i];
		for (int k=2;k<=n;k++)
		{
			for (int i=1;i+k-1<=n;i++)
			{
				int j=i+k-1;
				for (int mid=i;mid<=j-1;mid++)
					f[i][j]=min(abs(f[i][mid]-f[mid+1][j]),f[i][j]);
			}
		}
		cout<<f[1][n]<<endl;
	}
	return 0;
}
