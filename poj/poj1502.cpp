#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
#define for0(a,b) for(a=0;a<b;++a)
#define for1(a,b) for(a=1;a<=b;++a)
#define foru(i,a,b) for(i=a;i<=b;++i)
#define ford(i,a,b) for(i=a;i>=b;--i)
using namespace std;
 
typedef double db;
typedef long long ll;
const db eps = 1e-8;
const int INF = 1e9;
const int N = 105;
typedef pair<int,int> P;
 
struct node{
    int v, c;
    node(int v=0, int c=0):v(v),c(c){ }
};
int head[N], next[N*N], to[N*N], val[N*N], tot, n;
 
void init(){
    memset(head, -1, sizeof head );
    tot = 0;
}
 
void addedge(int u, int v, int c)
{
    next[tot] = head[u];
    to[tot] = v;
    val[tot] = c;
    head[u] = tot++;
}
 
int d[N];
bool vis[N];
priority_queue<P, vector<P>, greater<P> > pq;
 
void dijkstra(int s){
    for(int i=1; i<=n; ++i) {d[i]=INF; vis[i] = false;}
    d[s] = 0;
    while(!pq.empty()) pq.pop();
    pq.push(P(0,s));
    P tmp;
    while(!pq.empty()){
        tmp = pq.top(); pq.pop();
        int &u = tmp.second;
        if(vis[u]) continue;
        vis[u] = true;
        for(int i=head[u]; ~i; i=next[i]){
            int &v = to[i];
            int &cost = val[i];
            if(!vis[v]&&d[v] > d[u] + cost){
                d[v] = d[u] + cost;
                pq.push(P(d[v],v));
            }
        }
    }
}
 
int main()
{
    scanf("%d", &n);
    init();
    char x[10];
    for(int i=2; i<=n; ++i){
        for(int j=1; j<i; ++j){
            scanf("%s", x);
            if(x[0]!='x'){
                int c = atoi(x);
                addedge(i, j, c);
                addedge(j, i, c);
            }
        }
    }
    dijkstra(1);
    int ans = -INF;
    for(int i=2; i<=n; ++i) {
        ans = max(d[i], ans);
    }
    printf("%d\n", ans );
    return 0;
}

