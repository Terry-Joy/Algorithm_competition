#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct Node{ 
    ll cost,now,time;
    bool operator<(const Node&a)const{ 
        return cost<a.cost;
    }
};
priority_queue<Node>q;
ll g(ll a,ll b){ 
    ll tmp=a/b,tmp2=a%b;
    return (tmp2*(tmp+1)*(tmp+1)+tmp*tmp*(b-tmp2));
}
int main(){ 
    ios::sync_with_stdio(false);
    int n,k;
    cin>>n>>k;
    ll a,ans=0;
    for(int i=1;i<=n;++i){ 
        cin>>a;
        ans+=a*a;
        q.push({g(a,1)-g(a,2),a,2});
    }
    for(int i=1;i<=k-n;++i){ 
        Node f=q.top();q.pop();
        ll x1=f.cost,x2=f.now,x3=f.time;
        ans-=x1;
        q.push({g(x2,x3)-g(x2,x3+1),x2,x3+1});
    }
    cout<<ans<<endl;
    return 0;
}
