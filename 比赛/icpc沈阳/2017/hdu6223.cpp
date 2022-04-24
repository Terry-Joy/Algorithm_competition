#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=150000;
int main()
{
    int T, kase=0;
    for(ll i=0;i<maxn;++i){
        int cnt=0;
        ll j=(i*i+1)%maxn;
        cnt++;
        while(j!=i){
            j=(j*j+1)%maxn;
            cnt++;
        }
        cout<<cnt<<"\n";
    }
    return 0;
}