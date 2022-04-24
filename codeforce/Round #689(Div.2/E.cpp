#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
unordered_map<ll,bool>mp;
ll k,l,r,t,x,y;
string cal(ll k,ll r,ll x,ll y,ll t){ 
    ll times=0,tmp=0;
    if(x>y){ 
        if(k<x&&k+y>r)tmp=0;
        else if(k+y>r){ 
            if((k+y-r)%x==0)tmp=(k+y-r)/x;
            else tmp=(k+y-r)/x+1;
            if(k-tmp*x<0)times=k/x;
            else times=(k-tmp*x)/(x-y)+tmp;
        }
        else times=k/(x-y);
        return ((times>=t)?"Yes":"No");//
    }else{ 
        ll f=k-(k/x)*x;
        mp[f]=1;
        t-=k/x;
        k-=(k/x)*x;
        while(t>0){// 
            if(k+y>r)return "No";
            t-=(k+y)/x;
            k=(k+y)%x;
            if(mp[k])return "Yes";
            mp[k]=1;
        }
    }
    return "Yes";
}
int main(){ 
    cin>>k>>l>>r>>t>>x>>y;
    cout<<cal(k-l,r-l,x,y,t);
    return 0;
}
