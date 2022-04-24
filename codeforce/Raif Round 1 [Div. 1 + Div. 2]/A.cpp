#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int x1,y1,x2,y2;
        cin>>x1>>y1>>x2>>y2;
        if(x1==x2&&y1==y2){ puts("0");continue;}
        else if(x1==x2){ cout<<abs(y1-y2)<<endl;continue;}
        else if(y1==y2){ cout<<abs(x1-x2)<<endl;continue;}
        else cout<<abs(x1-x2)+abs(y1-y2)+2<<endl;
    }
    return 0;
}
