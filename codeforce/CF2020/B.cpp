#include<bits/stdc++.h>

using namespace std;
int a[105];
int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        cin>>n>>k;
        for(int i=1;i<=n;++i)cin>>a[i];
        int cnt=0;
        for(int i=2;i<=n;++i){
            if(a[i]!=a[i-1])cnt++;
        }
        if(k==1){
            if(cnt)puts("-1");
            else puts("1");
            continue;
        }
        cout<<max(1,(cnt+k-2)/(k-1))<<"\n";
    }
    return 0;
}