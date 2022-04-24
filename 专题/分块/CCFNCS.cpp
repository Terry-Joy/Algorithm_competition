#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ll;
const int maxn=1e5+5;
const int maxm=400;
int a[maxn],L[maxm],R[maxm],pos[maxn],num,cnt[maxm][maxn],sum[maxm][maxn],n,ls[maxn],rs[maxn],big,q,op;
ll ans[maxm],pre[maxn],presum[maxm];
void init(){
    big=sqrt(n);
    num=(n-1)/big+1;
    for(int i=1;i<=num;++i){
        L[i]=R[i-1]+1;
        R[i]=i*big;
    }
    R[num]=n;
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j)pos[j]=i;
    }
    for(int i=1;i<=n;++i){
        sum[pos[i]][ls[i]]++;
        sum[pos[i]][rs[i]+1]--;
    }
    for(int i=1;i<=num;++i){
        for(int j=1;j<=n;++j)
            sum[i][j]+=sum[i][j-1];
    }
    for(int i=1;i<=num;++i){
        for(int j=1;j<=n;++j){
            cnt[i][j]+=sum[i][j];
        }
    }
    for(int i=1;i<=num;++i){
        ll s=0;
        for(int j=L[i];j<=R[i];++j){
            s+=a[j];
            pre[j]=s;
        }
        presum[i]=presum[i-1]+pre[R[i]];
    }
    for(int i=1;i<=num;++i){
        for(int j=1;j<=n;++j){
            ans[i]+=(ll)cnt[i][j]*a[j];
        }
    }
}
void update(int x,int y){
    for(int i=1;i<=num;++i){
        ans[i]+=(ll)cnt[i][x]*(y-a[x]);
    }
    a[x]=y;
    int pl=pos[x];
    ll s=0;
    for(int j=L[pl];j<=R[pl];++j){
        s+=a[j];
        pre[j]=s;
    }
    for(int i=pl;i<=num;++i){
        presum[i]=presum[i-1]+pre[R[i]];
    }
}
ll ask(int l,int r){
    ll res=0;
    for(int i=l;i<=r;++i){
        int ll=ls[i],rr=rs[i];
        int pl2=pos[ll],pr2=pos[rr];
        if(pl2==pr2)res+=pre[rr]-((L[pl2]==ll)?0:pre[ll-1]);
        else{
            res+=presum[pr2-1]-presum[pl2];
            res+=pre[rr]+pre[R[pl2]]-(ll==L[pl2]?0:pre[ll-1]);
        }
    }
    return res;
}
ll query(int l,int r){
    int pl=pos[l],pr=pos[r];
    ll res=0;
    if(pl==pr){
        return ask(l,r);
    }else{
        for(int i=pl+1;i<=pr-1;++i)res+=ans[i];
        res+=ask(l,R[pl]);
        res+=ask(L[pr],r);
        return res;
    }
}
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d%d",&ls[i],&rs[i]);
    init();
    scanf("%d",&q);
    int x,y;
    for(int i=1;i<=q;++i){
        scanf("%d%d%d",&op,&x,&y);
        if(op==1){
            update(x,y);
        }else{
            cout<<query(x,y)<<"\n";
        }
    }
    return 0;
}
