#include<bits/stdc++.h>
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p]
#define eb emplace_back
using namespace std;
const int maxn=4e5+5;
const int N=maxn*20;
vector<int>G[maxn];
int rt[maxn],n;
struct SAM{//maxn开2倍
    int len[maxn],link[maxn],ch[maxn][26],last,tot;
    int lc[N],rc[N],sum[N],cnt,ans,dp[maxn],pre[maxn],pos[maxn];
    SAM(){ //link指向状态内最长字符串的最长的一个在另一个endpos类的后缀
        tot=last=1;//sz endpos大小
    }
    void pushUp(int p){ 
        sum[p]=sum[ls]+sum[rs];
    }
    void update(int&p,int l,int r,int x){ 
        if(!p)p=++cnt;
        if(l==r){ 
            sum[p]++;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int merge(int p,int q,int l,int r){ 
        if(!p||!q)return p+q;
        int root=++cnt;
        if(l==r){ 
            sum[root]=sum[p]+sum[q];
            return root;
        }
        int mid=l+r>>1;
        lc[root]=merge(lc[p],lc[q],l,mid);
        rc[root]=merge(rc[p],rc[q],mid+1,r);
        pushUp(root);
        return root;
    }
    int query(int p,int l,int r,int L,int R){ 
        if(!p)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1;
        int ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    void dfs(int x){ 
        for(auto&v:G[x]){ 
            dfs(v);
            rt[x]=merge(rt[x],rt[v],1,n);
        }
    }
    void dfs2(int x){ 
        for(auto&v:G[x]){ 
            if(link[v]==1){ 
                dp[v]=1;pre[v]=v;
            }else{ 
                if(query(rt[pre[x]],1,n,pos[v]-len[v]+len[pre[x]],pos[v]-1)){ 
                    dp[v]=dp[pre[x]]+1;
                    pre[v]=v;
                }else{ 
                    dp[v]=dp[pre[x]];
                    pre[v]=pre[x];  
                }
            }
            dfs2(v);
        }
        ans=max(ans,dp[x]);
    }
    void solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
        dfs2(1);
        cout<<ans;
    }
    void extend(int c,int id){ 
        int cur=++tot,p=last;last=cur;
        update(rt[cur],1,n,id);
        pos[cur]=id;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;//==len[p]+1的复制出来
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                pos[clone]=pos[q];
                len[clone]=len[p]+1;
                link[clone]=link[q];link[q]=link[cur]=clone;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
}sam;
char s[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    cin>>(s+1);
    for(int i=1;i<=n;++i)sam.extend(s[i]-'a',i);
    sam.solve();
    return 0;
}
