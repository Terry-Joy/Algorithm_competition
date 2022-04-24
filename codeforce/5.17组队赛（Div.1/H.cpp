#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=1e5+5;
map<string,int>mp;
int a[N],c[N];
int lowbit(int x)
{
    return x&(-x);
}

void add(int x)
{
    for(int i=x;i<N;i+=lowbit(i))
        c[i]++;
}
int ask(int x)
{
    int ans=0;
    for(int i=x;i;i-=lowbit(i))
        ans+=c[i];
    return ans;
}
int main()
{
    int n;
    while(~scanf("%d",&n)&&n)
    {
        mp.clear();
        memset(c,0,sizeof(c));
        int num=0;
        string s;
        for(int i=1;i<=n;i++)
            cin>>s,mp[s]=++num;
        for(int i=1;i<=n;i++)
            cin>>s,a[i]=mp[s];
        ll ans=0;
        for(int i=n;i>=1;i--)
        {
            ans+=(ll)ask(a[i]);
            add(a[i]);
        }
        printf("%lld\n",ans);
    }
    return 0;
}

