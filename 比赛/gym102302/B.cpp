#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
priority_queue<ll,vector<ll>,greater<ll> >q;
ll a,b;
int main(){
    cin>>a>>b;
    for(ll i=1;i*i<=a;++i){
        if(a%i)continue;
        ll x1=i,x2=a/i;
        if(x1%b==0)q.push(x1);
        if(x2%b==0&&x2!=x1)q.push(x2);
    }
    while(!q.empty()){
        cout<<q.top()<<" ";
        q.pop();
    }
    return 0;
}