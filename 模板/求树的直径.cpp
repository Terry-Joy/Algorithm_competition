//树形DP d[x]表示从节点x出发走向以x为根的所能到达的最远距离
//先更新直径，然后再更新d[x]
//缺点难以记录路径 但代码量短
void dp(int x)
{
   v[x]=1;
   for(int i=head[x];i;i=next[i])
   {
      int y=ver[i];
      if(v[y])continue;
      dp(y);
      ans=max(ans,d[x]+d[y]+edge[i]);
      d[x]=max(d[x],d[y]+edge[i]);      //d[x]保留以yj为根的子树，j<i，所以只更新i即可 
   } 
}

//两次dfs，可以第二次的时候记录路径
void dfs(int x)
{
    for(int i=head[x];i;i=next[i])
    { 
        int y=ver[i];
        if(fa[x]!=y)
        {
        	fa[y]=x;
            d[y]=d[x]+edge[i];
            dfs(y);
        }
    }
}
int main()
{
   memset(vis,0,sizeof(vis));
   memset(d,0x3f,sizeof(d));
   cin>>n>>m;
   for(int i=1;i<=m;++i)
   {
      int x,y,z;
      add(x,y,z);
      add(y,x,z); 
   } 
   d[1]=0;
   dfs(1);        //先找第一个端点
   int maxx=-1000,INF=0x3f,start=0;
   for(int i=1;i<=n;++i)
   {
      if(d[i]>maxx&&d[i]!=INF)  //能到达
         maxx=d[i];
         start=i; 
   }
   memset(vis,0,sizeof(vis));
   memset(d,0x3f,sizeof(d));
   d[start]=0;
   dfs(start);
   maxx=-1000;
   for(int i=1;i<=n;++i)
   {
      if(d[i]>maxx&&d[i]!=INF)
      {
         maxx=d[i];
         end=i; 
      } 
   }
}

//��??bfs 
int bfs(int s)
{
	int i,x,y;
	memset(d,0x3f,sizeof(d));
	q.push(s); d[s]=pre[s]=0;
	while(q.size())
	{
		x=q.front(); q.pop();
		for(i=head[x];i;i=next[i])
			if(d[ver[i]]==0x3f3f3f3f)		//ʡȥһ��v���� 
				d[ver[i]]=d[x]+edge[i],pre[ver[i]]=i,q.push(ver[i]);
	}
	for(x=y=1;x<=n;x++) if(d[x]>d[y]) y=x;
	return y;				//y��ʾ�˵� 
}

int get()
{
	p=bfs(1);
	p=bfs(p);
	return d[p];
}
