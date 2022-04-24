#include<iostream>
#include<cstdio>
using namespace std;
const int maxn=1e5+10;
int main()
{
	char a[maxn],b[maxn];
	int n,a1[maxn],b1[maxn],lena=0,lenb=0;
	scanf("%d",&n);
		scanf("%s%s",a+1,b+1);
	for(int i=1;i<=n;++i)
	{
		if(a[i]>b[i])
			{
				a1[++lena]=i;
			}
		else if(a[i]<b[i])
		{
			b1[++lenb]=i;
		}
	}
	if(lena==0)printf("NO");
	else {
		if(a1[1]!=1)
		{
			printf("YES\n");
			printf("1 %d",a1[1]);
		}
		else {
			if(n==2)
			{
				if(a[2]<b[2])
					printf("NO");
				else
					{
						printf("YES\n");
						printf("1 2");	
					}
			}
			else
				{
					printf("YES\n");
					printf("2 3");
				}
		}
	}
	return 0;
}
