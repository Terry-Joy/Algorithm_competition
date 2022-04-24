#include<bits/stdc++.h>
#define lson p<<1,l,mid
#define rson p<<1|1,mid+1,r
#define ls p<<1
#define rs p<<1|1
#define pb push_back
using namespace std;
typedef long long ll;
int t,n,q,l,r;
int main(){
    ios::sync_with_stdio(false);cin.tie(0); 
    cin>>t;
    while(t--){ 
        string s;
        cin>>n>>q;
        cin>>s;
        while(q--){ 
            bool flag=0;
            cin>>l>>r;
            l--;r--;
            for(int i=0;i<l;++i){ 
                if(s[i]==s[l])flag=1;
            }
            for(int i=r+1;i<n;++i){ 
                if(s[i]==s[r])flag=1;
            }
            if(flag)cout<<"YES"<<"\n";
            else cout<<"NO"<<"\n";
        }
    }
    return 0;
}
