#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main(){
    int n,x,y;
    cin>>n;
    for(int i=1;i<=n;++i){
        scanf("%d%d",&x,&y);
        a[i]=x+y;b[i]=x-y;
    }
    sort(a+1,a+1+n);
    sort(b+1,b+1+n);
    cout<<max(a[n]-a[1],b[n]-b[1])<<endl;
    return 0;
}