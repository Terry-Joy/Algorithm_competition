#include<bits/stdc++.h>
using namespace std;
unordered_map<int,int>mp;
const int maxn=1e5+5;
int a[maxn],n;
int main(){
    int t;
    cin>>t;
    while(t--){
        mp.clear();
        scanf("%d",&n);
        for(int i=1;i<=n;++i)scanf("%d",&a[i]),mp[a[i]]++;
        if(n&1){
            puts("Second");
        }else{
            bool flag=0;
            for(auto&v:mp){
                if(v.second&1){
                    flag=1;
                }
            }
            if(flag){
                puts("First");
            }else
                puts("Second");
        }
    }
    return 0;
}