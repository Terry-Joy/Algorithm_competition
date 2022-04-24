//dcc[i]保存编号为i的v-DCC中的所有结点
int vc[maxn],nc[maxn],hc[maxn],tc,new_id[maxn];
int dfn[maxn],low[maxn],stack[maxn],tot,num,root,top,cnt;
bool cut[SIZE];
vector<int>dcc[maxn];
void add_c(int x,int y)//v-DCC缩点
{
    vc[++tc]=y,nc[tc]=hc[x],hc[x]=tc;
}
void tarjan(int x)
{
   dfn[x]=low[x]=++num;
   stack[++top]=x;
   if(x==root&&head[x]==0)  //孤立点
   {
      dcc[++cnt].push_back(x);
      return; 
   } 
   int flag=0;
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
              if(x!=root||flag>1)cut[x]=1;  //是割点
              cnt++;
              int z;
              do{ 
                z=stack[top--];
                dcc[cnt].push_back(z);      //维护一个栈来存储v-DCC
              }while(z!=y)
              dcc[cnt].push_back(x);
           } 
        } 
        else low[x]=min(low[x],dfn[y]);
   }
}
int main()
{
   tot=1;
   //add()加边
   for(int i=1;i<=n;++i)
      if(!dfn[i])root=i,tarjan(i); 
   /*for(int i=1;i<=cnt;++i)
    {
       printf("v-DCC #%d",i)
          for(int j=0;j<dcc[i].size();++j)
             printf(" %d",dcc[i][j]);
       puts(""); 
    }*/
    //给每一个割点一个新的编号(从cnt+1开始)
    num=cnt;
    for(int i=1;i<=n;++i)
        if(cut[i])new_id[i]=++num;
    tc=1;//建新图，从每个v-DCC到它所包含的所有割点连边
    for(int i=1;i<=cnt;++i)
        for(int j=0;j<=dcc[i].size();++j)
        {
           int x=dcc[i][j];
           if(cut[x])
           {
              add_c(i,new_id[x]);
              add_c(new_id[x],i); 
           } 
           else c[x]=i;
        }
    printf("缩点之后的森林，点数 %d,边数 %d\n",num,tc/2);
    printf("编号 1~%d 的为原图的v-dcc,编号>%d的为原图的割点\n",cnt,cnt);
    for(int i=2;i<tc;i+=2)
        printf("%d %d\n",vc[i^1],vc[i]);
}
