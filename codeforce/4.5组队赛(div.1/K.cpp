#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
const int N=1e5+10,M=2e5+10;
int head[N],ver[M],edge[M],next1[M],tot,ans1[N],ans2[N],ans3[N],ans,dfn[N],times;
bool used[N];
void add(int x,int y)
{
   ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
void answer(int x,int y,int z)
{
   ans1[++ans]=x,ans2[ans]=y,ans3[ans]=z; 
}
void dfs(int now,int fa)
{
   dfn[now]=++times;
   vector<int>son;                      //存储树边上可用的子边，父边，返祖边
   for(int i=head[now];i;i=next1[i])
   {    
       int y=ver[i];
       if(y==fa)continue;
       if(!dfn[y])                      //往下第一次访问
       { 
           dfs(y,now);
           if(!used[y])               //观察now到y的边是否被y用来匹配了
               son.push_back(y),used[y]=1;
       }
       else 
          if(dfn[y]<dfn[now])
            son.push_back(y);
       
   } 
   int num=son.size();
   if(num&1)
   {
      if(fa)
      {
         answer(fa,now,son[num-1]);       //奇数的话把自己的父边拿出来与任意一条儿子匹配
      } 
      used[now]=1;
   }
    for(int i=0;i<num-1;i+=2)
      answer(son[i],now,son[i+1]);           //偶数的时候随便两两匹配 
}
int main()
{   
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
       int a,b;
       scanf("%d%d",&a,&b);
       add(a,b);
       add(b,a); 
    }
    for(int i=1;i<=n;++i)
        if(!dfn[i])
            dfs(i,0);
    printf("%d\n",ans);
    for(int i=1;i<=ans;++i)
    {
        printf("%d %d %d\n",ans1[i],ans2[i],ans3[i]); 
    }
    return 0;
}
