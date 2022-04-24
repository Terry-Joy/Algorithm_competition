#include<iostream>
#include<cstdio>
using namespace std;
char a[100000];
int b[30];
int main()
{
	int n,k;
	scanf("%d%d",&n,&k);
	cin>>a;
	int len=-1;
	char c=0;
	while(cin>>c && len<k-1)
	{		
		if(c>='a' && c<='z')
			b[++len]=c;
	}
	int num=0,w=0,q=1,i=0;
	while(i<n)
	{
		for(int j=0;j<k;++j)
		{
		if(a[i]==b[j])
		break;
		else if(j==k-1&&q==1)
		q=0;
		}
		if(q==1)
		w++;
		else 
		{
		num+=((w+1)*w)/2;
		w=0;
		}
		i++;
	}
	printf("%d",num);
} 
