#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int a[maxn];
int main()
{
    int n;
    scanf("%d",&n);
    int mx=-1;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]),mx=max(mx,a[i]);
    int ans=0;
    int len=0;
    for(int i=1;i<=n;++i)
    {
        if(a[i]==mx){    
            ++len;
            ans=max(ans,len);
        }
        else len=0;
    }
    cout<<ans;
    return 0;
}
