#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int c,d;
        cin>>c>>d;
        if(!c&&!d)cout<<0<<"\n";
        else if((d-c)&1)cout<<-1<<"\n";
        else if(d==c)cout<<1<<"\n";
        else cout<<2<<"\n";
    }
    return 0;
}
