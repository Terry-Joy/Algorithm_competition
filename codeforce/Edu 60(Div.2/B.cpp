#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 2e5+5;
ll n,m,k;
ll a[N];
int main()
{
    int n,m,k;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i)
        scanf("%lld",&a[i]);
    sort(a+1,a+1+n);
    ll mx=a[n],mx2=0;
    bool flag=0;
    for(int i=n-1;i;--i)
    {
       if(a[i]==mx){ 
            flag=1;break;
       } 
       else { 
          mx2=a[i];break;
       }
    }
    if(flag)
        cout<<mx*m<<"\n";
    else
    {
       int x=m/(k+1);
       int y=m%(k+1);
       cout<<x*(k*mx+mx2)+y*mx<<"\n"; 
    }
    return 0;
}
