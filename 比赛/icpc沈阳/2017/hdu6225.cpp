#include<bits/stdc++.h>

using namespace std;
typedef unsigned long long ull;
int main(){
    int t;
    ull a,b,c,d;
    cin>>t;
    while(t--){
        ull ans=0;
        cin>>a>>b>>c>>d;
        if(a==4611686018427387904&&b==4611686018427387904&&c==4611686018427387904&&d==4611686018427387904)
        {
            puts("18446744073709551616");
            continue;
        }
        ans=(a+b+c+d);
        cout<<ans<<"\n";
    }
    return 0;
}