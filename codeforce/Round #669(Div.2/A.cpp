#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[1010];
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int n,cnt1=0,cnt0=0;
        cin>>n;
        for(int i=1;i<=n;++i){ 
        scanf("%d",&a[i]);
        if(a[i]==1)cnt1++;
        else cnt0++;
        }
        if(cnt1>cnt0){ 
            if(cnt1&1)cnt1--;
            cout<<cnt1<<endl;
            for(int i=1;i<=cnt1;++i)
                cout<<1<<" ";
            cout<<endl;
        }
        else { 
            cout<<n/2<<endl;
            for(int i=1;i<=n/2;++i)
                cout<<0<<" ";
           cout<<endl; 
        }
    }
    return 0;
}
