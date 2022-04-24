struct DS{
    int fa[maxn],rank[maxn];
    void init(){
        for(int i=1;i<=n;++i)
            fa[i]=i,rank[i]=0;
    }
    int find(int x){
        if(x==fa[x])return x;
        return fa[x]=find(fa[x]);
    }
    void merge(int x,int y){
        int fx=find(x),fy=find(y);
        if(fx==fy)return;
        if(rank[fx]<rank[fy])
            fa[fx]=fy;
        else{
            fa[fy]=fx;
            if(rank[fy]==rank[fx])
                rank[fx]++;
        }
    }
}ds;