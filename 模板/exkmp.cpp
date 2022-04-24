//求与某个后缀的LCP
#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e7+10;
char s1[maxn],s2[maxn];
int z[maxn],ext[maxn]; //z[i] s2[i,n]与s2[1,n]的LCP ext[i]是s1[i,n]与s2[1,n]的LCP
void getZ(int len){ 
    z[1]=len;
    int now=1;
    while(now<len&&s2[now]==s2[now+1])now++;
    z[2]=now-1;
    int p=2;
    for(int i=3;i<=len;++i){ 
        if(z[i-p+1]+i-1<p+z[p]-1)z[i]=z[i-p+1];
        else{ 
            now=p+z[p]-i;
            if(now<0)now=0;
            while(s2[now+1]==s2[i+now]&&i+now<=len)now++;
            z[i]=now;
            p=i;
        }
    }
}
void exkmp(int len,int len2){ 
    int now=0;
    while(now<len&&now<len2&&s2[now+1]==s1[now+1])now++;
    ext[1]=now;
    int p=1;
    for(int i=2;i<=len;++i){ 
        if(z[i-p+1]+i-1<p+ext[p]-1)ext[i]=z[i-p+1];
        else{ 
            now=p+ext[p]-i;
            if(now<0)now=0;
            while(s2[now+1]==s1[i+now]&&i+now<=len&&now<len2)now++;
            ext[i]=now;
            p=i;
        }
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>(s1+1)>>(s2+1);
    int len1=strlen(s1+1);
    int len2=strlen(s2+1);
    getZ(len2);
    exkmp(len1,len2);
    ll ans0=0,ans1=0;
    for(int i=1;i<=len2;++i){ 
        ans0^=(ll)i*(z[i]+1);
    }
    for(int i=1;i<=len1;++i){ 
        ans1^=(ll)i*(ext[i]+1);
    }
    cout<<ans0<<"\n"<<ans1<<"\n";
    return 0;
}
