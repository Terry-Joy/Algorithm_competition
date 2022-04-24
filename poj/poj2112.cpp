#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
int match[35][20],map[235][235],line[35],k,c,m,i,j,f;
bool vis[35];
const int INF=0x3f3f3f3f;
bool dfs(int x,int li)
{
   for(int i=1;i<=k;++i)
   {
      if(!vis[i]&&map[x][i]<=li)
      {
         vis[i]=1;
         if(line[i]<m)
         {
            match[i][++line[i]]=x;
            return true; 
         } 
         else
         for(int j=1;j<=line[i];++j)
         {
            if(dfs(match[i][j],li))
            {
                match[i][j]=x; 
                return true;
            }
         }
      } 
   } 
   return false;
}
bool check(int x)
{
   memset(match,0,sizeof(match));//记得每次check都要更新
   memset(line,0,sizeof(line));
   for(int i=k+1;i<=k+c;++i)
   {
      memset(vis,0,sizeof(vis));
      if(!dfs(i,x))return false; 
   } 
   return true;
}
int main()
{
    scanf("%d%d%d",&k,&c,&m); 
    for(i=1;i<=k+c;++i)
        for(j=1;j<=k+c;++j) 
        { 
            scanf("%d",&map[ i][j]);
            if(i!=j&&map[i][j]==0)//不在同一点的0实际上是无穷大
                map[i][j]=INF;
        }
    int l=INF,r=-1,mid;
    for(f=1;f<=k+c;++f)
         for(i=1;i<=k+c;++i)
            for(j=1;j<=k+c;++j)
            { 
                map[i][j]=min(map[i][j],map[i][f]+map[f][j]);//floyd
                l=min(l,map[i][j]);r=max(r,map[i][j]);
            }
    r++;
    while(l<r)
    {
       mid=l+r>>1;
       if(check(mid))
          r=mid;
       else 
          l=mid+1; 
    }
    printf("%d\n",r);
    return 0;
}
