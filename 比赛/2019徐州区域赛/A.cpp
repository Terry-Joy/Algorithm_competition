#include <iostream>

using namespace std;
typedef long long ll;
ll solve(ll l,ll r,ll s){
    ll p=r-l+1;
    if(p<5){
        if(p==1){
            if(l<=s) return 1;
            else return 0;
        }else if(p==2){
            if( (l^r)<=s) return 2;
            else if(l<=s) return 1;
            else return 0;
        }else if(p==3){
            ll t=l^(l+1)^r;
            if(t<=s) return 3;
            else if( (l^(l+1))<=s || (r^(l+1))<=s) return 2;
            else if(l<=s) return 1;
            else return 0;
        }else if(p==4){
            ll t=l^(l+1)^(l+2)^r;
            if(t<=s) return 4;
            else if( (t^r)<=s || (t^l)<=s) return 3;
            else if( (l^(l+1))<=s || ((l+1)^(l+2))<=s || ((l+2)^r)<=s) return 2;
            else if(l<=s) return 1;
            else return 0;
        }
    }else{
        ll d=p/4;
        if( (l&1) && !(r&1)){
            if(p%4){
                ll q=4*d;
                if( (l^r)<=s) return q+2;
                else if(l<=s) return q+1;
                else return q;
            }else{
                d--; ///这个有可能会漏
                ll q=4*d;
                if( (l^1^r)<=s) return q+4;
                else if( (l^1)<=s || (1^r)<=s) return q+3;
                else if(1<=s) return q+2;
                else if(l<=s) return q+1;
                else return q;
            }
        }else if( (l&1) && (r&1) ){
            ll t=p%4;
            ll q=4*d;
            if(t==1){
                if(l<=s) return q+1;
                else return q;
            }else if(t==3){
                if((l^1)<=s) return q+3;
                if(1<=s) return q+2;
                else if(l<=s) return q+1;
                else return q;
            }
        }else if( !(l&1) && (r&1) ){
            ll t=p%4;
            ll q=4*d;
            if(t){
                if(1<=s) return q+2;
                else return q;
            }else{
                return q;
            }
        }else if( !(l&1) && !(r&1) ){
            ll t=p%4;
            ll q=4*d;
            if(t==1){
                if(r<=s) return q+1;
                else return q;
            }else if(t==3){
                if((1^r)<=s) return q+3;
                else if(1<=s) return q+2;
                else return q;
            }
        }
    }
}
int main(){
    ll T,l,r,s;
    scanf("%lld",&T);
    while(T--){
        scanf("%lld%lld%lld",&l,&r,&s);
        ll ans=solve(l,r,s);
        if(!ans) printf("-1\n");
        else printf("%lld\n",ans);
    }
    return 0;
}
