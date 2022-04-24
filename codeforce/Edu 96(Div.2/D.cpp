
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=2e5+5;
int sum[maxn],n;
char s[maxn];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        scanf("%s",s+1);
        int num=0,cnt=0,len=strlen(s+1);
        s[len+1]='#';
        for(int i=1;i<=len;++i){
            num++;
            if(s[i]!=s[i+1]){
                sum[++cnt]=num;
                num=0;
            }
        }
        bool flag=1;
        int ans=0,l=1,r=1;
        while(flag){
            if(sum[l]>1){
                ans++;
                l++;r=l;
            }else{
                while(r<=cnt&&sum[r]<=1)r++;
                if(r>cnt){
                    ans+=((cnt-l+2)/2);
                    flag=0;
                    break;
                }else{
                    sum[r]--;
                    ans++;
                    l++;
                }
            }
        }
        cout<<ans<<"\n";
        for(int i=1;i<=cnt;++i)
            sum[i]=0;
    }
    return 0;
}