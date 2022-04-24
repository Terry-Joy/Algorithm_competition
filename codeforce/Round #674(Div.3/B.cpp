#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
int a[4][4];
int main(){ 
    int t;
    cin>>t;
    while(t--){ 
        int n,m;
        cin>>n>>m;
        int cnt1=0,cnt2=0,cnt3=0;

        for(int i=1;i<=n;++i)
        { 
            for(int j=1;j<=2;++j)
                for(int k=1;k<=2;++k)
                    cin>>a[j][k];
            if(a[1][1]==a[2][2]&&a[1][2]==a[2][1])cnt3++;
            if(a[1][1]==a[2][2])cnt1++;
            if(a[2][1]==a[1][2])cnt2++;
        }
    	if((m*m)%2==1){ puts("NO");continue;}
        if(m==2)if(cnt2){ 
            puts("YES");
            continue;
        }
        else { 
            puts("NO");
            continue;
        }
        if(cnt3)puts("YES");
        else if(cnt1>0&&cnt2>0)puts("YES");
        else puts("NO");
    }
    return 0;
}
