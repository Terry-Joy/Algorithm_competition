#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn],b[maxn];
int main(){ 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int k=n/2;//偶数一半 奇数一半少一个
    int cnt=2;
    for(int i=1;i<=k;++i){ 
        b[cnt]=a[i];
        cnt+=2;
        if(cnt>n)break;
    }
    cnt=1;
    for(int i=k+1;i<=n;++i){ 
        while(b[cnt])cnt++;
        b[cnt]=a[i];
    }
    int mx=0;
    for(int i=2;i<n;++i){
        if(b[i]<b[i-1]&&b[i]<b[i+1])
            mx++;
    }
    cout<<mx<<endl;
    for(int i=1;i<=n;++i)
        printf("%d ",b[i]);
    return 0;
}
