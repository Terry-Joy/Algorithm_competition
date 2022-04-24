#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char a[110],b[110],c[110]; 
int main()
{
	int n;
	scanf("%d",&n);
	while(n--)
	{
		int flag=0;
		scanf("%s%s%s",a,b,c);
		int len=strlen(a);
		for(int i=0;i<len;++i)
		{
			if(a[i]==b[i])
			{
				if(c[i]==a[i])flag=1;
				else {flag=0;break;} 
			} 
			else {
				if(c[i]==a[i]||c[i]==b[i])flag=1;
				else {flag=0;break;}
			}
		}
		if(flag==1)printf("YES\n");
		else printf("NO\n");
	}
	return 0;
} 
