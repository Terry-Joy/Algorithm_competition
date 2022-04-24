#include<bits/stdc++.h>
#define fi first 
#define se second
#define ls (lson[now_])
#define rs (rson[now_])
#define eb emplace_back
using namespace std;
typedef pair<int,int>PI;
const int maxn=1e6+5;
const int N=maxn*32;
vector<int>G[maxn];
int rt[maxn],n;
char s[maxn],s2[maxn];
struct GSAM{ 
    int link[maxn],ch[maxn][10],tot,len[maxn];
    int mx[N],lc[N],rc[N],fa[maxn][24],cnt=0,flag[N],ps[maxn];
    struct Node{
        int l,r,pl,id;
        Node(int _l=0,int _r=0,int _pl=0,int _id=0):l(_l),r(_r),pl(_pl),id(_id){ }
    };
    vector<Node>Q[maxn];
    GSAM(){ tot=1;cnt=0;}
  
   
 	 int node_num,  lson[maxn << 5], rson[maxn << 5];
  pair <int, int> ans[maxn << 5];
  void Update(int now_) {
    ans[now_] = std :: max(ans[ls], ans[rs]);
  }
  void Insert(int &now_, int L_, int R_, int pos_) {
    if (! now_) now_ = ++ cnt;
    if (L_ == R_) {
      ++ ans[now_].first;
      ans[now_].second = - L_;
      return ;
    }
    int mid = (L_ + R_) >> 1;
    if (pos_ <= mid) Insert(ls, L_, mid, pos_);
    else Insert(rs, mid + 1, R_, pos_);
    Update(now_);
  }
  int Merge(int x_, int y_, int L_, int R_) {
    if (! x_ || ! y_) return x_ + y_;
    int now_ = ++ cnt;
    if (L_ == R_) {
      ans[now_] = ans[x_];
      ans[now_].first += ans[y_].first;
      return now_;
    }
    int mid = (L_ + R_) >> 1;
    ls = Merge(lson[x_], lson[y_], L_, mid); //傻↑逼↓ (lson写成rson)
    rs = Merge(rson[x_], rson[y_], mid + 1, R_);
    Update(now_);
    return now_;
  }
  pair <int, int> Query(int now_, int L_, int R_, int ql_, int qr_) {
    if (! now_) return pair <int, int> (0, n + 1);
    if (ql_ <= L_ && R_ <= qr_) return ans[now_];
    int mid = (L_ + R_) >> 1;
    pair <int, int> ret (0, n + 1);
    if (ql_ <= mid) ret = std :: max(ret, Query(ls, L_, mid, ql_, qr_));
    if (qr_ > mid) ret = std :: max(ret, Query(rs, mid + 1, R_, ql_, qr_));
    return ret;
  }
    void dfs(int x,int f){ 
        fa[x][0]=f;
        for(int i=1;i<=20;++i)
            fa[x][i]=fa[fa[x][i-1]][i-1];
        for(auto&v:G[x]){ 
            dfs(v,x);
            rt[x]=Merge(rt[x],rt[v],1,n);
        }
    }
     int extend(int c, int last) {
        if(ch[last][c]){
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
    void init(){ 
        int las=1,L=strlen(s+1); 
        for(int i=1;i<=L;++i){ 
            ps[i]=las=extend(s[i]-'a',las);
        }
        //for(int i=1;i<=tot;++i)cout<<link[i]<<" ";
        for(int i=2;i<=tot;++i)G[link[i]].eb(i);
        dfs(1,0);
        cout<<cnt<<"\n";
    }
    void solve(){ 
        int m,l,r,pl,pr;
        cin>>m;
        for(int i=1;i<=m;++i){ 
            cin>>l>>r>>pl>>pr;
            int nowpos=ps[pr];
            for(int j=20;j>=0;--j){ 
                if(fa[nowpos][j]&&len[fa[nowpos][j]]>=pr-pl+1)
                    nowpos=fa[nowpos][j];
            }
            PI w=Query(rt[nowpos],1,n,l,r);
            if(!w.fi)cout<<l<<" "<<0<<"\n";
            else cout<<-w.se<<" "<<w.fi<<"\n";
        }
        //  query();
        //  for(int i=1;i<=m;++i)
        //     cout<<ans[i].fi<<" "<<ans[i].se<<"\n";
    }
}gsam;
int main(){ 
    scanf("%s",s+1); 
    cin>>n;
    for(int i=1;i<=n;++i){ 
        scanf("%s",s2+1); 
        int las=1,len=strlen(s2+1);
        for(int j=1;j<=len;++j){ 
            las=gsam.extend(s2[j]-'a',las);
            gsam.Insert(rt[las],1,n,i);
        }
    }
    for(int i=1;i<=gsam.tot;++i)cout<<gsam.link[i]<<" "; 
    gsam.init();
    // for(int i=1;i<=1000;++i)cout<<gsam.mx[i]<<" ";
    gsam.solve();
    return 0;
}

