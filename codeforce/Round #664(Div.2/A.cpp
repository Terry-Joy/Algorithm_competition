#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int r,g,b,w;
        cin>>r>>g>>b>>w;
        if(r%2==0&&g%2==0&&b%2==0&&w%2==0){ 
            puts("Yes");
        }
        else if(r%2==1&&g%2==1&&b%2==1&&w%2==1){ 
                puts("Yes");
        }
        else{ 
            int cnt1,cnt=0;
            if(r%2==1)cnt1++;
            else cnt++;
            if(g%2==1)cnt1++;
            else cnt++;
            if(b%2==1)cnt1++;
            else cnt++;
            if(w%2==1)cnt1++;
            else cnt++;
            if(cnt==3){ puts("Yes");
            }
            else if(cnt==1&&min(min(r,g),min(b,w))>=1)
                puts("Yes");
            else if(cnt==1&&min(min(r,g),min(b,w))==0&&w==0)
                puts("Yes");
            else puts("No");
        }
    }
    return 0;
}
