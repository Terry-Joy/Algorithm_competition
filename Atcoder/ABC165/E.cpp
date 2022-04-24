#include<iostream>
#include<cstdio>
#include<cstring>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=3e5+5;
map<pair<int,int>,bool>mp;
vector<int>a,b;
typedef long long ll;
int r[maxn],c[maxn];
int main(){
    int h,w,n,x,y,mxr,mxc;
    scanf("%d%d%d",&h,&w,&n);
    mxr=mxc=0;
    while(n--){
        scanf("%d%d",&x,&y);
        mp[{x,y}]=1;
        r[x]++;
        c[y]++;
        mxr=max(mxr,r[x]);
        mxc=max(mxc,c[y]);
    }
    for(int i=1;i<=h;++i)
        if(r[i]==mxr)a.push_back(i);
    for(int j=1;j<=w;++j)
        if(c[j]==mxc)b.push_back(j);
    for(auto&v:a)
        for(auto&q:b){
            if(mp[{v,q}]==0){
                cout<<mxr+mxc<<endl;
                return 0;
            }
        }
    cout<<mxr+mxc-1<<endl;
    return 0;
}