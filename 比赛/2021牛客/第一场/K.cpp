#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int a[maxn],b[maxn],n;
int main(){ 
    int t;
    scanf("%d",&t);
    while(t--){ 
        scanf("%d",&n);
        for(int i=0;i<n;++i)scanf("%d",&a[i]);
        sort(a,a+n);
        for(int i=0;i<n;++i)cout<<a[i]<<" ";
        cout<<"\n";
    }
    return 0;
}
