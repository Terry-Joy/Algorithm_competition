#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n=1000,m=10000;
    cout<<n<<" "<<m<<"\n";
    for(int i=1;i<=n;++i){ 
        int x=rand()%n+1;
        cout<<x<<" ";
    }
    cout<<"\n";
    srand(time(0));
    for(int i=1;i<=m;++i){ 
        int l=rand()%n+1,r=rand()%n+1;
        if(l>r)swap(l,r);
        int f=min(l,n+1-r);
        int k=rand()%f+1;
        cout<<l<<" "<<r<<" "<<f<<"\n";
    }
}
