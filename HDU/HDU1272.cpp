#include<iostream>
#include<cstring>
using namespace std;
bool vis[100010];
int main()
{
    int edge=0,ver=0,flag=0,a=0,b=0;
    memset(vis,0,sizeof(vis));
    while(~scanf("%d%d",&a,&b)&&(a!=-1&&b!=-1))
    {
       if(!a&&!b)
       {
          if(!flag)          //空树
          {
             puts("Yes");
             continue; 
          }
          if(edge==ver-1)
             puts("Yes");
          else
             puts("No");
          edge=0,ver=0,flag=0;
          memset(vis,0,sizeof(vis));
          continue; 
       } 
       flag=1;
       if(!vis[a])ver++;    //点数
       if(!vis[b])ver++;
       vis[a]=vis[b]=1;
       edge++;              //边数
    } 
    return 0;
}
