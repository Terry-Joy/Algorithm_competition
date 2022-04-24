#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=105;
int a[maxn],b[maxn],c[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=1;i<=n;++i)cin>>a[i];
        for(int i=1;i<=n;++i)cin>>b[i];
        for(int i=1;i<=n;++i)cin>>c[i];
        int last=a[1];
        cout<<last<<" ";
        for(int i=2;i<=n-1;++i){
            if(a[i]!=last)cout<<a[i]<<" ",last=a[i];
            else if(b[i]!=last)cout<<b[i]<<" ",last=b[i]; 
            else if(c[i]!=last)cout<<c[i]<<" ",last=c[i];
        }
        if(a[n]!=a[1]&&a[n]!=last)cout<<a[n]<<" ";
        else if(b[n]!=a[1]&&b[n]!=last)cout<<b[n]<<" ";
        else if(c[n]!=a[1]&&c[n]!=last)cout<<c[n]<<" ";
        puts("");
    }
    return 0;
}