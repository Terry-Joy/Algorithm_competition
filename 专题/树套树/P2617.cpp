//树状数组套权值线段树求动态修改区间第k大 可以在线
#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
#define N maxn*300
#define lson lc[p],l,mid 
#define rson rc[p],mid+1,r
using namespace std;
const int maxn=2e5+5;
const int maxm=1e5+5;
int n,m,a[maxn],b[maxn],cnt,rt[maxm],jL[22],jR[22],numL,numR;
struct BitAndSegmentTree{
    int tot,lc[N],rc[N],sum[N];
    void update(int&p,int l,int r,int x,int val){
        if(!p)p=++tot;
        sum[p]+=val;
        if(l==r)return;
        int mid=l+r>>1;
        if(x<=mid)update(lson,x,val);
        else update(rson,x,val);
    }
    int kth(int l,int r,int k){//log颗一起求k大
        if(l==r)return l;
        int mid=l+r>>1,ans=0;
        for(int i=1;i<=numL;++i)ans-=sum[lc[jL[i]]];
        for(int i=1;i<=numR;++i)ans+=sum[lc[jR[i]]];
        if(ans>=k){
            for(int i=1;i<=numL;++i)//一起换根
                jL[i]=lc[jL[i]];
            for(int i=1;i<=numR;++i)
                jR[i]=lc[jR[i]];
            return kth(l,mid,k);
        }else{
            for(int i=1;i<=numL;++i)
                jL[i]=rc[jL[i]];
            for(int i=1;i<=numR;++i)
                jR[i]=rc[jR[i]];
            return kth(mid+1,r,k-ans);
        }
    }
    void add(int x,int y){
        int pos=lower_bound(b+1,b+1+cnt,a[x])-b;
        for(int i=x;i<=n;i+=lowbit(i))update(rt[i],1,cnt,pos,y);
    }
    int query(int l,int r,int k){
        numL=numR=0;
        for(int i=l-1;i;i-=lowbit(i))jL[++numL]=rt[i];//预处理树状数组上要跳的log颗线段树的根
        for(int i=r;i;i-=lowbit(i))jR[++numR]=rt[i];
        return kth(1,cnt,k);
    }
}tr;
struct Q{
    char s[2];
    int x,y,z;
}qs[maxm];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
    cnt=n;
    for(int i=1;i<=m;++i){
        cin>>qs[i].s;
        if(qs[i].s[0]=='Q'){
            cin>>qs[i].x>>qs[i].y>>qs[i].z;
        }else{
            cin>>qs[i].x>>qs[i].y;
            b[++cnt]=qs[i].y;//修改的值也要离散化 不存的话就暴力在线
        }
    }    
    sort(b+1,b+1+cnt);
    cnt=unique(b+1,b+1+cnt)-(b+1);
    for(int i=1;i<=n;++i)tr.add(i,1);//树状数组上建树
    for(int i=1;i<=m;++i){
        if(qs[i].s[0]=='Q'){
            cout<<b[tr.query(qs[i].x,qs[i].y,qs[i].z)]<<"\n";
        }else{
            tr.add(qs[i].x,-1);
            a[qs[i].x]=qs[i].y;
            tr.add(qs[i].x,1);
        }
    }
    return 0;
}