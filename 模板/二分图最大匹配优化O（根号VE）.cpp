// hk算法时间复杂度sqrt(V)*E
vector<int> g[maxn];
int un, vn;
int linker[maxn], used[maxn];
int mx[maxn], my[maxn], dx[maxn], dy[maxn], dis;

bool search_path()
{
    queue<int> que;
    dis=inf;
    memset(dx, -1, sizeof(dx));
    memset(dy, -1, sizeof(dy));
    for(int u=1; u<=un; u++){
        if(mx[u]==-1) que.push(u), dx[u]=0;
    }
    while(!que.empty())
    {
        int u=que.front(); que.pop();
        if(dx[u]>dis) break;
        for(auto &v: g[u]){
            if(dy[v]==-1){
                dy[v]=dx[u]+1;
                if(my[v]==-1) dis=dy[v];
                else dx[my[v]]=dy[v]+1, que.push(my[v]);
            }
        }
    }
    return dis!=inf;
}

bool dfs(int u)
{
    for(auto &v: g[u])
    {
        if(!used[v] && dy[v]==dx[u]+1){
            used[v]=true;
            if(my[v]!=-1 && dy[v]==dis) continue;
            if(my[v]==-1 || dfs(my[v])){
                my[v]=u, mx[u]=v;
                return true;
            }
        }
    }
    return false;
}

int hopcroft_karp()
{
    int res=0;
    memset(mx, -1, sizeof(mx));
    memset(my, -1, sizeof(my));
    while(search_path()){
        memset(used, 0, sizeof(used));
        for(int u=1; u<=un; u++)
            if(mx[u]==-1 && dfs(u)) res++;
    }
    return res;
}
printf("%d\n",hopcroft_karp());