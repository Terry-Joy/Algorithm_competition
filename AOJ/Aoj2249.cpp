#include <queue>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
using namespace std;
typedef long long ll;
const int inf=0x3f3f3f3f;
const int maxn=20010;
struct edge{
    int to,cost,val;
    edge(){}
    edge(int a,int b,int c){to=a;cost=b;val=c;}
};
typedef pair<int,int>P;
vector<edge>G[maxn];
int dis[maxn],value[maxn];
void dijkstra(int st){
    priority_queue<P,vector<P>,greater<P> >que;
    fill(dis,dis+maxn,inf);
    fill(value,value+maxn,inf);
    dis[st]=0;
    que.push(P(0,st));
    while(!que.empty()){
        P p=que.top();que.pop();
        int v=p.second;
        if(dis[v]<p.first) continue;
        for(unsigned int i=0;i<G[v].size();i++){
            edge e=G[v][i];
            if(dis[e.to]>dis[v]+e.cost){
                dis[e.to]=dis[v]+e.cost;
                value[e.to]=e.val;
                que.push(P(dis[e.to],e.to));//因为都是从1出发，例如1到3最小距离是通过1->2->3这样的，我们将1->3的费用就记为
                                            //2->3的费用，因为1->2的费用肯定已经会花的，要的是用的每条路的费用，所以最后将1到
                                            //每个点的费用加起来就行了
            }else if(dis[e.to]==dis[v]+e.cost){//相等时要小的费用
                value[e.to]=min(value[e.to],e.val);
            }
        }
    }
}
int main(){
    int n,m,a,b,c,d;
    while(scanf("%d%d",&n,&m)!=-1){
        if(n==0&&m==0) break;
        for(int i=0;i<maxn;i++) G[i].clear();
        for(int i=0;i<m;i++){
            scanf("%d%d%d%d",&a,&b,&c,&d);
            G[a].push_back(edge(b,c,d));
            G[b].push_back(edge(a,c,d));
        }
        dijkstra(1);
        int ans=0;
        for(int i=2;i<=n;i++) ans+=value[i];
        printf("%d\n",ans);
    }
    return 0;
}

