#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int t,k,a[maxn],n;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        cout<<n-1<<"\n";
        int pos=min_element(a+1,a+1+n)-a;
        int cnt=1,i=pos-1,j=pos+1;
        while(i>=1){
            cout<<pos<<" "<<i<<" "<<a[pos]<<" "<<a[pos]+cnt<<"\n";
            i--;cnt++;
        }
        cnt=1;
        while(j<=n){
            cout<<pos<<" "<<j<<" "<<a[pos]<<" "<<a[pos]+cnt<<"\n";
            j++;cnt++;
        }

    }
    return 0;
}