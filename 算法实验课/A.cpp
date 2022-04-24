#include<bits/stdc++.h>
using namespace std;
int is(int n){
    int sum=0;
    for(int i=1;i*i<=n;++i){
        if(n%i==0){
            sum+=i;
             if(n/i!=i&&n/i!=n){
            sum+=n/i;
        }
        }
       
    }
    return sum;
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int a,b;
        cin>>a>>b;
        int aa=is(a),bb=is(b);
        if(a!=b&&aa==b&&bb==a)cout<<"YES"<<"\n";
        else cout<<"NO"<<"\n";
    }
    return 0;
}