#include<iostream>

using namespace std;
int gcd(int a,int b){return b?gcd(b,a%b):a;}
const int maxn=1e5+5;
int a[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    int sum=a[1];
    for(int i=1;i<=n;++i)
        sum=gcd(sum,a[i]);
    cout<<sum<<"\n";
    return 0;
}