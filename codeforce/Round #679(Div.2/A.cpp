#include<bits/stdc++.h>

using namespace std;
int a[110],b[110];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int t,n;
    cin>>t;
    while(t--){ 
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        int l=1,r=n;
        while(l<r){ 
           b[l]=a[r];
           b[r]=-a[l]; 
           l++;r--; 
        }
        for(int i=1;i<=n;++i)
            cout<<b[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
