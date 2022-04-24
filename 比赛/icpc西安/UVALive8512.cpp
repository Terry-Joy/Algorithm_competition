//线段树维护线性基交 O(qlogn(log^2max))
//本题求区间异或后|k的最大值
#include<bits/stdc++.h>
#define lson p<<1,l,mid 
#define rson p<<1|1,mid+1,r 
#define ls p<<1 
#define rs p<<1|1
using namespace std;
const int maxn=1e4+5;
int T,a[maxn],q,k,L,R,n;
struct LB{
    int cnt;
    int d[33],p[33];
    LB(){}
    void init(){
        memset(d,0,sizeof(d));
    }
    void insert(int x){
        for(int i=29;i>=0;--i){
            if(x&(1<<i)){
                if(d[i])x^=d[i];
                else{
                    d[i]=x;break;
                }
            }
        }
    }
    int getMax(){   
        int ans=0;
        for(int i=29;i>=0;--i){
            if((ans^d[i])>ans)ans^=d[i];
        }
        return ans;
    }    
    LB merge(LB m){
        LB ret;
        for(int i=0;i<=29;i++){ret.d[i]=d[i];}
        for(int i=0;i<=29;i++){
            for(int j=i;j>=0;j--){
                if(m.d[i]&(1<<j)){
                    if(ret.d[j]) m.d[i]^=ret.d[j];
                    else {ret.d[j]=m.d[i];break;}
                }
            }
        }
        return ret;
    }
}tr[maxn<<2],A,tmp;
void pushUp(int p){
    tr[p]=tr[ls].merge(tr[rs]);
}
void build(int p,int l,int r){
    if(l==r){
        tr[p].init();
        tr[p].insert(a[l]);
        return;
    }
    int mid=l+r>>1;
    build(lson);
    build(rson);
    pushUp(p);
}
LB query(int p,int l,int r,int L,int R){
    if(L<=l&&r<=R)return tr[p];
    int mid=l+r>>1;
    if(R<=mid)return query(lson,L,R);
    else if(L>mid)return query(rson,L,R);
    else return query(lson,L,R).merge(query(rson,L,R));
}
int main(){
    cin>>T;
    while(T--){
        cin>>n>>q>>k;
        k=~k;
        for(int i=1;i<=n;++i)cin>>a[i],a[i]&=k;
        k=~k;
        build(1,1,n);
        for(int i=1;i<=q;++i){
            cin>>L>>R;
            cout<<(query(1,1,n,L,R).getMax()|k)<<"\n";
        }
    }
    return 0;
}