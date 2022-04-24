#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=2e5+5;
bool v[maxn];
int cnt[maxn],n,st[maxn],tail,k,a[maxn];
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>k;
    for(int i=1;i<=n;++i){
        cin>>a[i];cnt[a[i]]++;
    }
    for(int i=1;i<=n;++i){ 
        cnt[a[i]]--;
        if(!v[a[i]]){ 
            v[a[i]]=1;
            while(tail>0&&cnt[st[tail]]&&st[tail]>a[i]){ 
                v[st[tail]]=0;
                tail--;
            }
            st[++tail]=a[i];
        }
    }
    for(int i=tail-k+1;i<=tail;++i){ 
        cout<<st[i]<<" ";
    }
    return 0;
}
