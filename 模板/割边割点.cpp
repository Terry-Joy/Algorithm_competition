const int size=1e6+10;
int head[size],ver[size<<1],nex1[size<<1];
int dfn[size],low[size],n,m,num;
bool bridge[size<<2];
int tot=1;
void add(int x,int y)
{
	ver[++tot]=y,next1[tot]=head[x],head[x]=tot;
 } 
void tarjan(int x,int in_edge)
{
	dfn[x]=low[x]=++num;                //low表示子节点与和通过一条不在搜索树上的边到达子树的节点的最小值
	for(int i=head[x];i;i=next1[i])
	{
	 	int y=ver[i];
		if(!dfn[y])
		{
 			tarjan(y,i);
			low[x]=min(low[x],low[y]);  //搜索树上x是y的父亲节点
			if(dfn[x]<low[y])           //搜索树上的dfn[x]<low[y]时满足割边
			 	bridge[i]=bridge[i^1]=1;
		}
		else if(i!=(in_edge^1))         //不再算一次反向边但是计算重边
			low[x]=min(low[x],dfn[y]);  //不是搜索树上父子节点
	}
}
int main(){
 	for(int i=1;i<=n;++i)
		if(!dfn[i])tarjan(i,0);
	for(int i=2;i<tot;i+=2)
 		if(bridge[i])
			printf("%d %d\n",ver[i^1],ver[i]);
}

//割点 tot从1还是2开始没关系
bool cnt[SIZE];
int root //其他变量同上,x为根时要满足2次以上
void tarjan(int x)
{
   dfn[x]=low[x]=++num;
   int flag=0;          //标记dfn[x]<=low[y]的次数
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
         if(dfn[x]<=low[y])
         {
            flag++;
            if(x!=root||flag>1)cnt[x]=1;        //标记为割点 
         } 
      } 
      else low[x]=min(low[x],dfn[y]);
   } 
}
int main()
{
   tot=1;
   if(x==y)continue;        //add edge
   for(int i=1;i<=n;++i)
        if(!dfn[i])root=i,tarjan(i);
}


