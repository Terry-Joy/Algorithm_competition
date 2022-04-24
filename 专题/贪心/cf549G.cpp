#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
int a[maxn];
bool flag=0;
unordered_map<int,int>v;
int main(){ 
    int n,x;
    scanf("%d",&n);
    v.clear();
    for(int i=1;i<=n;++i){ 
        scanf("%d",&x);
        a[i]=x+i;
        if(!v[x+i])v[x+i]=1;
        else flag=1;
    }
    if(flag)puts(":(");
    else{
        sort(a+1,a+1+n);
        for(int i=1;i<n;++i)printf("%d ",a[i]-i);
        printf("%d\n",a[n]-n);
    }
    return 0;
}
