#include<bits/stdc++.h>
using namespace std;
int t,n,a[]={ 0,7,27,41,49,63,78,108};
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--){ 
        cin>>n;
        int sum=0,x;
        for(int i=1;i<=n;++i){ 
            cin>>x;
            sum+=a[x];
        }
        if(sum>=120)sum-=50;
        else if(sum>=89)sum-=30;
        else if(sum>=69)sum-=15;
        cout<<sum<<"\n";
    }
    return 0;
}
