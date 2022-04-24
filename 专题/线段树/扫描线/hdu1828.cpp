#include<bits/stdc++.h>
#define ls p<<1
#define rs p<<1|1
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
using namespace std;
int n;
const int maxn=2e4+5;
struct Line{
    int xL,xR,flag,h;
    bool operator<(const Line&a){return h<a.h;}
}line[maxn];
int cnt[maxn<<2],num[maxn<<2],len[maxn<<2];//当前线段是否被覆盖，当前有多少竖线
bool Lf[maxn<<2],Rf[maxn<<2];//当前左右端点是否被覆盖
int a,b,c,d;
void pushUp(int p,int l,int r){
    if(cnt[p]){
        num[p]=2;
        Lf[p]=Rf[p]=1;
        len[p]=r-l+1;
    }else if(l==r){//不被覆盖时候防止越界
        num[p]=len[p]=Lf[p]=Rf[p]=0;
    }else{
        Lf[p]=Lf[ls];Rf[p]=Rf[rs];
        len[p]=len[ls]+len[rs];
        num[p]=num[ls]+num[rs];
        if(Rf[ls]&&Lf[rs])num[p]-=2;//左右都被覆盖就回去
    }
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
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        int lmn=20001,rmx=1;
        for(int i=1;i<=n;++i){
            cin>>a>>b>>c>>d;
            a+=10001,c+=10001;
            lmn=min(lmn,a);rmx=max(rmx,c);
            line[(i<<1)-1]={a,c,1,b};line[i<<1]={a,c,-1,d};
        }
        sort(line+1,line+1+2*n);
        int last=0,ans=0;
        for(int i=1;i<=2*n;++i){
            if(line[i].xL<line[i].xR)
            update(1,1,rmx,line[i].xL,line[i].xR-1,line[i].flag);
            ans+=num[1]*(line[i+1].h-line[i].h);
            ans+=abs(len[1]-last);
            last=len[1];
        }
        cout<<ans<<"\n";
    }
    return 0;
}