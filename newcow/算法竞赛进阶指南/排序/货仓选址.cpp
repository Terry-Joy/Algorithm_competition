#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
ll ans=0;
int a[maxn],n;
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int pos=((n&1)?a[(n+1)/2]:a[n/2]);
    for(int i=1;i<=n;++i){
        ans+=1ll*abs(pos-a[i]);
    }
    cout<<ans<<endl;
    return 0;
}