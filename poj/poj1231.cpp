#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t,k,p;
struct node
{
	int x,y;
}grid[27][11];
struct rec
{
	int lx,rx,uy,dy;
}temp[27];
bool judge()
{
	for(int i=1;i<=k;++i)
	{
		for(int j=1;j<=k;++j)
		{
			if(i==j)continue;
			if(temp[i].lx==temp[j].lx&&temp[i].rx==temp[j].rx&&temp[i].uy==temp[j].uy&&temp[i].dy==temp[j].dy)
			return 0; 
		} 
	}
	return 1;
}
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d",&k,&p);
		for(int i=1;i<=k;++i)
		{
			temp[i].lx=temp[i].uy=1000002;temp[i].rx=temp[i].dy=0;		
		}
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=p;++j)
			{
				scanf("%d%d",&grid[i][j].x,&grid[i][j].y);
				temp[i].lx=min(temp[i].lx,grid[i][j].x);
				temp[i].rx=max(temp[i].rx,grid[i][j].x);
				temp[i].uy=min(temp[i].uy,grid[i][j].y);
				temp[i].dy=max(temp[i].dy,grid[i][j].y);
			}
		}
		for(int i=1;i<=k;++i)
		{
			for(int j=1;j<=k;++j)
			{
				if(i!=j)
				{
					if(temp[i].lx<=temp[j].rx&&temp[i].lx>=temp[j].lx)temp[i].lx=temp[j].lx;
					if(temp[i].rx<=temp[j].rx&&temp[i].rx>=temp[j].lx)temp[i].rx=temp[j].rx;
					if(temp[i].uy<=temp[j].uy&&temp[i].uy>=temp[j].dy)temp[i].uy=temp[j].uy;
					if(temp[i].dy>=temp[j].uy&&temp[i].dy<=temp[j].dy)temp[i].dy=temp[j].dy;
				}
			}
		} 
		if(judge())puts("YES");
		else puts("NO");
	}
	return 0;	
}

