#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int match[25][1010],g[1010][25],line[25],n,b,li[25];
bool vis[1010];

bool dfs(int x,int l,int r)
{
   for(int i=l;i<=r;++i)        //从左边每个点出发
   {
      int y=g[x][i];
      if(!vis[y])
      {
         vis[y]=1;
         if(line[y]<li[y])
         {
            match[y][++line[y]]=x;
            return true; 
         } 
         else 
         for(int j=1;j<=line[y];++j)
         {
            if(dfs(match[y][j],l,r))
            {
               match[y][j]=x;
               return true; 
            } 
         }
      } 
   } 
   return false;
}

bool check2(int l,int r)
{
   memset(line,0,sizeof(line));
   for(int i=1;i<=n;++i)
   {
      memset(vis,0,sizeof(vis));
      if(!dfs(i,l,r))return false;//看看多重匹配能否匹配成功 
   } 
   return true;
}

bool check(int len)
{
    int l,r;
    for(int i=1;i<=b-len+1;++i)//枚举区间
    {
        l=i,r=i+len-1;
        if(check2(l,r))
            return true;
    } 
    return false;
}

int main()
{
   scanf("%d%d",&n,&b);
   for(int i=1;i<=n;++i) 
      for(int j=1;j<=b;++j)
          scanf("%d",&g[i][j]);//第i头牛的第j个rank是哪个仓库
   for(int i=1;i<=b;++i)
       scanf("%d",&li[i]);
   int l=1,r=b+1,mid;
   while(l<r)
   {
      int mid=l+r>>1;
      if(check(mid))
         r=mid;
      else l=mid+1; 
   }
   printf("%d\n",r);
   return 0; 
}
