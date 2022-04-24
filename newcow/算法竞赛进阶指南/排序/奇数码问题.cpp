#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=250005;
int a[maxn],t1[maxn],n,cnt1=0,cnt2=0;
ll ans1=0,ans2=0;
void merge(int l,int r,ll&ans){
    if(l==r)return;
    int mid=l+r>>1;
    merge(l,mid,ans);
    merge(mid+1,r,ans);
    int i=l,j=mid+1,k=l;
    while(i<=mid&&j<=r){
        if(a[i]<=a[j])t1[k++]=a[i++];
        else{
            t1[k++]=a[j++];
            ans+=mid-i+1;
        }
    }
    while(i<=mid)t1[k++]=a[i++];
    while(j<=r)t1[k++]=a[j++];
    for(int i=l;i<=r;++i)a[i]=t1[i];
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    while(cin>>n){
        int val;
        cnt1=cnt2=ans1=ans2=0;
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                cin>>val;
                if(val)a[++cnt1]=val;
            }
        merge(1,cnt1,ans1);
        for(int i=1;i<=n;++i)
            for(int j=1;j<=n;++j){
                cin>>val;
                if(val)a[++cnt2]=val;
            }
        merge(1,cnt2,ans2);
        if(ans1%2==ans2%2)cout<<"TAK"<<"\n";
        else cout<<"NIE"<<"\n";
    }
    return 0;
}