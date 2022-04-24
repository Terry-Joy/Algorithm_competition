#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
char s[maxn];
int main(){ 
    cin>>(s+1);
    int len=strlen(s+1);
    bool ok=0;
    int ps1=0,ps2=0;
    for(int i=1;i+1<=len;++i){ 
        if(s[i]==s[i+1]){ 
            ok=1;
            ps1=i;ps2=i+1;break;
        }
    }
    if(!ok){ 
        for(int i=1;i+2<=len;++i){ 
            if(s[i]==s[i+2]){ 
                ok=1;
                ps1=i;ps2=i+2; 
                break;  
            }
        }
    }
    if(!ok)cout<<"-1 -1";
    else cout<<ps1<<" "<<ps2;
    return 0;
}
