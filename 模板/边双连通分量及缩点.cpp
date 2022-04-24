//边双连通分量 把所有割边删去后 剩下的联通块就是一个边双连通分量
tot=1;//c[i]表示结点i所属的e-dcc的编号
int dfn[SIZE],low[SIZE],c[SIZE],dcc;
int hc[SIZE],vc[SIZE<<1],nc[SIZE<<1],tc;//缩点把树或者森林存进新的邻接表
bool bridge[SIZE<<1];
void add_c(int x,int y)             //缩点新的add
{
   vc[++tc]=y,nc[tc]=hc[x],hc[x]=tc; 
}
void tarjan(int x,int in_edge)
{
   dfn[x]=low[x]=++num;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!dfn[y])
      {
         tarjan(y,i);
         low[x]=min(low[x],low[y]);
         if(dfn[x]<low[y])
             bridge[i]=bridge[i^1]=1;
      } 
      else if(i!=(in_edge^1))
          low[x]=min(low[x],dfn[y]);
   } 
}
void dfs(int x)
{
   c[x]=dcc;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(c[y]||bridge[i])continue;
      dfs(y); 
   } 
}
int main()
{
    //求割边
    tot=1;
    for(int i=1;i<=n;++i)
       if(!dfn[i])tarjan(i,0); 
    for(int i=1;i<=n;++i)
        if(!c[i])
        {
           ++dcc;
           dfs(i); 
        }
    tc=1;
    for(int i=2;i<=tot;++i)
    {
       int x=ver[i^1],y=ver[i];     //已经加了2条
       if(c[x]==c[y])continue;
       add_c(c[x],c[y]); 
    }
    printf("缩点后的森林，点数%d,边数%d(可能有重边)\n",dcc,tc/2);
    for(int i=2;i<tot;i+=2)
        printf("%d %d\n",vc[i^1],vc[i]);
}
