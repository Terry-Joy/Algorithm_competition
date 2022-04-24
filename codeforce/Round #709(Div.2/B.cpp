#include <bits/stdc++.h>
#define fi first
#define se second
#define pb push_back
const int maxn = 1e5 +5;
using namespace std;
int a[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int maxx=0;
        for(int i=1 ; i<=n ; i++) cin>>a[i],maxx=max(maxx,a[i]);
        if(n==1||n==2){
            puts("0");
            continue;
        }
        bool flag1=true;
        int v=a[2]-a[1];
        int c,m;
        for(int i=1 ; i<n ; i++)
        {
            if(a[i+1]-a[i]!=v) flag1=false;
            if(a[i+1]>=a[i]) c=a[i+1]-a[i];
        }
        for(int i=1 ; i<n ; i++)
            if(a[i]>a[i+1]) m=a[i]+c-a[i+1];
        if(flag1) {
            puts("0");
            continue;
        }
        bool flag2=true;
        for(int i=1 ; i<n ; i++)
        {
            if(a[i]<=a[i+1]&&c!=a[i+1]-a[i]) flag2=false;
            if(a[i]>=a[i+1]&&m!=a[i]+c-a[i+1]) flag2=false;
        }
        if(!flag2) cout<<"-1"<<endl;
        else {
            if(m>c&&m>maxx) cout<<m<<" "<<c<<endl;
            else puts("-1");
        }
    }
    return 0;
}
