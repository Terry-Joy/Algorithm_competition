#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
const int M=4e4+100;
const int INF=0x3f3f3f3f;
int head[210],ver[M],next1[M],edge[M],tot,a[210],v[210],d[210],cnt[210],vis[210],n,m;
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int v)//dfs连通块负环标记 
{
	vis[v]=1;
	for(int i=head[v];i;i=next1[i])
	{
		int y=ver[i];
		if(!vis[y])dfs(y);
	}
}
void spfa()
{ 
    memset(v,0,sizeof(v));
    memset(d,0x3f,sizeof(d));
    memset(cnt,0,sizeof(cnt));
    memset(vis,0,sizeof(vis));
    queue<int>q;
    d[1]=0,v[1]=1,cnt[1]=0;
    q.push(1);
    while(q.size()){ 
        int x=q.front();q.pop();
        v[x]=0;
        for(int i=head[x];i;i=next1[i]){ 
            int y=ver[i],z=edge[i];
            if(vis[y])continue;
            if(d[y]>d[x]+z)
            {
            	d[y]=d[x]+z;
				if(!v[y])
				{
					q.push(y);
					v[y]=1;
					cnt[y]++;
					if(cnt[y]>=n)dfs(y);
				} 
            }
        }
    }
}
int main()
{ 
    int t,f=1;
    scanf("%d",&t);
    while(t--)
    {
    	tot=0;//一定要初始化！！ 
        memset(head,0,sizeof(head));
   	 	scanf("%d",&n);
   		 for(int i=1;i<=n;++i)
    		{
       			scanf("%d",&a[i]); 
  	  		}
 			   scanf("%d",&m);
  	  for(int i=1;i<=m;++i)
  	  {
      	  int q,b;
      	 	scanf("%d%d",&q,&b);
        	int ed=(a[b]-a[q])*(a[b]-a[q])*(a[b]-a[q]);
        	add(q,b,ed);
   	 	}
    		int k,que;
   		 scanf("%d",&k);
   		 printf("Case %d:\n",f++);
			spfa();   
  		  while(k--)
			{ 
       			 scanf("%d",&que);
    			if(d[que]>=INF||d[que]<3||vis[que])	
      	  			printf("?\n");
    				else printf("%d\n",d[que]);
    		}
    }
    return 0;
}
