#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int>P;
const int maxn=2e3+10;
char mp[maxn][maxn],path[2*maxn],cha[]="DLRU";
bool v[maxn][maxn];
int n,m,sx,sy,d[4][2]={{1,0},{0,-1},{ 0,1},{-1,0}},prex[maxn][maxn],prey[maxn][maxn],pre[maxn][maxn];
int cnt=0;
void dfs(int x,int y){ 
    if(x==sx&&y==sy){ 
        cout<<cnt<<"\n";
        for(int i=cnt;i>=1;--i)cout<<path[i];
        return;  
    }
    int x1=prex[x][y];
    int y1=prey[x][y];
    path[++cnt]=cha[pre[x][y]];
    dfs(x1,y1);
}
void bfs(){ 
    queue<P>q;
    q.push({sx,sy});
    v[sx][sy]=1;
    while(!q.empty()){ 
        P s1=q.front();q.pop();
        int x=s1.first,y=s1.second;
        if(mp[x][y]=='E'){ 
            dfs(x,y);
            return;
        }
        for(int i=0;i<4;++i){ 
            int xx=s1.first,yy=s1.second;
            while(1){ 
                xx+=d[i][0];yy+=d[i][1];
                if(xx<1||xx>n||yy<1||yy>m||v[xx][yy])break;
                if(mp[xx][yy]=='.'||mp[xx][yy]=='E'){ 
                    v[xx][yy]=1;
                    q.push({xx,yy});
                    pre[xx][yy]=i;
                    prex[xx][yy]=s1.first;
                    prey[xx][yy]=s1.second;
                    break;
                }
            }
        }
    }
    cout<<-1<<endl;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j){ 
            cin>>mp[i][j];
            if(mp[i][j]=='S')
                sx=i,sy=j;
    }
    bfs();
}
