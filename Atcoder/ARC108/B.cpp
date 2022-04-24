#include<bits/stdc++.h>

using namespace std;
const int maxn=2e5+5;
char s[maxn],ans[maxn];
int sum=0,now=0;
typedef long long ll;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0); 
    int n;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;++i){ 
        ans[++now]=s[i];
        if(s[i]=='x'&&now>=3){ 
            if(ans[now-1]=='o'&&ans[now-2]=='f'){ 
                now-=3;
                sum+=3;
            }
        }
    }
    cout<<n-sum;
    return 0;
}
