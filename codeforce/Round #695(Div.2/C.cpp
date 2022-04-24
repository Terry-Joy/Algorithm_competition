#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=3e5+5;
int mx1=1e9,mx2=1e9;
int a[maxn];
ll sum=0;
int main(){ 
    ios::sync_with_stdio(false);    
    cin.tie(0);
    int n1,n2,n3;
    cin>>n1>>n2>>n3;

    for(int i=1;i<=n1+n2+n3;++i){ 
        cin>>a[i];
        sum+=a[i];
    }
    sort(a+1,a+1+n1+n2+n3);
    if(n1==1&&n2==1&&n3==1){ 
        cout<<sum-2*a[1]<<"\n";
    }
    else if(n1+n2+n3<=4){ 
        cout<<sum-2*a[1]<<"\n";
    }
    else{ 
        cout<<sum-2*(a[1]+a[2])<<"\n";
    }
    return 0;
}
