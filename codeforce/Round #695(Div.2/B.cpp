#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int t,n,pos[maxn],cnt=0,a[maxn];
int is(int i){
    if(a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1])return 1;
        return 0;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int sum=0,mx=0;
        a[0]=a[1],a[n+1]=a[n];
        for(int i=2;i<n;++i){ 
            if(is(i)){ 
               sum++;
               int now=a[i];
               int x1=is(i-1)+is(i)+is(i+1);
               a[i]=a[i+1];
               int x2=is(i-1)+is(i)+is(i+1);
               a[i]=a[i-1];
               int x3=is(i-1)+is(i)+is(i+1);
               a[i]=now;
               mx=max(mx,x1-min(x2,x3));
            }
        }
        cout<<sum-mx<<"\n";
    }
    return 0;
}
