#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6+10;
char a[maxn],b[maxn];
int next[maxn],f[maxn];
int main()
{
	scanf("%s%s",a+1,b+1);
	int j;
	next[1]=j=0;
	int la=strlen(a+1),lb=strlen(b+1); 
	for(int i=2;i<=lb;++i)
	{
		while(j>0&&b[i]!=b[j+1]) j=next[j];
		if(b[i]==b[j+1]) j++;
		next[i]=j;
	}
	j=0;
	for(int i=1;i<=la;++i)
	{
		while(j>0&&a[i]!=b[j+1]) j=next[j];
		if(a[i]==b[j+1]) j++;
		f[i]=j;
		if(j==lb) printf("%d\n",i-lb+1),j=next[j];
	}
	for(int i=1;i<lb;++i)
		printf("%d ",next[i]);
	printf("%d",next[lb]);
	return 0;
} 
