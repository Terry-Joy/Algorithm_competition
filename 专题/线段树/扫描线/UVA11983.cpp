//矩形k次以上面积并 原题是覆盖整数点右上坐标+1转化
#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
using namespace std;
typedef long long ll;
const int maxn=3e4+5;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a){return h<a.h;}
}line[maxn<<1];
int t,n,k,X[maxn<<1];
struct SegmentTree{
    int len[maxn<<3][11],cnt[maxn<<3];//被覆盖i次以上的长度以及当前区间被覆盖次数
    void pushUp(int p,int l,int r){
        for(int i=0;i<=k;++i)len[p][i]=0;//上一次更新后得清空
        if(cnt[p]>=k){//当前覆盖次数>=k
            len[p][k]=X[r+1]-X[l];
        }else if(l==r){//叶子结点只更新对应次数
            len[p][cnt[p]]=X[r+1]-X[l];
        }else{//覆盖不满的话，得把子结点标记影响上传
            for(int i=0;i<=k;++i)
                len[p][min(k,cnt[p]+i)]+=len[ls][i]+len[rs][i];
        }
    }
    void build(int p,int l,int r){
        cnt[p]=0;
        for(int i=1;i<=k;++i)len[p][i]=0;
        len[p][0]=X[r+1]-X[l];//初态的时候得赋值
        if(l==r)return;
        int mid=l+r>>1;
        build(lson);
        build(rson);
    }
    void update(int p,int l,int r,int L,int R,int val){
        if(L<=l&&r<=R){
            cnt[p]+=val;
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
    cin>>t;
    int T=0;
    while(t--){
        cin>>n>>k;
        int a,b,c,d;
        line[0].h=0;
        for(int i=1;i<=n;++i){
            cin>>a>>b>>c>>d;
            c++;d++;
            line[(i<<1)-1]={a,c,1,b};line[i<<1]={a,c,-1,d};
            X[(i<<1)-1]=a;X[i<<1]=c;
        }
        sort(line+1,line+1+2*n);
        sort(X+1,X+1+2*n);
        int m=unique(X+1,X+1+2*n)-(X+2);
        tr.build(1,1,m);
        ll ans=0;
        for(int i=1;i<=2*n;++i){
            ans+=1ll*tr.len[1][k]*(line[i].h-line[i-1].h);
            int l1=lower_bound(X+1,X+2+m,line[i].xL)-X;
            int r1=lower_bound(X+1,X+2+m,line[i].xR)-X-1;
            tr.update(1,1,m,l1,r1,line[i].flag);
        }
        cout<<"Case "<<++T<<": "<<ans<<"\n";
    }
    return 0;
}
