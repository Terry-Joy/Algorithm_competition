const int N=100010,M=1000010;
int head[N],ver[M],next[M],edge[M];
int n,m,tot;
bool v[N];
void add(int x,int y,int z){
	ver[++tot]=y,edge[tot]=z,next[tot]=head[x],head[x]=tot;
}
void spfa(){//1到其他点
	queue<int>q; 
	memset(d,0x3f,sizeof(d));
	memset(v,0,sizeof(v));	//判断是否在队列中 
	d[1]=0,v[1]=1;
	q.push(1);
	while(q.size())
	{
		int x=q.front(),q.pop();
		v[x]=0;
		for(int i=head[x];i;i=next[i]){
			int y=ver[i],z=edge[i];
			if(d[y]>d[x]+z)
			{
				d[y]=d[x]+z;
				if(!v[y])q.push(y),v[y]=1;
			}
		}
	}
}
