#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int n,a[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    reverse(a+1,a+1+n);
    int ans=-1,pos=1;
    for(int i=4;i<=n-3;++i){
        int a4=a[i]+a[i+1]+a[i+2]+a[i+3],a3=a[i-1],pos=i-2;
        while(a[pos]+a3<a4){
            pos--;
        }
        if(pos==1)pos++;
        if(a[pos]+a3>=a4)continue;
        int l=1,r=pos-1;
        while(l<r){
            int mid=l+r>>1;
            if(a[mid]>=a[pos]+a3)l=mid+1;
            else r=mid;
        }
        if(r>=i-2)continue;
        if(a[r]<a[pos]+a3)ans=max(ans,a[r]+a[pos]+a3+a4);
    }
    if(ans==-1)puts("-1");
    else cout<<ans<<"\n";
    return 0;
}