#include<bits/stdc++.h>
#define fi first 
#define se second
#define lson lc[p],l,mid
#define rson rc[p],mid+1,r
#define ls lc[p]
#define rs rc[p]
#define eb emplace_back
using namespace std;
typedef pair<int,int>PI;
const int maxn=1.3e6+5;
const int N=maxn*16;
vector<int>G[maxn];
int rt[maxn],n;
char s[maxn],s2[maxn];
struct GSAM{ 
    int link[maxn],ch[maxn][26],tot,len[maxn];
    int mx[N],lc[N],rc[N],fa[maxn][22],cnt,flag[N],ps[maxn],limit[maxn];
    struct Node{
        int l,r,pl,id;
        Node(int _l=0,int _r=0,int _pl=0,int _id=0):l(_l),r(_r),pl(_pl),id(_id){ }
    };
    vector<Node>Q[maxn];
    vector<pair<int,int>>ans;
    GSAM(){ tot=1;cnt=0;}
    void pushUp(int p){ 
        if(mx[ls]>=mx[rs])mx[p]=mx[ls],flag[p]=flag[ls];
        else mx[p]=mx[rs],flag[p]=flag[rs];
    }
    PI ask(int p,int l,int r,int L,int R){ 
        if(!p)return PI(100000,0);
        if(L<=l&&r<=R)return PI(flag[p],mx[p]);
        int mid=l+r>>1;
        PI x1={0,0},x2={ 0,0};
        if(L<=mid)x1=ask(lson,L,R);
        if(R>mid)x2=ask(rson,L,R);
        if(x1.se>=x2.se)return x1;
        else return x2;
    }
    void update(int&p,int l,int r,int x){ 
        if(!p)p=++cnt;
        if(l==r){ 
            mx[p]++;flag[p]=l;return;
        }
        int mid=l+r>>1;
        if(x<=mid)update(lson,x);
        else update(rson,x);
        pushUp(p);
    }
    int extend(int c, int last) {
        if (ch[last][c]) {
            int p = last, q = ch[p][c];
            if (len[p] + 1 == len[q]) return q;
            int newq = ++tot ;
            memcpy(ch[newq], ch[q], sizeof(ch[q])); 
            len[newq] = len[p] + 1; 
            link[newq] = link[q];
            link[q] = newq; 
            for (; p && ch[p][c] == q; p = link[p]) ch[p][c] = newq;
            return newq;
        }
        int p = last, now = ++ tot;
        len[now] = len[p] + 1;
        for (; p && ! ch[p][c]; p = link[p]) ch[p][c] = now;
        if (! p) {
            link[now] = 1; 
            return now;
        }
        int q = ch[p][c];
        if (len[q] == len[p] + 1) {
            link[now] = q; 
            return now;
        }
        int newq = ++ tot;
        memcpy(ch[newq], ch[q], sizeof(ch[q])); 
        link[newq] = link[q], len[newq] = len[p] + 1; 
        link[q] = link[now] = newq;
        for (; p && ch[p][c] == q; p = link[p]) ch[p][c] = newq;
        return now;
    }
    int merge(int p,int q,int l,int r){ 
        if(!p||!q)return p+q;
        int root=++cnt,mid=l+r>>1;
        if(l==r){ 
            mx[root]=mx[p]+mx[q];
            flag[root]=l;
            return root;
        }
        lc[root]=merge(lc[p],lc[q],l,mid);
        rc[root]=merge(rc[p],rc[q],mid+1,r);
        pushUp(root);
        return root;
    }
    void dfs(int x,int f){ 
        for(auto&v:G[x]){ 
            dfs(v,x);
            rt[x]=merge(rt[x],rt[v],1,n);
        }
    }
    void init(){ 
        int L=strlen(s+1),p=1,nowlen=0;
        for(int i=1;i<=L;++i){ 
            int c=s[i]-'a';
            if(ch[p][c]){ 
                p=ch[p][c];nowlen++;
            }else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else{ 
                    nowlen=len[p]+1;
                    p=ch[p][c];
                }
            }
            ps[i]=p;limit[i]=nowlen;
        }
        for(int i=1;i<=tot;++i)fa[i][0]=link[i];
        for(int j=1;j<=20;++j)
            for(int i=1;i<=tot;++i)
                fa[i][j]=fa[fa[i][j-1]][j-1];
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1,0);
    }
    void solve(){ 
        int m,l,r,pl,pr;
        cin>>m;
        for(int i=1;i<=m;++i){ 
            cin>>l>>r>>pl>>pr;
            int nowpos=ps[pr];
            if(limit[pr]<pr-pl+1){ 
                cout<<l<<" "<<"0\n";
                continue;
            }
            for(int j=20;j>=0;--j){ 
                if(fa[nowpos][j]&&len[fa[nowpos][j]]>=pr-pl+1)
                    nowpos=fa[nowpos][j];
            }
            PI w=ask(rt[nowpos],1,n,l,r);
            if(!w.se)cout<<l<<" "<<"0\n";
            else cout<<w.fi<<" "<<w.se<<"\n";
        }
    }
}gsam;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s+1);
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>(s2+1);
        int las=1,len=strlen(s2+1);
        for(int j=1;j<=len;++j){ 
            las=gsam.extend(s2[j]-'a',las);
            gsam.update(rt[las],1,n,i);
        }
    }
    gsam.init();
    gsam.solve();
    return 0;
}

