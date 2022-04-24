#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int v[510][510],x[250010],y[250010],N,M;
int n,m,deg[510],p=0;
bool check(int mid)
{
 	while(p)
	 {
	 	deg[x[p]]--;
	 	deg[y[p]]--;
	 	v[x[p]][y[p]]=v[y[p]][x[p]]=0;
	 	p--;
	  } 
 	int M=m;					//M来记录当前连上的边 
 	while(M<N)					//迭代 
 	{
 		bool change=0;
 		for(int i=1;i<=n;++i)
 			for(int j=i+1;j<=n;++j)
 			{
 				if(!v[i][j]&&deg[i]+deg[j]>=mid)
 				{
 					deg[i]++;
 					deg[j]++;
 					v[i][j]=v[j][i]=1;
 					x[++p]=i;
 					y[p]=j;
 					M++;
 					change=1;
				 }
			 }
			 if(!change)
				 	break;
	 }
	 return M==N;
}
int main()
{
    scanf("%d%d",&n,&m);
    N=n*(n-1)/2;
    for(int i=1;i<=m;++i)
    {
       int x,y;
       scanf("%d%d",&x,&y);
       deg[x]++;deg[y]++;
       v[x][y]=1; 
       v[y][x]=1;
   }
   
    int l=-1,r=2*(n-1);
    int mid;
    while(l<r)
    {
       mid=(l+r+1)>>1;
       if(check(mid)) 
          l=mid;
       else
           r=mid-1;
    }
     printf("%d\n",l);
     return 0;     
}
