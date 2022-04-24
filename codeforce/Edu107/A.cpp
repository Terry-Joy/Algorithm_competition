#include<bits/stdc++.h>
#define pb push_back 
#define fi first  
#define se second
using namespace std;
int n,t,a[100];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){
        cin>>n;
        int ans=0;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(a[i]==1||a[i]==3)ans++;
        }
        cout<<ans<<"\n";
    }
    return 0;
}