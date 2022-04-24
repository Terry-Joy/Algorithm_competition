#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
struct Node{
    ll num;
    int sum;
    bool operator<(const Node&a)const{ 
        return sum>a.sum;
    }
}node[1010];
ll d[65];
int main(){
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
        scanf("%lld%d",&node[i].num,&node[i].sum);
    sort(node+1,node+1+n);
    int ans=0;
    for(int i=1;i<=n;++i){
        for(int j=63;j>=0;--j){
            if(node[i].num&(1ll<<j)){
                if(d[j])node[i].num^=d[j];
                else{
                    d[j]=node[i].num;
                    break;
                }
            }
        }
        if(node[i].num)ans+=node[i].sum;
    }
    cout<<ans<<endl;
    return 0;
}