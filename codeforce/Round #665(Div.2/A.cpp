#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<string>
#include<queue>
#include<vector>

using namespace std;

int main(){
    int t,n,k;
    cin>>t;
    while(t--){
        scanf("%d%d",&n,&k);
        if(n==k)cout<<0<<endl;
        else if(n<k)cout<<k-n<<endl;
        else cout<<(((n-k)%2)?1:0)<<endl;
    }
    return 0;
}
