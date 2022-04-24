#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
#include<algorithm>
#include<stack>
#include<cmath>
using namespace std;
const int N=5010,M=5010;
int head[N],ver[M],next1[M],edge[M],tot,n,m,flag,v[N],a[M],b[M];
void add(int x,int y,int z)
{
    ver[++tot]=y,edge[tot]=z,next1[tot]=head[x],head[x]=tot;
}
void dfs(int x) 
{
    if(flag)return;
    v[x]=1;         //正在访问
    for(int i=head[x];i;i=next1[i])
    {
        int y=ver[i];
        if(!v[y])dfs(y);
        else if(v[y]==1)
        {
            flag=1;
            return; 
        } 
    }
    v[x]=2;     //dfs三种状态 2表示其后续节点已经被访问过了
}
int main()
{
    scanf("%d%d",&n,&m);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a[i],&b[i]);
        add(a[i],b[i],1); 
    }
    for(int i=1;i<=n;++i)
    { 
        if(!v[i])
            dfs(i);
    }
    if(!flag){ 
        cout<<1<<endl;
        for(int i=1;i<=m;++i)
            cout<<1<<" ";
        cout<<endl;
    }
    else
    {
        cout<<2<<endl;
        for(int i=1;i<=m;++i){
            if(a[i]<b[i])
                cout<<1<<" ";
            else 
                cout<<"2"<<" "; 
        }
        cout<<endl;
    }
    return 0; 
}
