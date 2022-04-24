#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=110;
int match[N],map[N][N],ans,a[N],b[N];
bool vis[N];
int i,j,n;
bool  dfs(int x)
{
    for(int i=1;i<=n;++i)
    {    
        if(!vis[i]&&map[x][i]==1)
        {
            vis[i]=1; 
            if(!match[i]||dfs(match[i]))
            {
                match[i]=x;return x; 
            }
        }
    } 
    return false;
}
int main()
{
    while(~scanf("%d",&n))
    {
        memset(match,0,sizeof(match));
        ans=0;
        for(i=1;i<=n;++i)
            for(j=1;j<=n;++j)
                scanf("%d",&map[i][j]);
        for(i=1;i<=n;++i)
        {
           memset(vis,0,sizeof(vis)); 
            if(dfs(i))ans++; 
        }
        if(ans<n)
        {
            puts("-1");
            continue; 
        }
        int k=0;
        for(i=1;i<=n;++i)
        {
            if(match[i]!=i)
            {
                for(j=1;j<=n;++j)
                {
                    if(i==match[j])//挨个匹配  
                    { 
                        a[++k]=i;
                        b[k]=j;
                        swap(match[i],match[j]);
                        break; 
                    }
                }
            } 
        }
        printf("%d\n",k);
        for(i=1;i<=k;++i)
            printf("C %d %d\n",a[i],b[i]); 
    }
    return 0;
}
