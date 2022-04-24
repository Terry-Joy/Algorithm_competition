#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<deque>
using namespace std;
typedef pair<int,int>P;
const int maxn=105;
const int INF=0x3f3f3f3f;
char mp[maxn][maxn];
int dis[3][maxn][maxn],h,w,t;
int dx[]={0,0,-1,1},dy[]={1,-1,0,0};
vector<P>G;
void bfs(int st,int sx,int sy){
    deque<P>q;
    dis[st][sx][sy]=0;
    q.push_front({sx,sy});
    while(!q.empty()){
        P x1=q.front();q.pop_front();
        for(int i=0;i<4;++i){
            int xx=x1.first+dx[i],yy=x1.second+dy[i];
            if(xx<1||xx>h+2||yy<1||yy>w+2||mp[xx][yy]=='*')continue;
            bool flag=(mp[xx][yy]=='#')?1:0;
            if(dis[st][xx][yy]<=dis[st][x1.first][x1.second]+flag)continue;
            dis[st][xx][yy]=flag+dis[st][x1.first][x1.second];
            flag?q.push_back({xx,yy}):q.push_front({xx,yy});
        }
    }
}
int main(){
    scanf("%d",&t);
    while(t--){
        G.clear();
        scanf("%d%d",&h,&w);
        memset(mp,'.',sizeof(mp));
        for(int i=2;i<=h+1;++i)
            scanf("%s",mp[i]+2);
        memset(dis,0x3f,sizeof(dis));
        G.push_back({1,1});
        for(int i=2;i<=h+1;++i)
            for(int j=2;j<=w+1;++j)
                if(mp[i][j]=='$')
                    G.push_back({i,j});
        for(int i=0;i<G.size();++i)
            bfs(i,G[i].first,G[i].second);
        int ans=INF;
        for(int i=1;i<=h+2;++i)
            for(int j=1;j<=w+2;++j){
                if(dis[0][i][j]!=INF&&dis[1][i][j]!=INF&&dis[2][i][j]!=INF){
                    if(ans==INF||ans>dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-2*(mp[i][j]=='#'))
                        ans=dis[0][i][j]+dis[1][i][j]+dis[2][i][j]-2*(mp[i][j]=='#');  
                }
            }
        printf("%d\n",ans);
    }
    return 0;
}