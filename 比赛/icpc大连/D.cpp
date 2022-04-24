#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
ll gcd(ll a,ll b){ return b?gcd(b,a%b):a;}
int main(){ 
    ll a,b;
    while(~scanf("%lld%lld",&a,&b)){ 
        ll c=gcd(a,b);
        ll d=a*a-4*c*b;
        if(d<0){ 
            puts("No Solution");
            continue;
        }         
        double a1=(a-sqrt(d))/2;
        double a2=(a+sqrt(d))/2;
        if(a1==round(a1)&&a2==round(a2))
            printf("%.0f %.0f\n",a1,a2);
        else
            puts("No Solution");
    }
    return 0;
}
