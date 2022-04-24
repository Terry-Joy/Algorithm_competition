#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5010;
int sa[maxn],st[maxn],sg[maxn],sc[maxn],ans;
char s[maxn];
int main(){
    int n;
    cin>>n;
    scanf("%s",s+1);
    for(int i=1;i<=n;++i){
        sa[i]=sa[i-1]+(s[i]=='A');
        st[i]=st[i-1]+(s[i]=='T');
        sg[i]=sg[i-1]+(s[i]=='G');
        sc[i]=sc[i-1]+(s[i]=='C');
    }
    for(int i=1;i<=n;++i)
        for(int j=i;j<=n;++j){
            if(sa[j]-sa[i-1]==st[j]-st[i-1]&&sg[j]-sg[i-1]==sc[j]-sc[i-1])
                ans++;
        }
    cout<<ans<<endl;
}