#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        int n,s,t,h;
        scanf("%d%d%d%d",&n,&s,&t,&h);
        for(int i=1;i<=n-1;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n-1;++i)scanf("%d",&b[i]);
        a[n]=1;a[n+1]=h;
        b[n]=1;b[n+1]=h;
        n++;s++;t++;
        sort(a+1,a+1+n);
        sort(b+1,b+1+n);
        ll sum1=0,sum2=0;
        for(int i=t+1;i<=n-s;++i)sum1+=a[i],sum2+=b[i];
        ll ans=2e18;
        ll del=sum1-sum2+a[t]-1;//1 [t,n-s+1]
        if(del>=b[t]){ 
            ll x=min(del,(ll)b[n-s+1]);
            ans=min(ans,1-x);
        }

        del=sum2-sum1+b[n-s+1]+1;
        if(del<=a[n-s+1]){ 
            ll x=max(1ll*a[t],del);
            ans=min(ans,x-h);
        }
        if(a[t]-b[n-s+1]>=sum2-sum1+1) //[1,h]
            ans=min(ans,1ll-h);

        if(a[n-s+1]-b[t]>=sum2-sum1+1)//[t,n-s+1],[t,n-s+1]
            ans=min(ans,max(sum2-sum1+1,1ll*a[t]-b[n-s+1]));
        if(ans==2e18){ 
            puts("IMPOSSIBLE");
        }else
            cout<<ans<<"\n";
    }
    return 0;
}
