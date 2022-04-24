#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#include<queue>
#include<cmath>
#include<stack>
#include<vector>
#include<string>
using namespace std;
const int N=1e5+10,M=2e5+100,INF=0x7fffffff;
string name[3]={"me","Gon","Killua"};
int head[N],next1[M],ver[M],edge[M],tot=0,d[N][3],vis[N][3],n,m;
struct Node
{
   int val,v,col;
   bool operator<(const Node&a)const
   {
      return val>a.val;
   }
   Node(int m_val=0,int m_v=0,int m_col=0):val(m_val),v(m_v),col(m_col){} 
};
void add(int x,int y,int z)
{
   ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot; 
}
priority_queue<Node>q;
void dijkstra()
{
    for(int i=1;i<=n;++i)
    	for(int j=0;j<3;++j)
    	 	vis[i][j]=0,d[i][j]=INF;
    d[1][0]=0;
    q.push(Node(d[1][0],1,0));
    while(q.size())
    {
       Node x=q.top();q.pop();
       if(vis[x.v][x.col])continue;
       vis[x.v][x.col]=1;
	   if(x.v==n)continue;					//到达终点要返回 
       for(int i=head[x.v];i;i=next1[i])
       {
          int y=ver[i],z=edge[i];
          if(!vis[y][(x.col+1)%3]&&d[y][(x.col+1)%3]>x.val+z)
          {
             d[y][(x.col+1)%3]=x.val+z;
             q.push(Node(d[y][(x.col+1)%3],y,(x.col+1)%3)); 
          } 
       } 
    }
}
int main()
{
   scanf("%d%d",&n,&m);
   for(int i=1;i<=m;++i)
   {
      int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
      add(a,b,c);
      add(b,a,c); 
   }
   dijkstra();
   for(int i=0;i<2;++i)
        for(int j=i+1;j<3;++j)
            if(d[n][i]>d[n][j])
            { 
                swap(d[n][i],d[n][j]);
                swap(name[i],name[j]);
            }   
   for(int i=0;i<3;++i)
       cout<<name[i]<<"\n";
   return 0; 
}
