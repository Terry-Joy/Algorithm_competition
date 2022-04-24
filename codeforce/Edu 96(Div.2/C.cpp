
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
priority_queue<int>q;
signed main(){
    int t,n;
    cin>>t;
    while(t--){
        cin>>n;
        cout<<2<<endl;
        for(int i=1;i<=n;++i)q.push(i);
        while(q.size()>1){
            int a1=q.top();q.pop();
            int a2=q.top();q.pop();
            cout<<a1<<" "<<a2<<endl;
            int t3=ceil((a1*1.0+a2*1.0)/2);
            q.push(t3);
        }
    }
    return 0;
}