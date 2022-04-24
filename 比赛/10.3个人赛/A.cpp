#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=15000+5;
pair<int,string>mp[maxn];
struct Node{
    string win,lose,time,
    int time,id;
    bool operator<(const Node&a){
        if(a.time==time)return a.id<id;
        return a.time<time;
    }
}wi[maxn];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    string a;
    for(int i=1;i<=n;++i){
        cin>>a;
        mp[i]={n-i+1,a};
    }
    return 0;
}