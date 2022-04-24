#include<bits/stdc++.h>
using namespace std;
const int maxn=520;
const double esp=1e-5;
int d[maxn],n,m,cnt=0,sum=0;
struct Node{
    double a[maxn];
    int cost;
    bool operator<(const Node&a)const{
        return cost<a.cost;
    }
}node[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j)
            cin>>node[i].a[j];
    }
    for(int i=1;i<=n;++i)
        cin>>node[i].cost;
    sort(node+1,node+1+n);
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(fabs(node[i].a[j])>esp){
                if(!d[j]){
                   d[j]=i;++cnt;sum+=node[i].cost;
                   break;
                }else{
                    double t=node[i].a[j]/node[d[j]].a[j];
                    for(int k=j;k<=m;++k)
                        node[i].a[k]-=t*node[d[j]].a[k];
                }
            }
        }
    }
    cout<<cnt<<" "<<sum<<endl;
    return 0;
}