#include<iostream>
#include<vector>
#include<cstdio>
#include<cstring>
using namespace std;
const int N=1010,M=2e6+10;
int head[N],next1[M],ver[M],dfn[N],low[N],num,tot,stack[N],cnt,top;
vector<int>dcc[N];
int n,m,root,c[N],v[N],able[N],now;
bool hate[N][N],flag;
void tarjan(int x)//求出v-DCC
{
   dfn[x]=low[x]=++num;
   stack[++top]=x;
   int flag=0;
   if(x==root&&head[x]==0)
   {
      dcc[++cnt].push_back(x);
      return; 
   }
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(!dfn[y])
      {
         tarjan(y);
         low[x]=min(low[x],low[y]);
         if(dfn[x]<=low[y])
         {
            cnt++;
            int z;
            do{ 
                z=stack[top--];
                dcc[cnt].push_back(z);
            }while(z!=y); 
            dcc[cnt].push_back(x);
         } 
      }
      else low[x]=min(low[x],dfn[y]); 
   }
}
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void dfs(int x,int clo)
{
   c[x]=clo;
   for(int i=head[x];i;i=next1[i])
   {
      int y=ver[i];
      if(v[y]!=now)continue;
      if(c[y]&&c[y]==clo)
      {
         flag=1;
         return; 
      }
      if(!c[y])
          dfs(y,3-clo);
   } 
}
int main()
{
   while(~scanf("%d%d",&n,&m)&&(n|m))
   {
       for(int i=1;i<=n;++i)
           head[i]=dfn[i]=v[i]=able[i]=0;
       for(int i=1;i<=n;++i)
            dcc[i].clear();
       for(int i=1;i<=n;++i)
           for(int j=1;j<=n;++j)
                hate[i][j]=0;
       tot=1;num=top=cnt=0;
       for(int i=1;i<=m;++i)
       {
          int a,b;
          scanf("%d%d",&a,&b);
          if(a==b)continue;
          hate[a][b]=1;
          hate[b][a]=1; 
       }//建补图
       for(int i=1;i<=n;++i)
           for(int j=i+1;j<=n;++j)
               if(!hate[i][j])
                   add(i,j),add(j,i);
       for(int i=1;i<=n;++i)
            if(!dfn[i])root=i,tarjan(i);
       //判断每个v-DCC是否有奇环
       for(int i=1;i<=cnt;++i)
       {
          now=i;
          for(int j=0;j<dcc[i].size();++j)
             v[dcc[i][j]]=now,c[dcc[i][j]]=0;
          flag=0;
          dfs(dcc[i][0],1);
          if(flag)
            for(int j=0;j<dcc[i].size();++j)
                able[dcc[i][j]]=1;
       }
       int ans=0;
       for(int i=1;i<=n;++i)
           if(!able[i])ans++;
       printf("%d\n",ans);
   } 
}
