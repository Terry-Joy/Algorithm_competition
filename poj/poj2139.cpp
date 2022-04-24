#include<cstdio>
#include<cstring>
#include<iostream>
#include<cmath>
using namespace std;
const int maxn=1<<29; 
int dis[310][310],b[310],n,m,x;
int main()
{
	while(scanf("%d%d",&n,&m)!=EOF)
	{
		for(int i=0;i<310;++i)
		{
			for(int j=0;j<310;++j)
				dis[i][j]=maxn;
			dis[i][i]=0;
		}	
		while(m--)
		{
			scanf("%d",&x);
			for(int i=0;i<x;++i)
				scanf("%d",&b[i]);
			for(int i=0;i<x;++i)
				for(int j=i+1;j<x;++j)
					dis[b[i]][b[j]]=dis[b[j]][b[i]]=1;	
		}
		for(int k=1;k<=n;++k)
			for(int i=1;i<=n;++i)
				for(int j=1;j<=n;++j)
		dis[i][j]=min(dis[i][j],dis[i][k]+dis[k][j]);
		int mins=maxn;
		for(int i=1;i<=n;++i)
		{
			int max1=0;
			for(int j=1;j<=n;++j)
				max1+=dis[i][j];
			mins=min(mins,100*max1/(n-1));
		}
		printf("%d",mins);
	}
	return 0;
} 
