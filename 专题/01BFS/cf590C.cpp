#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
typedef pair<int,int>P;
const int maxn=1e3+5;
const int INF=0x3f3f3f3f;
char mp[maxn][maxn];
int d[4][maxn][maxn],n,m;
int dx[]={-1,1,0,0},dy[]={0,0,-1,1};
void bfs(int st,int sx,int sy){
    deque<P>q;
    for(int i=1;i<=n;++i)
        for(int j=1;j<=m;++j)
            d[st][i][j]=INF;
    d[st][sx][sy]=0;
    q.push_front({sx,sy});
    while(!q.empty()){
        P s1=q.front();
        q.pop_front();
        for(int i=0;i<4;++i){
            int xx=s1.first+dx[i],yy=s1.second+dy[i];
            if(xx<1||xx>n||yy<1||yy>m||mp[xx][yy]=='#')continue;
            int dis=d[st][s1.first][s1.second]+(mp[xx][yy]=='.');
            if(d[st][xx][yy]<=dis)continue;
            d[st][xx][yy]=dis;
            mp[xx][yy]=='.'?q.push_back({xx,yy}):q.push_front({xx,yy});
        }
    }
}
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)
        scanf("%s",mp[i]+1);
    for(int st=1;st<=3;++st){
        int a,b;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j)
                if(mp[i][j]-'0'==st){
                    a=i;b=j;
                    i=n+1,j=m+1;
                }
        bfs(st,a,b);
    }    
    int ans=-1;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(mp[i][j]=='#')continue;
            if(d[1][i][j]==INF||d[2][i][j]==INF||d[3][i][j]==INF)continue;
             if(ans==-1||ans>d[1][i][j]+d[2][i][j]+d[3][i][j]-2*(mp[i][j]=='.'))
                    ans=d[1][i][j]+d[2][i][j]+d[3][i][j]-2*(mp[i][j]=='.');
        }
    }
    cout<<ans<<endl;
    return 0;
}