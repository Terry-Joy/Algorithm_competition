#include<bits/stdc++.h>

using namespace std;
int n;
int main(){ 
    int l=0,r=0,t=0,b=0,x=0,y=0,d=0,dis=0;
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(int i=1;i<=n;++i){ 
        cin>>dis>>dis;
        if(!d){ cout<<(r+1)-x<<" ";x=r+1;}
        else if(d==1){ cout<<(t+1)-y<<" ";y=t+1;}
        else if(d==2){ cout<<x-(l-1)<<" ";x=l-1;}
        else if(d==3){ cout<<y-(b-1)<<" ";y=b-1;}
        r=max(r,x);l=min(l,x);
        t=max(t,y);b=min(b,y);
        d=(d+dis+4)%4;
    }
    return 0;
}
