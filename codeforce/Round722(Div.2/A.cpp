#include<bits/stdc++.h>
using namespace std;
int t,n,a[105];
int main(){
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int mn=*min_element(a+1,a+1+n);
        int ans=0;
        for(int i=1;i<=n;++i)ans+=(a[i]==mn);
        sort(a+1,a+1+n);
        int m=unique(a+1,a+1+n)-(a+1);
        cout<<((m==1)?0:n-ans)<<"\n";
    }
    return 0;
}