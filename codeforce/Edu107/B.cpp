#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
int n,t;
int mypow(int a,int b){
    int ans=1;
    while(b){
        if(b&1)ans=ans*a;
        a=a*a;
        b>>=1;
    }
    return ans;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    int a,b,c;
    while(t--){
        cin>>a>>b>>c;
        cout<<mypow(10,a-1)<<" "<<mypow(10,b-1)+mypow(10,c-1)<<"\n";
    }
    return 0;
}