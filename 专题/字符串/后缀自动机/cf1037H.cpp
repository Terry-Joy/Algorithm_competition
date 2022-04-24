#include<bits/stdc++.h>
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p] 
#define fi first
#define se second
#define eb emplace_back
using namespace std;
using PI=pair<char,int>;
const int maxn=2e5+5;
const int N=maxn*32;
int q;
struct SAM{
    int len[maxn],link[maxn],ch[maxn][26],tot,last;
    int lc[N],rc[N],rt[maxn],cnt,sum[N],n,sta[maxn];
    char s2[maxn];
    vector<int>G[maxn];
    void pushUp(int p){ 
        sum[p]=sum[ls]+sum[rs];
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
        int x=++cnt,mid=l+r>>1;
        sum[x]=sum[p]+sum[q];
        if(l==r)return x;
        lc[x]=merge(lc[p],lc[q],l,mid);
        rc[x]=merge(rc[p],rc[q],mid+1,r);
        return x;
    }
    int query(int p,int l,int r,int L,int R){ 
        if(!p)return 0;
        if(L<=l&&r<=R)return sum[p];
        int mid=l+r>>1,ans=0;
        if(L<=mid)ans+=query(lson,L,R);
        if(R>mid)ans+=query(rson,L,R);
        return ans;
    }
    SAM(){ tot=last=1;}
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;
        update(rt[cur],1,n,len[cur],1);
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[p]+1==len[q])link[cur]=q;
            else{ 
                int clone=++tot;
                len[clone]=len[p]+1;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
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
    void solve(){ 
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1);
        int q,l,r;
        cin>>q;
        for(int i=1;i<=q;++i){
            int nxt,j,pos=1;
            cin>>l>>r>>(s2+1);
            int L=strlen(s2+1);
            for(j=1;;++j){ 
                sta[j]=-1;
                int c=max(s2[j]-'a'+1,0);
                for(int k=c;k<26;++k){ 
                    nxt=ch[pos][k];
                    if(nxt&&query(rt[nxt],1,n,l+j-1,r)){ 
                        sta[j]=k;
                        break;
                    }
                }
                nxt=ch[pos][s2[j]-'a'];
                if(!nxt||(j==L+1)||!query(rt[nxt],1,n,l+j-1,r))break;//找不到 不是好点 找完了再加一个
                pos=nxt;
            }
            while(j&&sta[j]==-1)j--;
            if(!j)puts("-1");
            else{ 
                for(int k=1;k<j;++k)putchar(s2[k]);
                putchar(sta[j]+'a');
                puts("");
            }
        }
    }
}sam;
char s[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    int len=strlen(s+1);
    sam.n=len;
    for(int i=1;i<=len;++i)sam.extend(s[i]-'a');
    sam.solve();
    return 0;
}
