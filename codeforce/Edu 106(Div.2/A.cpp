#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,t;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int n,k1,k2,w,b;
    while(t--){
        cin>>n>>k1>>k2>>w>>b;
         if((k1+k2)>=2*w&&2*n-(k1+k2)>=2*b)cout<<"YES"<<"\n";
          else cout<<"NO"<<"\n";
    }
    return 0;
}