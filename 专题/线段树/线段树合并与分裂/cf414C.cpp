#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll cnt[22][2];
int a[(1<<20)+5],t[(1<<20)+5],n,m,q;
void merge(int l,int r,int x){//顺逆都跑一遍不用管是否相等
    if(l>=r)return;
    int mid=l+r>>1;
    merge(l,mid,x-1);
    merge(mid+1,r,x-1);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<a[j]){   
            cnt[x][1]+=r-j+1;
            i++;
        }else j++;
    }
    i=l,j=mid+1;
    while(i<=mid&&j<=r){
        if(a[i]>a[j]){
            cnt[x][0]+=mid-i+1;
            t[k++]=a[j++];
        }else
            t[k++]=a[i++];
    }
    while(i<=mid)t[k++]=a[i++];
    while(j<=r)t[k++]=a[j++];
    for(int i=l;i<=r;++i)
        a[i]=t[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    int x=1<<n;
    for(int i=1;i<=x;++i)cin>>a[i];
    merge(1,x,n);
    cin>>q;
    while(q--){
        cin>>m;
        ll ans=0;
        for(int i=1;i<=n;++i){
            if(i<=m)swap(cnt[i][0],cnt[i][1]);
            ans+=cnt[i][0];
        }
        cout<<ans<<"\n";
    }
    return 0;
}