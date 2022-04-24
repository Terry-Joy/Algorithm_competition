#include<bits/stdc++.h>
#define pb push_back
using namespace std;
typedef long long ll;
const int maxn=2005;
int n,t,a[maxn],b[maxn],cnt1=0,cnt2=n;
int main(){
    cin>>t;
    while(t--){
        scanf("%d",&n);
        cnt1=0,cnt2=n;
        for(int i=1;i<=n;++i){
            cin>>a[i];
            if(a[i]&1)b[++cnt1]=a[i];
            else b[cnt2--]=a[i];
        }
        for(int i=1;i<=n;++i)cout<<b[i]<<" ";
        cout<<"\n";
    }
    return 0;
}