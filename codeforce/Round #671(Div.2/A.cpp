#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
char s[1010];
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int n;
        cin>>n;
        scanf("%s",s+1);
        if(n==1){ 
            if((s[1]-'0')%2==0)puts("2");
            else puts("1");
            continue;
        }
        bool ou=0,ji=0;
        for(int i=1;i<=n;i+=2){ 
            if((s[i]-'0')%2==1){ 
                ji=1;break;
            }
        }
        for(int i=2;i<=n;i+=2) 
            if((s[i]-'0')%2==0){ 
                ou=1;break;
            }
        if(n%2==0){ 
            if(ou==1)puts("2");
            else puts("1");
        }
        else{ 
            if(ji==1)puts("1");
            else puts("2");
        }
    }
    return 0;
}
