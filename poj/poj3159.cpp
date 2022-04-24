#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
typedef pair<int,int>P;
priority_queue<P,vector<P>,greater<P> >q;
const int N=4e4+10,M=150010;
int head[N],next1[M],edge[M],ver[M],tot,v[N],d[N],n,m;
void add(int x,int y,int z){ 
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dijkstra(){ 
    memset(v,0,sizeof(v));
    memset(d,0x3f,sizeof(d));
    d[1]=0;
    q.push(make_pair(d[1],1));
    while(q.size()){ 
        int x=q.top().second;q.pop();
        if(v[x])continue;
        v[x]=1;
        for(int i=head[x];i;i=next1[i])
        {
            int y=ver[i],z=edge[i];
            if(d[y]>d[x]+z)
            {
               d[y]=d[x]+z;
               q.push(make_pair(d[y],y)); 
            }
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
       int a,b,c;
      scanf("%d%d%d",&a,&b,&c);
     add(a,b,c); 
    }
    dijkstra();
    printf("%d",d[n]);
    return 0;
}
