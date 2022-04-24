#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=3e5+5;
char s[maxn];
int main(){ 
    int t,n;
    cin>>t;
    while(t--){ 
        scanf("%d",&n);
        scanf("%s",s+1);
        bool flag1=1,flag2=1;
        for(int i=1;i<=n;++i){ 
            if(s[i]=='>'||s[i]=='-')
                continue;
            else { flag1=0;break;}
        }
        for(int i=1;i<=n;++i){ 
            if(s[i]=='<'||s[i]=='-')
                continue;
            else { 
                flag2=0;
                break;
            }
        }
        if(flag1||flag2){ 
            cout<<n<<"\n";
            continue;
        }else{ 
            int ans=0;
            for(int i=1;i<=n;++i){ 
                int tmp=((i==1)?n:i-1);
                if(s[i]=='-'||s[tmp]=='-')
                    ans++;
            }
            cout<<ans<<"\n";
        }
    }
    return 0;
}
