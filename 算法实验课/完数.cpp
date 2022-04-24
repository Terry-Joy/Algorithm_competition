#include<bits/stdc++.h>
using namespace std;
bool is(int x){
    int sum=0;
    for(int i=1;i<=x/2;++i){
        if(x%i==0)sum+=i;
    }
    return sum==x;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int ans=0;
        for(int i=a;i<=b;++i){
            ans+=is(i);
        }
        cout<<ans<<"\n";
    }
    return 0;
}