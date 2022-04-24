#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int n,a[maxn],ans[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int r=n,l=1,now=n;
    ans[now]=a[r--],now--;
    ans[now]=a[l++],now--;
    for(int i=1;i;++i){
        if(i&1)ans[now--]=a[r--];
        else ans[now--]=a[l++];
        if(l>r)break;
    }
    for(int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    return 0;
}