#include<bits/stdc++.h>
using namespace std;
const int maxn=105;
char s[maxn];
int t,n,a,b;
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>t;
    while(t--){ 
        cin>>n>>a>>b;
        cin>>(s+1);
        s[n+1]='9';
        if(b>0)cout<<(a+b)*n<<"\n";
        else{ 
            int pre=0,ans=0,cnt1=0,cnt2=0,sum1=0,sum2=0;
            for(int i=1;i<=n;++i){ 
                if(s[i]!=s[i+1]){ 
                    if(s[i]=='0')cnt1++,sum1+=i-pre;
                    else cnt2++,sum2+=i-pre;
                    pre=i;
                }
            }
            if(cnt1<cnt2){ 
                ans+=sum1*a+cnt1*b+sum2*a+b;
            }else{ 
                ans+=sum2*a+cnt2*b+sum1*a+b;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
