#include<iostream>
#include<algorithm>
#include<vector>
#define pb push_back
#include<cstdio>
#include<cstring>
#define I(s) memset(s,0,sizeof(s));
using namespace std;
vector<int>ansP;
const int maxn=1e5+5;
struct SA{ 
    char s[maxn];
    int n,m,a[maxn],sa[maxn],rk[maxn],ht[maxn],tax[maxn],tp[maxn],mn[maxn][20];
    int ansN,T,Log[maxn];
    int cmp(int*f,int x,int y,int w){ 
        return f[x]==f[y]&&f[x+w]==f[y+w];
    }
    void rsort(){ 
        for(int i=0;i<=m;++i)tax[i]=0;  
        for(int i=1;i<=n;++i)tax[rk[tp[i]]]++;
        for(int i=1;i<=m;++i)tax[i]+=tax[i-1];
        for(int i=n;i>=1;--i)sa[tax[rk[tp[i]]]--]=tp[i];
    }
    void Suffix(){ 
        for(int i=1;i<=n;++i)a[i]=s[i];
        for(int i=1;i<=n;++i)rk[i]=a[i],tp[i]=i;
        rsort();
        for(int w=1,p=1,i;p<n;w+=w,m=p){ 
            for(p=0,i=n-w+1;i<=n;++i)tp[++p]=i;
            for(i=1;i<=n;++i)if(sa[i]>w)tp[++p]=sa[i]-w;
            rsort(),swap(rk,tp),rk[sa[1]]=p=1;
            for(int i=2;i<=n;++i)
                rk[sa[i]]=cmp(tp,sa[i],sa[i-1],w)?p:++p;
        }
    }
    void getHt(){ 
        int j,k=0;
        for(int i=1;i<=n;ht[rk[i++]]=k)
            for(k=k?k-1:k,j=sa[rk[i]-1];a[i+k]==a[j+k];++k);
    }    
    void RMQ(){ 
        for(int i=1;i<=n;++i)mn[i][0]=ht[i];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                mn[i][j]=min(mn[i][j-1],mn[i+(1<<(j-1))][j-1]);
    }
    int query(int l,int r){
        l=rk[l],r=rk[r];
        if(l>r)swap(l,r);
        l++; 
        int k=Log[r-l+1];
        return min(mn[l][k],mn[r-(1<<k)+1][k]);
    }
    int check(int i,int j,int len){ 
        int lcp=query(i,j);
        if(lcp/len+1>ansN){ 
            ansN=lcp/len+1;
            ansP.clear();
            //ansP=i;
            ansP.pb(len);
        }else if(lcp/len+1==ansN){ 
            ansP.pb(len);
        }
        return lcp;
    }
    void solve(){ 
        for(int len=1;len<=n;++len){ 
            for(int i=1;i+len<=n;i+=len){ 
                int fi=i,se=i+len;
                int lcp=check(fi,se,len);
                int fi2=i-(len-lcp%len);
                if(lcp%len==0||fi2<1)continue;
                int se2=fi2+len;
                check(fi2,se2,len);
            }
        }
        printf("Case %d: ",++T);
        /*int fi=ansP[0].first,se=ansP[0].second;
        fi=sa[fi];
        for(int i=fi;i<fi+se*ansN;++i)
            putchar(s[i]);*/
        if(ansN==1){//!! 
            putchar(s[sa[1]]);
            return;
        }
        bool f=0;
        for(int i=1;i<=n;++i){ 
            for(int j=0;j<ansP.size();++j){ 
                int fi=sa[i],len=ansP[j];
                int nxt=fi+len;
                if(nxt>n)continue;
                int lcp=query(fi,nxt);
                if(lcp/len+1==ansN){ 
                    for(int k=fi;k<fi+ansN*len;++k)
                        putchar(s[k]);
                    f=1;
                }
                if(f)break;
            }
            if(f)break;
        }
        puts("");
    }
    void init(){ 
        Log[1]=0;
        for(int i=2;i<maxn;++i)
            Log[i]=Log[i/2]+1;
        while(~scanf("%s",s+1)){ 
            if(s[1]=='#')break;
            ansP.clear();
            n=strlen(s+1);//小心多组数据结束符 此时直接赋值
            //for(int i=1;i<=n;++i)
              //  for(int j=0;j<=18;++j)mn[i][j]=0;
            m=(int)'z';//最大字符ASCII码
            ansN=1;
            Suffix();
            getHt();
            RMQ();
            solve();
            //I(mn);
            //I(a);I(sa);I(rk);I(ht);I(tp);I(tax);
        }
    }
}sa;
int main(){ 
    sa.T=0;
    sa.init();
    return 0;
}
