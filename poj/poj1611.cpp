#include<iostream>
#include<cstdio>
using namespace std;
int fa[30010],n,m,k,a[30010];
int find(int x)
{
   if(x==fa[x])return x;
   return fa[x]=find(fa[x]); 
}
void merge(int x,int y)
{
	int q=find(x),w=find(y);
	if(x==y)return;
	if(a[x]<a[y])
	{
		fa[x]=y;
		a[y]+=a[x];	
	}
	else{
		fa[y]=x;
		a[x]+=y;
	}
}
int main()
{ 
    while(~scanf("%d%d",&n,&m)&&(n|m))
    {   
        for(int i=0;i<n;++i)
        {
        	 fa[i]=i;
        	 a[i]=1;
		}
        for(int i=1;i<=m;++i)
        {
            int x,y;
			scanf("%d",&k);
            scanf("%d",&x);
            for(int i=1;i<k;++i)
            {
				scanf("%d",&y);
				merge(x,y);
			} 
        }
        printf("%d\n",a[find(0)]);
    }
    return 0;
}
