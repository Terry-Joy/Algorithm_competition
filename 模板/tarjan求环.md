#### tarjan求环信息

```cpp
int dfn[maxn],times,fa[maxn],cir[maxn],cirval[maxn],circnt;
bool cirsign[maxn];
int cost[maxn];
void dfs(int x){
    dfn[x]=++times;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==fa[x])continue;
        if(!dfn[y]){
            fa[y]=x;
       		cost[y]=edge[i];
            dfs(y);
        }else if(dfn[y]>dfn[x]){
            for(;y!=x;y=fa[y]){
                cirsign[y]=1;
                cir[++circnt]=y;
                cirval[circnt]=cost[y];
            }
            cirsign[x]=1;
            cir[++circnt]=x;
            cirval[circnt]=edge[i];
        }
    }
}
```

