#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int b[maxn];
int main(){ 
    int n,k;
    cin>>n>>k;
    for(int i=2;i<=n;++i){ 
        cout<<"and "<<1<<" "<<i<<endl;
        cin>>b[i];
    }
    for(int i=2;i<=n;++i){ 
        cout<<"or "<<1<<" "<<i<<endl;
        int x;
        cin>>x;
        b[i]+=x;
    }
    cout<<"and "<<2<<" "<<3<<endl;
    int a=0,x=0;
    cin>>a;
    cout<<"or "<<2<<" "<<3<<endl;
    cin>>x;
    a=a+x;
    b[1]=(b[2]-a+b[3])/2;
    for(int i=2;i<=n;++i)b[i]-=b[1];
    sort(b+1,b+1+n);
    cout<<"finish "<<b[k]<<endl;
    return 0;
}
