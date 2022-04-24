#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e3+5;
int a[maxn];
int main(){
    int t,n,k;
    cin>>t;
    while(t--){ 
        scanf("%d%d",&n,&k);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        sort(a+1,a+1+n);
        int pos,i;
        for(i=n;i;--i){ 
            if(a[i]<k){ pos=i;break;}
        }
        if(!i){ puts("0");continue;}
        int tmp=a[1];
        ll ans=0;
        for(i=pos;i>=2;--i){ 
            ans+=(k-a[i])/tmp;
        }
        cout<<ans<<endl;
    }
    return 0;
}
