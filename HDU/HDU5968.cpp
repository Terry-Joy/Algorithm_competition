#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
int a[110];
int M[110];
int main()
{
	int t,c,k,m,q;
	scanf("%d",&t);
	while(t--)
	{
		
		scanf("%d",&k);
		M[0]=0;
		for(int i=1;i<=k;++i)
		
		{
		scanf("%d",&a[i]);
		M[i]=M[i-1]^a[i];
		}
		
		scanf("%d",&m);
		while(m--)
		{
		
			scanf("%d",&c);
			int len=-1,ab=10000;
			for(int i=1;i<=k;++i)
			{
				for(int j=1;j<=k;++j)
				{
					
					if(ab>abs((M[j]^M[i-1])-c))
					{
					ab=abs((M[j]^M[i-1])-c);
					len=j-i+1;
					}
					else if(ab==abs((M[j]^M[i-1])-c))
					{
						len=max(len,j-i+1);
					}
				}
			}
			printf("%d\n",len);
		}
		printf("\n");
	}
	return 0;
}
