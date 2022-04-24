#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char a[]={ 'c','b','a'};
int main(){ 
    int t,n,k;
    cin>>t;
    while(t--){ 
        cin>>n>>k;
        for(int i=1;i<=k;++i)
            cout<<"a";
        int cnt=0;
        for(int i=k+1;i<=n;++i){ 
            cout<<a[cnt];
            cnt++;if(cnt==3)cnt=0;
        }
        cout<<"\n";
    } 
    return 0;
}
