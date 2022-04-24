#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=1e3+5;
bool is[maxn][maxn];
typedef pair<int,int>Node;
Node s,e;
int h,w,dx[]={0,0,1,-1},dy[]={-1,1,0,0},d[maxn][maxn];
char mp[maxn][maxn];
void bfs(){
    memset(d,0x3f,sizeof(d));
    deque<Node>q;
    d[s.first][s.second]=0;
    q.push_front(s);
    while(!q.empty()){
        Node n1=q.front();
        q.pop_front();
        if(is[n1.first][n1.second])continue;
        is[n1.first][n1.second]=1;
        for(int i=0;i<4;++i){
            int xx=n1.first+dx[i],yy=n1.second+dy[i];
            if(xx<1||yy<1||xx>h||yy>w||mp[xx][yy]=='#'||d[xx][yy]<=d[n1.first][n1.second])continue;
            d[xx][yy]=d[n1.first][n1.second];
            q.push_front({xx,yy});
        }
        for(int i=n1.first-2;i<=n1.first+2;++i){
            if(i<1||i>h)continue;
            for(int j=n1.second-2;j<=n1.second+2;++j){
                if(j<1||j>w||mp[i][j]=='#'||d[i][j]<=d[n1.first][n1.second]+1)continue;
                d[i][j]=d[n1.first][n1.second]+1;
                q.push_back({i,j});
            }
        }
    }   
}
int main(){
    scanf("%d%d",&h,&w);
    scanf("%d%d%d%d",&s.first,&s.second,&e.first,&e.second);
    for(int i=1;i<=h;++i)
        scanf("%s",mp[i]+1);
    bfs();
    if(d[e.first][e.second]==0x3f3f3f3f)puts("-1");
    else cout<<d[e.first][e.second]<<endl;      
    return 0;
}