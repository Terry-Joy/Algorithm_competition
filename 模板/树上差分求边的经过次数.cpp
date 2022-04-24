//树上差分求树边被非树边覆盖次数 
//倍增可加log优化 
#include<iostream>
#include<cstring>
#include<cstdio>
const int N=3e5+100,M=6e5+100;
using namespace std;
int head[N],ver[M],edge[M],next1[M],tot,d[N],dis[N],f[N][25],num[M],temp[N],cnt=0;
int n,m;
struct Node
{
   int x,y,lca,len;
}ed[N];
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int now,int fa)
{
   num[++cnt]=now;						//记录深入的时候的dfs序，方便后面处理 
   f[now][0]=fa;
   d[now]=d[fa]+1;
   for(int i=head[now];i;i=next1[i])
   {
      if(ver[i]!=fa)
      {
         dis[ver[i]]=dis[now]+edge[i];
         dfs(ver[i],now); 
      } 
   } 
}
int Lca(int x,int y)
{
    if(d[x]>d[y])swap(x,y);
    for(int i=20;i>=0;--i)
    {
       if(d[f[y][i]]>=d[x])
            y=f[y][i]; 
    }
    if(x==y)return x;
    for(int i=20;i>=0;--i)
    {
       if(f[x][i]!=f[y][i])
          x=f[x][i],y=f[y][i]; 
    }
    return f[x][0];
}
void init()
{
	for(int i=1;(1<<i)+1<=n;++i)
		for(int j=1;j<=n;++j)
			f[j][i]=f[f[j][i-1]][i-1];
}
bool check(int mid)
{
    int ans=0,cnt=0;
    memset(temp,0,sizeof(temp));
    for(int i=1;i<=m;++i)
    {
       if(ed[i].len>mid)
       {
          temp[ed[i].x]++,temp[ed[i].y]++,temp[ed[i].lca]-=2;
          ans=max(ans,ed[i].len-mid);//统计各路径覆盖树边的次数 
          cnt++; //(u,v)上u--,v++,lca(u,v)-=2 
       } 
    }
    if(cnt==0)
        return true;
    for(int i=n;i>=1;--i)temp[f[num[i]][0]]+=temp[num[i]];//dfs倒序累加temp值 
    for(int i=2;i<=n;++i)
    {
       if(temp[i]==cnt&&dis[i]-dis[f[i][0]]>=ans)//temp记录与父节点的边数经过几次 
          return true; //与路径次数相同则是所有路径覆盖边 
    }
    return false;
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<n;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
      add(b,a,c); 
   } 
   dis[1]=0;
   dfs(1,0);
   init();
   int sum=0;
   for(int i=1;i<=m;++i)
   {
        int x,y;
        scanf("%d%d",&ed[i].x,&ed[i].y);
        ed[i].lca=Lca(ed[i].x,ed[i].y);
        ed[i].len=dis[ed[i].x]+dis[ed[i].y]-2*dis[ed[i].lca];
        sum=max(sum,ed[i].len);
   }
   int l=0,r=sum+1;
   while(l<r)
   {
      int mid=(l+r)>>1;
      if(check(mid))
         r=mid;
      else l=mid+1; 
   }
   printf("%d\n",l);
   return 0;
}
