#include<bits/stdc++.h>
using namespace std;
#define fi first 
#define se second
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
namespace pollard_rho {
    const int C=2307;
    const int S=10;
    typedef pair<ll,int> pli;
    mt19937 rd(time(0));
    vector<ll>ve;
    ll gcd(ll a,ll b){return b?gcd(b,a%b):a;}
    ll mul(ll a,ll b,ll mod){return (__int128)a*b%mod;}
    //miller_rabin klogn
    //考虑O(1)快速乘
    ll power(ll a,ll b,ll mod){
        ll res=1;a%=mod;
        while(b){
            if(b&1)res=mul(res,a,mod);
            a=mul(a,a,mod);
            b>>=1;
        }
        return res;
    }
    bool check(ll a,ll n){
        ll m=n-1,x,y;
        int j=0;
        while(!(m&1))m>>=1,j++;
        x=power(a,m,n);
        for(int i=1;i<=j;x=y,i++){
            y=mul(x,x,n);
            if(y==1&&x!=1&&x!=n-1)return 1;
        }
        return y!=1;
    }
    bool miller_rabin(ll n){
        ll a;
        if(n==1)return 0;
        if(n==2)return 1;
        if(!(n&1))return 0;
        for(int i=0;i<S;i++)if(check(rd()%(n-1)+1,n))return 0;
        return 1;
    }
    ll pollard_rho(ll n,int c){
        ll i=1,k=2,x=rd()%n,y=x,d;
        while(1){
            i++;x=(mul(x,x,n)+c)%n,d=gcd(y-x,n);
            if(d>1&&d<n)return d;
            if(y==x)return n;
            if(i==k)y=x,k<<=1;
        }
    }
    void findfac(ll n,int c){
        if(n==1)return ;
        if(miller_rabin(n)){
            ve.push_back(n);
            return ;
        }
        ll m=n;
        while(m==n)m=pollard_rho(n,c--);
        findfac(m,c);
        findfac(n/m,c);
    }
    vector<pli> solve(ll n){
        vector<pli>res;
        ve.clear();
        findfac(n,C);
        sort(ve.begin(),ve.end());
        for(auto x:ve){
            if(res.empty()||res.back().fi!=x)res.push_back({x,1});
            else res.back().se++;
        }
        return res;
    }
}
using namespace pollard_rho;
int main(){ 
    return 0;
}
