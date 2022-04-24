#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){
    int n,cnt=0;
    scanf("%d",&n);
    for(int i=1;i<=n-1;++i){
        for(int j=1;j<=n-1;++j){
            if(i*j<n)cnt++;
            else break;
       }
    }
    cout<<cnt<<endl;
}