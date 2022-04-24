#include<bits/stdc++.h>
#define fi first 
#define se second 
using namespace std;
typedef pair<int,int>P;
const int maxn=4e5+5;
int n,a[maxn],b[maxn],cnt[maxn];
int main(){
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]),b[i]=a[i];
    sort(b+1,b+1+n);
    int m=unique(b+1,b+1+n)-(b+1);
    for(int i=1;i<=n;++i)a[i]=lower_bound(b+1,b+1+m,a[i])-b;
    for(int i=1;i<=n;++i)cnt[a[i]]++;
    for(int i=1;i*i<=n;++i){
        int sum=0;
        for(int j=1;)
    }
    return 0;
}