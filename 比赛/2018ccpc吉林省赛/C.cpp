#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
int t,n,cnt1,cnt2,now;
struct Node{ 
    int val,id;
    bool operator<(const Node&x)const{ 
        return val<x.val;
    }
}a[maxn];
bool ans[maxn];
int main(){ 
    scanf("%d",&t);
    int T=0;
    while(t--){ 
        bool f=1;
        cnt1=cnt2=now=1;
        scanf("%d",&n);
        for(int i=1;i<=n;++i)ans[i]=0;
        for(int i=1;i<=n;++i)scanf("%d",&a[i].val),a[i].id=i;
        sort(a+1,a+1+n);
        cout<<"Case "<<++T<<": ";
        for(int i=1;i<=n;++i){ 
            while(cnt1+cnt2<=n-i+1&&now<a[i].val)
                cnt1<<=1,cnt2<<=1,now++;
            if(cnt1+cnt2>n-i+1){ 
                f=0;break;     
            }
            if(cnt1)cnt1--,ans[a[i].id]=1;
            else cnt2--;
            if(!cnt1&&!cnt2)break;
        }
        if(!f||cnt1||cnt2){ 
            puts("NO");
        }else{ 
            puts("YES");
            for(int i=1;i<=n;++i)cout<<ans[i];
            puts("");
        }
    }
    return 0;
}
