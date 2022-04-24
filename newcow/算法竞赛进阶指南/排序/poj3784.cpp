#include<bits/stdc++.h>

using namespace std;
const int maxn=10002;
int t,num[maxn*4],id,a[maxn],n,cnt,b[maxn];
int kth(int p,int l,int r,int rank){
    if(l==r)return l;
    int mid=l+r>>1;
    if(rank<=num[p<<1])return kth(p<<1,l,mid,rank);
    return kth(p<<1|1,mid+1,r,rank-num[p<<1]);
}
void update(int p,int l,int r,int val){
    num[p]+=1;
    if(l==r)return;
    int mid=l+r>>1;
    if(val<=mid)update(p<<1,l,mid,val);
    else update(p<<1|1,mid+1,r,val);
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    for(int j=1;j<=t;++j){
        cin>>id>>n;
        memset(num,0,sizeof(num));
        for(int i=1;i<=n;++i)cin>>a[i],b[i]=a[i];
        sort(b+1,b+1+n);
        int m=unique(b+1,b+1+n)-(b+1);
        for(int i=1;i<=n;++i){ 
            a[i]=lower_bound(b+1,b+1+m,a[i])-b;
        }
        cout<<id<<" "<<(n+1)/2<<"\n";
        int cnt=(n+1)/2,tot=0;
        for(int i=1;i<=n;++i){ 
            update(1,1,m,a[i]);
            if(i&1){ 
                cout<<b[kth(1,1,m,(i+1)/2)]<<" ";
                tot++;
            }
            if(tot==10&&i<n){ 
                cout<<"\n";tot=0;
            }
        }
        if(j!=t)cout<<"\n";
    }
    return 0;
}
