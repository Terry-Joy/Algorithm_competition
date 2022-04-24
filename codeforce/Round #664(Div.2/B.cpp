#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){ 
    int n,m,s,e;
    cin>>n>>m>>s>>e;
    cout<<s<<" "<<e<<endl;
    for(int j=e-1;j>=1;--j)
        cout<<s<<" "<<j<<endl;
    for(int j=e+1;j<=m;++j)
        cout<<s<<" "<<j<<endl;
    int cnt=0;
    for(int i=s-1;i>=1;--i){ 
        cnt++;
        cnt%=2;
        if(cnt){ 
            for(int j=m;j>=1;--j)
                cout<<i<<" "<<j<<endl;
        }
        else for(int j=1;j<=m;++j)
            cout<<i<<" "<<j<<endl;
    }
    for(int i=s+1;i<=n;++i){ 
        cnt++;
        cnt%=2;
        if(cnt){ 
            for(int j=m;j>=1;--j)
                cout<<i<<" "<<j<<endl;
        }
        else for(int j=1;j<=m;++j)
            cout<<i<<" "<<j<<endl;
    }
    return 0;
}
