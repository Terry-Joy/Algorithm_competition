#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
const int maxn=2e5+10;
using namespace std;
int p[maxn];
char s[maxn];
int main()
{
	int t,n;
	scanf("%d",&t);
	for(int i=1;i<=t;++i)
	{
		scanf("%d%s",&n,s+1);
		for(int i=1;i<=n;++i)
			p[i]=n-i+1; //n~1的序列 
		for(int i=1;i<n;)
		{
			int j=i;
			while(s[j]=='<')j++;  
			reverse(p+i,p+j+1); //最优反转 
			i=j+1;
		}
		for(int i=1;i<=n;++i)printf("%d ",p[i]);
		putchar('\n');
		for(int i=1;i<=n;++i)p[i]=i;
		for(int i=1;i<n;)
		{
			int j=i;
			while(s[j]=='>')j++;
			reverse(p+i,+p+j+1);
			i=j+1; 
		}
		for(int i=1;i<=n;++i)printf("%d ",p[i]);
		putchar('\n');	
	}
	return 0;
} 
