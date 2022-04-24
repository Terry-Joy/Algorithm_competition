#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int a[maxn],b[maxn];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)scanf("%d",&a[i]);
    for(int i=1;i<=n;++i)scanf("%d",&b[i]);
    reverse(b+1,b+1+n);
    int h1=n,q1=1,mx=-1;
    for(int i=1;i<=n;++i){
        if(a[i]==b[i]){
            mx=a[i];
            h1=i;
            while(a[i]==b[i])i++;
            q1=i-1;
        }
    }
    for(int i=1;i<=n;++i){
        if(a[i]!=mx&&b[i]!=mx&&h1<=q1){
            swap(b[i],b[h1]);
            h1++;
        }
    }
    if(h1<=q1){puts("No");return 0;}
    else {
        puts("Yes");
        for(int i=1;i<n;++i)printf("%d ",b[i]);
        cout<<b[n]<<endl;
    }
    return 0;
}