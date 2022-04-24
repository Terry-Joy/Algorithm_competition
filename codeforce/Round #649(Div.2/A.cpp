#include<bits/stdc++.h>

using namespace std;
typedef long long ll;
const int maxn=1e5+5;
int a[maxn];
int main(){ 
    int t,n,x;
    cin>>t;
    while(t--){ 
        int sum=0;
        bool flag=1;
        cin>>n>>x;
        for(int i=1;i<=n;++i)
        { 
            scanf("%d",&a[i]);
            sum+=a[i];
            if(a[i]%x!=0)flag=0;
            a[i]%=x;
        }
        if(flag){ 
            puts("-1");continue;
        }
        if(sum%x!=0){ cout<<n<<endl;continue;}
        int l=1,r=n;
        while(a[l]==0&&l<=n)l++;
        while(a[r]==0&&r>=1)r--;
        printf("%d\n",max(n-l,r-1));
    }
    return 0;
}
