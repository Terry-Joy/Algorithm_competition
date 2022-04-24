#include<bits/stdc++.h>
using namespace std;
using db=double;
const int maxn=1e5+5;
int n;
db w[maxn],g[maxn],c;
int main(){ 
    ios::sync_with_stdio(false);
    cin>>n>>c;
    db sum=0;
    for(int i=1;i<=n;++i)cin>>w[i],sum+=w[i];
    sort(w+1,w+1+n);
    db num=1;
    for(int i=n;i;--i){ 
        g[i]=1-num;
        num*=0.5;
    }
    db ans=c;
    for(int i=1;i<=n;++i){ 
        ans+=w[i]*g[i];
    }
    ans=min(ans,sum);
    printf("%.6f",ans);
    return 0;
}
