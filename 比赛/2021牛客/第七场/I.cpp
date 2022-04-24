#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[100],b[100];
int main(){
   int  x,s;
    cin>>x>>s;
    int tot1=0,tot2=0;
    ll ans=1;
    while(x){ 
        a[tot1++]=x&1;
        x/=2;
    }
    while(s){ 
        b[tot2++]=s&1;
        s/=2;
    }
    for(int i=0;i<=max(tot1-1,tot2-1);++i){ 
        if(!a[i]&&!b[i])continue;
        else if(a[i]==1&&!b[i]){ 
            cout<<0;
            return 0;
        }else if(a[i]==1&&b[i]==1){ 
            ans*=2;
        }else if(!a[i]&&b[i]==1)continue;

    }
    if(x==s)ans--;
    cout<<ans;
    return 0;
}
