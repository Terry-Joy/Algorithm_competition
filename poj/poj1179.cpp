#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
char b[100];
int	fm[200][200],fi[200][200],val[100];
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;++i)
	 getchar(),scanf("%c%d",&b[i],&val[i]),b[i+n]=b[i],val[i+n]=val[i]; 
	memset(fm,0xcf,sizeof(fm));
	memset(fi,0x3f,sizeof(fi));
	for(int i=1;i<=2*n;++i)fm[i][i]=fi[i][i]=val[i];
	for(int len=2;len<=n;++len)		//阶段 
	{	
		for(int i=1;i+len-1<=2*n;++i)		//状态 
		{
			for(int k=i;k<i+len-1;++k)//决策 
			{
				if(b[k+1]=='t')
				{
					fm[i][i+len-1]=max(fm[i][i+len-1],fm[i][k]+fm[k+1][i+len-1]);
					fi[i][i+len-1]=min(fi[i][i+len-1],fi[i][k]+fi[k+1][i+len-1]);
				} 
				else//乘法时最大最小值有不同可能 
				{	//考虑负负相乘 正负相乘等可能 
					fm[i][i+len-1]=max(fm[i][i+len-1],fm[i][k]*fm[k+1][i+len-1]);
					fm[i][i+len-1]=max(fm[i][i+len-1],fi[i][k]*fi[k+1][i+len-1]);
					fm[i][i+len-1]=max(fm[i][i+len-1],fm[i][k]*fi[k+1][i+len-1]);
					fm[i][i+len-1]=max(fm[i][i+len-1],fi[i][k]*fm[k+1][i+len-1]);
					fi[i][i+len-1]=min(fi[i][i+len-1],fi[i][k]*fi[k+1][i+len-1]);
					fi[i][i+len-1]=min(fi[i][i+len-1],fi[i][k]*fm[k+1][i+len-1]);
					fi[i][i+len-1]=min(fi[i][i+len-1],fm[i][k]*fi[k+1][i+len-1]);
					fi[i][i+len-1]=min(fi[i][i+len-1],fi[i][k]*fm[k+1][i+len-1]);
				}
				
			}
		}
	}
	int maxx = -0x7fffffff;	
	for(int i = 1; i <= n; i++)
	maxx = max(maxx,fm[i][i+n-1]);
	printf("%d\n",maxx);
	for(int i = 1; i <= n; i++)
		if(fm[i][i+n-1] == maxx)
		printf("%d ",i);
	return 0;
}
