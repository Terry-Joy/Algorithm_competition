//非递归模拟系统栈求欧拉回路 o(N+M)
const int N,M;
int head[N],ver[M],edge[M],next1[M],tot;
int stack[M],ans[M]//欧拉dfs层数是o(M),防爆栈,模拟系统栈和答案栈
bool vis[M];
int n,m,top,t;
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void euler()
{
   stack[++top]=1;
   while(top>0)
   {
      int x=stack[top],i=head[x];
      while(i&&vis[i])i=next1[i];       //找到一条未访问的边
      if(i)//沿着这条边模拟递归，标记该边，更改表头
      {
         stack[++top]=ver[i];
         vis[i^1]=vis[i]=1;
         head[x]=next1[i];
      }
      else{//与x连的边都跑过了，就模拟回溯记录答案， 
          top--;
          ans[++t]=x;
      }
   } 
}
int main()
{
   tot=1;
  //加边
   euler();
   for(int i=t;i;--i)printf("%d\n",ans[i]); 
}
