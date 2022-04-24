#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=1e4+5;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a){
        return h<a.h;
    }
}line[maxn<<1];
unordered_map<char,int>mp;
int t,n,a,b,c,d,X[maxn<<1],id[8];
ll ans[8];
char s;
struct SegmentTree{
    int cnt[maxn<<3][8],len[maxn<<3][8];
    void build(int p,int l,int r){
        for(int i=1;i<=7;++i)len[p][i]=0,cnt[p][i]=0;
        len[p][0]=X[r+1]-X[l];
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void pushUp(int p,int l,int r){
        int tmp=0;
        if(cnt[p][1])tmp|=1;
        if(cnt[p][2])tmp|=2;
        if(cnt[p][4])tmp|=4;
        for(int i=0;i<=7;++i)len[p][i]=0;
        if(tmp){ 
            len[p][tmp]=X[r+1]-X[l];
            for(int i=1;i<=7;++i){ 
                if(l!=r&&tmp!=(tmp|i)){//叶子不能再递归 
                    len[p][tmp|i]+=len[ls][i]+len[rs][i];
                    len[p][tmp]-=len[ls][i]+len[rs][i];
                }
            }
        }else 
            if(l!=r)
                for(int i=1;i<=7;++i)len[p][i]=len[ls][i]+len[rs][i];
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            if(val>0)cnt[p][val]++;
            else cnt[p][-val]--;
            return pushUp(p,l,r);
        }
        int mid=l+r>>1;
        if(L<=mid)update(lson,L,R,val);
        if(R>mid)update(rson,L,R,val);
        pushUp(p,l,r);
    }
}tr;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    mp['R']=1;mp['G']=2;mp['B']=4;
    id[1]=1;id[2]=2;id[3]=4;id[4]=3;id[5]=5;id[6]=6;id[7]=7;
    cin>>t;
    int T=0;
    while(t--){
        memset(ans,0,sizeof(ans));
        cin>>n;
        for(int i=1;i<=n;++i){
            cin>>s>>a>>b>>c>>d;
            line[(i<<1)-1]={a,c,mp[s],b};line[(i<<1)]={a,c,-mp[s],d};
            X[(i<<1)-1]=a;X[i<<1]=c;
        }
        sort(X+1,X+1+2*n);
        sort(line+1,line+1+2*n);
        int m=unique(X+1,X+1+2*n)-(X+2);
        tr.build(1,1,m);
        for(int i=1;i<=2*n;++i){
            for(int j=1;j<=7;++j)ans[j]+=1ll*(line[i].h-line[i-1].h)*tr.len[1][id[j]];
            int l=lower_bound(X+1,X+2+m,line[i].xL)-X;
            int r=lower_bound(X+1,X+2+m,line[i].xR)-X-1;
            tr.update(1,1,m,l,r,line[i].flag);
        }
        cout<<"Case "<<++T<<":\n";
        for(int i=1;i<=7;++i)
            cout<<ans[i]<<"\n";
    }
    return 0;
}
