#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t,n;
int main(){
    cin>>t;
    ll a,b;
    while(t--){
        cin>>a>>b;
        if(b==1){puts("NO");continue;}
        else if(b==2){
            puts("YES");
            cout<<a<<" "<<3*a<<" "<<2*a*b<<"\n";
        }else{
            puts("YES");
            cout<<(b-1)*a<<" "<<a<<" "<<b*a<<"\n";
        }
    }
    return 0;
}