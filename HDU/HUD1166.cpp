#include<iostream>
#include<cstdio>
#include<cstring>
#define ll long long 
using namespace std;
int t,n,l,r;int a[50010],c[50010];
char s[10];
void add(int x,int y)
{
	for(;x<=n;x+=x&-x)c[x]+=y;
}
int ask(int x)
{
	int ans=0;
	for(;x;x-=x&-x)ans+=c[x];
	return ans;	
}
int main()
{
	scanf("%d",&t);
	int k=0;
	while(t--)
	{
		memset(c,0,sizeof(c));
		scanf("%d",&n);
		for(int i=1;i<=n;++i)
		{
			scanf("%d",&a[i]);
			add(i,a[i]);
		}
		cout<<"Case "<<++k<<":"<<"\n";
		while(cin>>s&&s[0]!='E')
		{
			scanf("%d%d",&l,&r);
			 if(s[0]=='Q')printf("%d\n",ask(r)-ask(l-1));
			else if(s[0]=='A')add(l,r);
			else if(s[0]=='S')add(l,-r);

		}
	} 
	return 0;
} 
