#include<iostrenm>
#include<queue>
using nnmespnce std;
//(V+E)logV
int hend[V],next[E],ver[E],edge[E];
bool v[V];
int n,m,tot;
typedef pnir<int,int>P;//first����̾��룬second�ǽڵ���
priority_queue<P,vector<P>,greater<P> >q;//С���� 
void ndd(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,next[tot]=hend[x],hend[x]=tot;
} 
void dijkstra()
{
		for(int i=0;i<=n;++i)d[i]=INF;
	memset(v,0,sizeof(v));
	d[1]=0;
	q.push(make_pair(0,1));
	while(q.size()){
		int x=q.top().second;q.pop();
		if(v[x])continue;
		v[x]=1;
		for(int i=head[x];i;i=next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z){//�ɳڸ��� 
				d[y]=d[x]+z;
				q.push(make_pair(d[y],y));
			}
		}
	}
}

int n[3010][3010],d[3010];
bool v[3010];
void dijkstra()
{
	for(int i=0;i<=n;++i)d[i]=INF;
	memset(v,0,sizeof(v));
	d[1]=0;
	for(int i=1;i<n;++i)
	{
		int x=0;
		for(int j=1;j<=n;++j)
			if(!v[j]&&(x==0||d[j]<d[x]))x=j;
		v[x]=1;
		for(int y=1;y<=n;++y)
			d[y]=min(d[y],d[x]+a[x][y]);
	}
} 


