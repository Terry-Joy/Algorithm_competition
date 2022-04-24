#include<iostream>
#include<cstdio>
#include<cstring>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int a[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    ll ans=0;
    for(int i=2;i<=n;++i)
        if(a[i]<a[i-1])
            ans+=(a[i-1]-a[i]),a[i]=a[i-1];
    cout<<ans<<endl;
    return 0;
}