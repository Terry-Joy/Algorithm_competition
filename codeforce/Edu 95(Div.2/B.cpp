#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[120],id[120],b[120],m;
int main(){
    int t;
    cin>>t;
    while(t--){ 
        int n;
        m=0;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)
            scanf("%d",&a[i]);
        for(int i=1;i<=n;++i){ 
            scanf("%d",&id[i]);
            if(id[i]==0)b[++m]=a[i];
        }
        int k=0;
        sort(b+1,b+1+m);
        reverse(b+1,b+1+m);
        for(int i=1;i<=n;++i)
            if(id[i]==1)cout<<a[i]<<" ";
            else cout<<b[++k]<<" ";
        puts("");
    }
    return 0;
}
