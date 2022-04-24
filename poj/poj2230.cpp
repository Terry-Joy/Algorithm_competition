#include<iostream>
#include<cstdio>
using namespace std;
const int N=1e4+10,M=1e5+10;
int head[N],ver[M],next1[M],edge[M],tot,stack[M],ans[M],top,t,n,m;
bool vis[M];
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
        while(i&&vis[i])i=next1[i];
        if(i)
        {
            stack[++top]=ver[i];
            vis[i]=1;
            head[x]=next1[i]; 
        } 
        else
        {
            top--;
            ans[++t]=x; 
        }
    }
}
int main()
{
    tot=1;
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        int a,b;
        scanf("%d%d",&a,&b);
        add(a,b);
        add(b,a); 
    } 
    euler();
    for(int i=t;i;i--)
        printf("%d\n",ans[i]);
    return 0;
}
