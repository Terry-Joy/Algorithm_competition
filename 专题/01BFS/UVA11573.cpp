#include<iostream>
#include<cstdio>
#include<cstring>
#include<deque>
using namespace std;
const int maxn=1e3+5;
struct Node{
    int x,y;
    Node(int a,int b):x(a),y(b){}
};
int d[maxn][maxn],h,w,n,sx,sy,ex,ey;
int dr[8][2]{{-1,0},{-1,1},{0,1},{1,1},{1,0},{1,-1},{0,-1},{-1,-1}};
char mp[maxn][maxn];
bool is[maxn][maxn];
int bfs(){
    memset(d,0x3f,sizeof(d));
    deque<Node>q;
    q.push_front(Node(sx,sy));
    d[sx][sy]=0;
    while(!q.empty()){
        Node s1=q.front();
        q.pop_front();
        for(int i=0;i<8;++i){
            int xx=s1.x+dr[i][0],yy=s1.y+dr[i][1];
            bool flag=0;
            if(mp[s1.x][s1.y]-'0'!=i)flag=1;
            if(xx<1||xx>h||yy<1||yy>w||d[xx][yy]<=d[s1.x][s1.y]+flag)continue;
            d[xx][yy]=d[s1.x][s1.y]+flag;
            flag?q.push_back(Node(xx,yy)):q.push_front(Node(xx,yy));
        }
    }
    return d[ex][ey];
}
int main(){
    scanf("%d%d",&h,&w);
    for(int i=1;i<=h;++i)
        scanf("%s",mp[i]+1);
    scanf("%d",&n);
    while(n--){
        scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
        printf("%d\n",bfs());
    }
    return 0;
}