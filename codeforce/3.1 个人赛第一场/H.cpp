
#include<cstdio>
#include<iostream>
#include<algorithm>
#include<map>
#include<cstring>
#include <vector>
#include<queue>
const int maxn=200005;
using namespace std;
vector<char>mat[maxn];
int v[maxn];
int sx,sy,ex,ey;
int m,n,t;
int dirx[]= {-1,1,0,0};
int diry[]= {0,0,1,-1};
struct node
{
    int x,y;
} no,ne;
int flag=0;
bool check(int x,int y)
{
    if(x>=0&&x<n&&y>=0&&y<m)
        return true;
    return false;
}
void DFS(int x,int y,int d)
{
    if(d==0||flag==1)
        return ;
    for(int i=0; i<4; i++)
    {
        int fx=dirx[i]+x;
        int fy=diry[i]+y;
        if((fx==ex&&fy==ey)||(fx==sx&&fy==sy))
        {
            flag=1;
            return ;
        }
        if(check(fx,fy))
        {
            if(mat[fx][fy]=='M')
            {
                continue;
            }
            if( v[fx*m+fy]+1<v[x*m+y])
            {
                v[fx*m+fy]=d-1;
                DFS(fx,fy,d-1);
            }
        }
    }
}
int BFS()
{
    queue<node>q;
    no.x=sx,no.y=sy;
    q.push(no);
    v[sx*m+sy]=0;
    while(!q.empty())
    {
        no=q.front();
        q.pop();
        for(int i=0; i<4; i++)
        {
            ne.x=dirx[i]+no.x;
            ne.y=diry[i]+no.y;
            if(check(ne.x,ne.y))
            {
                if(v[ne.x*m+ne.y]==-1)
                {
                    v[ne.x*m+ne.y]=v[no.x*m+no.y]+1;
                    q.push(ne);
                }
            }
        }
    }
    return v[ex*m+ey];
}
int main()
{
    int d;
    char s;
    scanf("%d %d %d",&n,&m,&d);
    t=d;
    for(int i=0; i<n; i++)
    {
        getchar();
        for(int j=0; j<m; j++)
        {
            scanf("%c",&s);
            if(s=='S')
            {
                sx=i,sy=j;
            }
            if(s=='F')
                ex=i,ey=j;
            mat[i].push_back(s);
            v[i*m+j]=-1;
        }
    }
    for(int i=0; i<n; i++)
    {
        for(int j=0; j<m; j++)
        {
            if(mat[i][j]=='M')
            {
                if(v[i*m+j]==d)
                    continue;
                v[i*m+j]=d;
                DFS(i,j,d);
            }
        }
        if(flag==1)
            break;
    }
    if(flag==1)
        printf("-1\n");
    else
    {
        int ans = BFS();
        printf("%d\n",ans);
    }
    return 0;
}
