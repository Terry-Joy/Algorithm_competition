#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll x = 1;
int get(ll a,ll b){    //获取比a小的最大的b的幂次方
    int ans = 0;
    x = 1;
    while(a >= x){
        ans ++;
        x = x * b;
    }
    ans -= 1;
    x /= b;
    return ans;
}
ll a[159];
int main(int argc,char *argv[]){
    ll t, n, k, p = 0,f = 0;
    cin >> t;
    for(ll i = 1;i <= t;i ++){
        map<ll,int> s;
        scanf("%lld%lld",&n,&k);
        f = 0;
        for(int j = 0;j < n;j ++){
            scanf("%lld",&a[j]);
            ll temp = a[j];
            while(temp != 0){
                p = get(temp, k);
                temp -= x;
                s[p] ++;
            }
        }
        int h;
        for(h = 0;h < 64;h ++){
            if(s[h] > 1)break;
        }
        if(h != 64)printf("NO\n");
        else printf("YES\n");
    }
}

