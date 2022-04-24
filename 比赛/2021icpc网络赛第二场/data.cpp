#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+10;
int a[maxn],n,m;
int main(){ 
    srand(time(0));
    n=m=100000;
    for(int i=1;i<=n;++i){ 
        a[i]=rand()%n+1;
    }
    cout<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;++i)cout<<a[i]<<" ";
    cout<<"\n";
    for(int i=1;i<=m;++i){ 
        int l=rand()%n+1,r=rand()%n+1;
        if(l>r)swap(l,r);
        cout<<l<<" "<<r<<"\n";
    }
    return 0;
}
