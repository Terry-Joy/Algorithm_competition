#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
typedef long long ll;
int n,m,k,q1[maxn],a[maxn],q2[maxn],h1,t1,h2,t2;
int main(){
    scanf("%d%d",&n,&m);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    while(m--){ 
        scanf("%d",&k);
        h1=h2=1,t1=t2=0;
        ll ans=(ll)(n+1)*n/2,sum=0;
        int l=1;
        for(int i=1;i<=n;++i){ 
            while(h1<=t1&&a[q1[t1]]<=a[i])t1--;
            while(h2<=t2&&a[q2[t2]]>=a[i])t2--;
            q1[++t1]=i;
            q2[++t2]=i;
            while(h1<=t1&&h2<=t2&&a[q1[h1]]-a[q2[h2]]>k){ 
                while(q1[h1]<=l)h1++;
                while(q2[h2]<=l)h2++;
                l++;
            }
            sum+=i-l+1;
        }
        cout<<ans-sum<<"\n";
    } 
    return 0;
}
