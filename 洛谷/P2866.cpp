#include<iostream>
#include<cstdio>
#include<queue>
#define ll long long 
using namespace std;
const int maxn=8e4+100;
ll a[maxn];
int main()
{ 
    int n;
    scanf("%d",&n);
    deque<ll>q;
    for(int i=1;i<=n;++i)
    {
       scanf("%lld",&a[i]); 
    }
    q.push_back(a[1]);
    ll ans=0;
    for(int i=2;i<=n;++i)
    {
       while(!q.empty()&&q.back()<=a[i])
          q.pop_back();
       q.push_back(a[i]); 
       ans+=q.size()-1;
    }
    cout<<ans<<endl;
    return 0;
}
