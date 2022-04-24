#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn];
vector<int>G;
int main(){ 
    int t,n;
    cin>>t;
    while(t--)
    {
        G.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]);
        for(int i=1;i<=n;++i){ 
            if(i==1||i==n)G.push_back(a[i]);
            else if((a[i]>a[i-1]&&a[i]>a[i+1])||(a[i]<a[i-1]&&a[i]<a[i+1]))G.push_back(a[i]);
        }
        cout<<G.size()<<endl;
        for(auto&v:G)
            printf("%d ",v);
        puts("");
    }
    return 0;
}
