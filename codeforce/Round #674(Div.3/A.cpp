#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){ 
    int t,n,x;
    cin>>t;
    while(t--){ 
        cin>>n>>x;
        if(n==1||n==2){ 
            puts("1");
            continue;
        }
        for(int i=1;i<=n+100;++i){
            if(n>=3+(i-1)*x&&n<=2+i*x)
            { 
                cout<<i+1<<endl;
                break;
            }
        }
    }
    return 0;
}
