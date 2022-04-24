#include<bits/stdc++.h>
#define eb emplace_back
using namespace std;
const int maxn=1520;
struct Hash{

	const static int md0 = 1e9 + 7, md1 = 1e9 + 9;
	int h0, h1;
	Hash(int h0 = 0, int h1 = 0) : h0(h0), h1(h1) {}
	Hash operator + (const int &o) const { return Hash((h0 + o) % md0, (h1 + o) % md1); }
	Hash operator * (const int &o) const { return Hash((h0 * 1ll * o) % md0, (h1 * 1ll * o) % md1); }
	Hash operator + (const Hash &o) const { return Hash((h0 + o.h0) % md0, (h1 + o.h1) % md1); }
	Hash operator - (const Hash &o) const { return Hash((h0 - o.h0 + md0) % md0, (h1 - o.h1 + md1) % md1); }
	Hash operator * (const Hash &o) const { return Hash((h0 * 1ll * o.h0) % md0, (h1 * 1ll * o.h1) % md1); }
	bool operator == (const Hash &o) const { return h0 == o.h0 && h1 == o.h1; }
} has[maxn], pw[maxn], base = {131, 133};

Hash getH(int l,int r){ 
    return has[r]-has[l-1]*pw[r-l+1];
}

void init(int n,char *s){ 
    pw[0]={ 1,1};
    for(int i=1;i<=n;++i){ //s+1
        pw[i]=pw[i-1]*base;
        has[i]=has[i-1]*base+s[i];
    }
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<Hash>res;
    pw[0]={ 1,1};
    for(int i=1;i<maxn;++i)
        pw[i]=pw[i-1]*base;
    for(int i=1;i<=n;++i){ 
        char s[1520];
        cin>>s+1;
        int len=strlen(s+1);
        has[0]=0;
        for(int i=1;i<=len;++i)
            has[i]=has[i-1]*base+s[i];
        res.eb(has[len]);
    }
    sort(res.begin(),res.end(),[&](Hash a,Hash b){ 
            if(a.h0==b.h0)return a.h1<b.h1;
            return a.h0<b.h0;
            });
    res.erase(unique(res.begin(),res.end()),res.end());
    cout<<res.size()<<'\n';
    return 0;
}
