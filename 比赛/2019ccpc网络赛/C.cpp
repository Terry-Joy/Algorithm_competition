#include<bits/stdc++.h>
#define eb emplace_back
#define ls lc[p]
#define rs rc[p]
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=2e5+5;
const int N=maxn*20;
int t,n,q;
struct SAM{ 
    int len[maxn],tot,last,ch[maxn][26],cnt,lc[N],rc[N],sum[N],rt[maxn],fa[maxn][24],pos[maxn],link[maxn];
    vector<int>G[maxn];
    SAM(){ 
        tot=last=1;
    }
    void pushUp(int p){ 
        if(ls&&!rs)sum[p]=sum[ls];
        else if(rs&&!ls)sum[p]=sum[rs];
        else if(ls&&rs)sum[p]=sum[ls]+sum[rs];
    }
    void update(int&p,int l,int r,int x,int val){ 
        if(!p)p=++cnt;
        if(l==r){ 
            sum[p]+=val;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){ 
        if(!p||!q)return p+q;
        int x=++cnt;
        sum[x]=sum[p]+sum[q];
        if(l==r)return x;
        int mid=l+r>>1;
        lc[x]=merge(lc[p],lc[q],l,mid);
        rc[x]=merge(rc[p],rc[q],mid+1,r);
        return x;
    }
    int query(int p,int l,int r,int k){ 
        if(l==r)return l;
        int mid=l+r>>1;
        if(sum[ls]>=k)return query(lson,k);
        else return query(rson,k-sum[ls]);
    }
    void extend(int c,int id){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;
        pos[id]=cur;
        update(rt[cur],1,n,id,1);
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[q]==len[p]+1)link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            rt[x]=merge(rt[x],rt[v],1,n);
        }
    }
    void init(){ 
        for(int i=1;i<=tot;++i)fa[i][0]=link[i];
        for(int j=1;j<=22;++j){ 
            for(int i=1;i<=tot;++i)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        }
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
    }
    int solve(int l,int r,int k){ 
        int p=pos[r];
        for(int i=22;i>=0;--i){ 
            if(fa[p][i]&&len[fa[p][i]]>=r-l+1)
                p=fa[p][i];
        }
        if(sum[rt[p]]<k)return -1;
        return query(rt[p],1,n,k)-(r-l+1)+1;
    }
    void init2(){ 
        for(int i=1;i<=tot;++i)rt[i]=0,G[i].clear(),link[i]=0;
        for(int i=1;i<=tot;++i)
            memset(ch[i],0,sizeof(ch[i]));
        for(int i=1;i<=cnt;++i)sum[i]=lc[i]=rc[i]=0;
        tot=last=1;
        cnt=0;
    }
}sam;
char s[maxn];
int main(){ 
    scanf("%d",&t);
    while(t--){ 
        scanf("%d%d",&n,&q);
        scanf("%s",s+1);
        for(int i=1;i<=n;++i)sam.extend(s[i]-'a',i);
        sam.init();
        int l,r,k;
        for(int i=1;i<=q;++i){ 
            scanf("%d%d%d",&l,&r,&k);
            cout<<sam.solve(l,r,k)<<"\n";
        }
        sam.init2();
    }
    return 0;
}
