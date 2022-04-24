#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int t,n,ans;
int main(){ 
    cin>>t;
        while(t--){ 
            int n;
            scanf("%d",&n);
            ans=0x3f3f3f3f;
            int k1=sqrt(n),k2=sqrt(n+0.5);
            cout<<min(ceil(1.0*n/k1)+k1,ceil(1.0*n/k2)+k2)-2<<endl;
        }
    return 0;
}
