int dfn[maxn],d[maxn],st[maxn<<1][21],lg[maxn<<1],ti;
void dfs(int x,int f){
    dfn[x]=++ti;d[x]=d[f]+1;st[ti][0]=x;
    for(int i=head[x];i;i=next1[i]){
        int y=ver[i];
        if(y==f)continue;
        dfs(y,x);
        st[++ti][0]=x;
    }
}
void RMQ(){
    for(int i=2;i<=ti;++i)lg[i]=lg[i>>1]+1;
    for(int j=1;j<=lg[ti];++j)
        for(int i=1;(i+(1<<j)-1)<=ti;++i){
            int r=i+(1<<(j-1));
            st[i][j]=d[st[i][j-1]]<d[st[r][j-1]]?st[i][j-1]:st[r][j-1];
        }
}
int query(int l,int r){
    if(l>r)swap(l,r);
    int k=lg[r-l+1];
    return d[st[l][k]]<d[st[r-(1<<k)+1][k]]?st[l][k]:st[r-(1<<k)+1][k];
}
void init(int rt){
    dfs(rt,0);
    RMQ();
}
int LCA(int x,int y){
    return query(dfn[x],dfn[y]);
}
