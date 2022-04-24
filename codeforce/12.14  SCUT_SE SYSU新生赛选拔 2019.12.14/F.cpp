#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct node
{
	int x;
	int y;
};
node node_xx1[7],v[5];
double k[5],dis1,dis2;
double cosc(int x1,int yy1,int x2,int y2)
{
	return (x1*x2+yy1*y2)/(sqrt(x1*x1+yy1*yy1)*sqrt(x2*x2+y2*y2));
}
double wabs(double a)
{
	if(a<0)return -1*a;
	return a;
}
int main()
{
	int n;
	int xx1,yy1,x2,y2;
	scanf("%d",&n);
	while(n--)
	{
		for(int i=1;i<=5;++i)
			scanf("%d%d",&node_xx1[i].x,&node_xx1[i].y);
		dis1=sqrt( (node_xx1[1].x-node_xx1[3].x)*(node_xx1[1].x-node_xx1[3].x)+(node_xx1[1].y-node_xx1[3].y)*(node_xx1[1].y-node_xx1[3].y));
		dis2=sqrt( (node_xx1[1].x-node_xx1[4].x)*(node_xx1[1].x-node_xx1[4].x)+(node_xx1[1].y-node_xx1[4].y)*(node_xx1[1].y-node_xx1[4].y));
		if(dis1>dis2)
		{
			xx1=node_xx1[3].x-node_xx1[1].x;
			yy1=node_xx1[3].y-node_xx1[1].y;
		}
		else 
		{
			xx1=node_xx1[4].x-node_xx1[1].x;
			yy1=node_xx1[4].y-node_xx1[1].y;
		}
		dis1=sqrt( (node_xx1[2].x-node_xx1[3].x)*(node_xx1[2].x-node_xx1[3].x)+(node_xx1[2].y-node_xx1[3].y)*(node_xx1[2].y-node_xx1[3].y));
		dis2=sqrt( (node_xx1[2].x-node_xx1[4].x)*(node_xx1[2].x-node_xx1[4].x)+(node_xx1[2].y-node_xx1[4].y)*(node_xx1[2].y-node_xx1[4].y));
		if(dis1>dis2)
		{
			x2=node_xx1[3].x-node_xx1[2].x;
			y2=node_xx1[3].y-node_xx1[2].y;
		}
		else 
		{
			x2=node_xx1[4].x-node_xx1[2].x;
			y2=node_xx1[4].y-node_xx1[2].y;
		}
		int x3=node_xx1[5].x;
		int y3=node_xx1[5].y;
		double c1,c2,c3,sin2,sin3; 
		c1=cosc(xx1,yy1,x2,y2);
		c2=cosc(xx1,yy1,x3,y3);
		c3=cosc(x2,y2,x3,y3);
		sin2=sqrt(1-c2*c2);
		sin3=sqrt(1-c3*c3);
		if(wabs(c2*c3-sin2*sin3-c1)<=1e-6)
		printf("Yes\n");
		else printf("No\n");
	}
	return 0;
}
 
