#include<bits/stdc++.h>
using namespace std;
int main(){ 
    int n=40;
    for(int i=0;i<n;++i){ 
        for(int j=0;j<n;++j){ 
            if((i^j)>i){ 
                cout<<i<<" "<<j<<" "<<(i^j)<<"\n";
            }
        }
    }
    return 0;
}
