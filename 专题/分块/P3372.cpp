#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int L[350+5],R[350+5],num,pos[maxn],n,m;
ll sum[maxn],add[maxn],a[maxn];
void update(int l,int r,ll val){
    int l1=pos[l],r1=pos[r];
    if(l1==r1){
        for(int i=l;i<=r;++i)a[i]+=val;
        sum[l1]+=1ll*(r-l+1)*val;
    }else{
        for(int i=l;i<=R[l1];++i)a[i]+=val;
        sum[l1]+=(R[l1]-l+1)*val;
        for(int i=L[r1];i<=r;++i)a[i]+=val;
        sum[r1]+=(r-L[r1]+1)*val;
        for(int i=l1+1;i<=r1-1;++i)add[i]+=val;
    }
}
ll query(int l,int r){
    int l1=pos[l],r1=pos[r];
    ll ans=0;
    if(l1==r1){
        for(int i=l;i<=r;++i)ans+=a[i];
        ans+=add[l1]*(r-l+1);
    }else{
        for(int i=l;i<=R[l1];++i)ans+=a[i];
        ans+=add[l1]*(R[l1]-l+1);
        for(int i=L[r1];i<=r;++i)ans+=a[i];
        ans+=add[r1]*(r-L[r1]+1);
        for(int i=l1+1;i<=r1-1;++i)ans+=sum[i]+add[i]*(R[i]-L[i]+1);
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>a[i];
    num=sqrt(n);
    int l=sqrt(n);
    for(int i=1;i<=num;++i){
        L[i]=(i-1)*l+1;
        R[i]=i*l;
    }
    if(R[num]<n){
        ++num;
        L[num]=R[num-1]+1;
        R[num]=n;
    }
    for(int i=1;i<=num;++i){
        for(int j=L[i];j<=R[i];++j){
            pos[j]=i;
            sum[i]+=a[j];
        }
    }
    int op,x,y,k;
    for(int i=1;i<=m;++i){
        cin>>op>>x>>y;
        if(op==1){
            cin>>k;
            update(x,y,k);
        }else{
            cout<<query(x,y)<<'\n';
        }
    }
    return 0;
}