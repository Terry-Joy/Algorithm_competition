#include<bits/stdc++.h>
#define fi first 
#define se second
using namespace std;
typedef pair<int,int>P;
char s[105][105];
int t,dir[4][2]={{-1,0},{1,0},{0,1},{0,-1}};
bool v[105][105];
int d[105][105],sx,sy,ex,ey,n,m;
int bfs(){
    memset(d,-1,sizeof(d));
    queue<P>q;
    q.push({sx,sy});
    v[sx][sy]=1;
    d[sx][sy]=0;
    while(!q.empty()){
        P x=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int xx=x.fi+dir[i][0],yy=x.se+dir[i][1];
            if(xx<1||xx>n||yy<1||yy>m)continue;
            if(s[xx][yy]=='#')continue;
            if(d[xx][yy]!=-1)continue;
            d[xx][yy]=d[x.fi][x.se]+1;
            q.push({xx,yy});
        }
    }
    return d[ex][ey];
}
int main(){
    scanf("%d",&t);
    while(t--){
        scanf("%d%d",&n,&m);
        for(int i=1;i<=n;++i){
            scanf("%s",s[i]+1);
        }
        for(int i=1;i<=n;++i)
            for(int j=1;j<=m;++j){
                if(s[i][j]=='S'){
                    sx=i;sy=j;
                }
                if(s[i][j]=='E'){
                    ex=i;ey=j;
                }
            }
        cout<<bfs()<<"\n";
    }
    return 0;
}