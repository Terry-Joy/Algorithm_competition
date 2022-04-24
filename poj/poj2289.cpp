#include<iostream>
#include<cstring>
#include<cstdio>

using namespace std;
const int N=1e3+10,M=1e6+10;
int head[N],ver[M],next1[M],tot,n,m,i,j;
char s[20];
int len[1010],match[1010][1010];    //len表示多重匹配的那一边的节点的匹配数 y[i][j]=x表示i匹配节点的集合中第j个匹配的是x
bool vis[N];
void add(int x,int y)
{
    ver[++tot]=y,next1[tot]=head[x],head[x]=tot; 
}
bool dfs(int x,int li)
{
    for(int i=head[x];i;i=next1[i])
    {
        int y=ver[i];
        if(!vis[y])
        {
            vis[y]=1; 
            if(len[y]<li)//假如没超过匹配次数
            {
                match[y][++len[y]]=x;
                return true; 
            }

            for(int i=1;i<=len[y];++i)//如果超过了递归当前匹配的k个节点 看能否找到增广路
            {
                if(dfs(match[y][i],li))
                {
                    match[y][i]=x;
                    return true; 
                } 
            }
        }
    } 
    return false;
}
bool check(int x)
{
    for(i=0;i<=m;++i)
        len[i]=0;
    for(i=1;i<=n;++i)
    {
        for(j=0;j<m;++j)
            vis[j]=0;
        if(!dfs(i,x))return false;
    }
    return true;
}
int main()
{
    while(~scanf("%d%d",&n,&m))
    {
        if(n==0&&m==0)break;
        tot=0;
        for(i=1;i<=n;++i)
            head[i]=0;
        for(i=1;i<=n;++i)
        {
            scanf("%s",s);
            int a;
            char c;
            while(1)
            {
                scanf("%d%c",&a,&c);
                add(i,a);
                if(c=='\n')break;
            }
        }
        int l=0,r=n+1,mid=0;
        while(l<r)
        {
            int mid=l+r>>1;
            if(check(mid))
                r=mid;    
            else
                l=mid+1;
        }
        printf("%d\n",r);
    }   
    return 0;
}
