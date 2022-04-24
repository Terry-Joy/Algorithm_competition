#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int a1=n/3,a2=n/5,a3=n/7;
        bool flag=0;
        for(int i=0;i<=a1;++i){
            for(int j=0;j<=a2;++j){
                int k=n-3*i-5*j;
                if(k%7==0){
                    cout<<i<<" "<<j<<" "<<k/7<<"\n";
                    flag=1; 
                    break;
                }
            }
            if(flag)break;
        }
        if(!flag)puts("-1");
    }
    return 0;
}