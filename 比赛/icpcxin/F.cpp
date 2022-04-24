#include<bits/stdc++.h>

using namespace std;
const int maxn=1e6+10;
int ans,num,a[maxn],x,k,n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i)cin>>a[i],a[i+n]=a[i];
    for(int i=30;i>=0;--i){
        ans|=(1<<i);
        num=x=0;
        for(int j=1;j<=2*n;++j){
            x|=a[j];
            if(ans==(x&ans))x=0,num++;
        }
        if(num<2*k-1)ans^=(1<<i);
    }
    cout<<ans<<"\n";
    return 0;
}