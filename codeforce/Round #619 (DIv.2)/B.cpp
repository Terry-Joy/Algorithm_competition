#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define me(a,x) memset(a,x,sizeof a)
#define pb(a) push_back(a)
#define pa pair<int,int>
#define fi first
#define se second
int a[100005];
int n;
int check(int x)
{
    int mi=0;
    for(int i=0; i<n-1; i++)
    {
        if(a[i]==-1 && a[i+1]!=-1)
            mi=max(mi,abs(x-a[i+1]));
        else if(a[i]!=-1 && a[i+1]==-1)
            mi=max(mi,abs(x-a[i]));
        else if(a[i]!=-1 && a[i+1]!=-1)
            mi=max(mi,abs(a[i+1]-a[i]));

    }
    return mi;

}
int main()
{
    int t;cin>>t;
    while(t--)
    {
        cin>>n;
        int ma=-1;
        for(int i=0; i<n; i++)
        {

            cin>>a[i];
            ma=max(ma,a[i]);
        }
        int l=0,r=ma+1,mid;
        while(l+1<r)
        {
            mid=l+r>>1;
            int w=check(mid),e=check(mid+1);
            if(w<e)
                r=mid;
            else
                l=mid;
        }
        int z=check(l),x=check(r);
        if(z<x) cout<<z<<" "<<l<<endl;
        else cout<<x<<" "<<r<<endl;

    }
    return 0;
}

