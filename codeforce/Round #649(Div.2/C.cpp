#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
typedef long long ll;
const int maxn=1e6+5;
int a[maxn],b[maxn];
bool v[maxn];
vector<int>ans;
int main(){ 
    int n;
    cin>>n;
    for(int i=1;i<=n;++i) 
        scanf("%d",&a[i]),v[a[i]]=1;
    for(int i=0;i<=1000000;++i)
        if(!v[i])ans.push_back(i);
    int id=0;
    for(int i=1;i<=n;++i){
        if(i==1||a[i]==a[i-1])
            b[i]=ans[id++];
        else b[i]=a[i-1];
    }
    for(int i=1;i<=n;++i)
        printf("%d ",b[i]);
    return 0;
}
