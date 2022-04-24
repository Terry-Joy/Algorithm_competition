#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
const int maxn=30010; 
int fa[maxn],d[maxn],size[maxn],t,b,c;
char a; 
int find(int x)
{
	if(x==fa[x])return x;
	int root=find(fa[x]); 
	d[x]+=d[fa[x]]; 
	return fa[x]=root; 
}
void init(int x,int y)
{
	int f1=find(x),f2=find(y);
	fa[f1]=f2;d[f1]=size[f2];
	size[f2]+=size[f1];
}

int main()
{
	scanf("%d",&t);
	for(int i=1;i<=30000;++i)
	{
		fa[i]=i;
		size[i]=1;
	}
	for(int i=1;i<=t;++i)
	{
		cin>>a;
		scanf("%d%d",&b,&c);
		if(a=='M')
			init(b,c);
		else {
			if(find(b)!=find(c))
				printf("-1\n");
			else 
				printf("%d\n",abs(d[b]-d[c])-1);	
		}
	}
	return 0;
} 
