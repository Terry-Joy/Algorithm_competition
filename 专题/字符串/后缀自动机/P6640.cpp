#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+5;
const int N=2e5+5;
struct SAM{ 
    int tot,last,len[maxn],link[maxn],ch[maxn][26],f[N],mx[N][19],Log[N],n;
    SAM(){ 
        tot=last=1;
    }
    void extend(int c){ 
        int cur=++tot,p=last;last=cur;
        len[cur]=len[p]+1;
        for(;p&&!ch[p][c];p=link[p])ch[p][c]=cur;
        if(!p)link[cur]=1;
        else{ 
            int q=ch[p][c];
            if(len[q]==len[p]+1)link[cur]=q;
            else{ 
                int clone=++tot;
                memcpy(ch[clone],ch[q],sizeof(ch[q]));
                link[clone]=link[q];link[q]=link[cur]=clone;
                len[clone]=len[p]+1;
                for(;p&&ch[p][c]==q;p=link[p])ch[p][c]=clone;
            }
        }
    }
    void query(char*s){
        int L=strlen(s+1),p=1,nowlen=0;
        n=L;
        for(int i=1;i<=L;++i){ 
            int c=s[i]-'a';
            if(ch[p][c])nowlen++,p=ch[p][c];
            else{ 
                while(p&&!ch[p][c])p=link[p];
                if(!p)p=1,nowlen=0;
                else{ 
                    nowlen=len[p]+1;p=ch[p][c];
                }
            }
            f[i]=nowlen;
        }   
    }
    void RMQ(){ 
        for(int i=1;i<=n;++i)mx[i][0]=f[i];
        for(int j=1;(1<<j)<=n;++j)
            for(int i=1;i+(1<<j)-1<=n;++i)
                mx[i][j]=max(mx[i][j-1],mx[i+(1<<(j-1))][j-1]);
        Log[1]=0;
        for(int i=2;i<=n+1;++i)
            Log[i]=Log[i/2]+1;
    }
    bool check(int mid,int l){ 
        return f[mid]-(mid-l+1)<=0;
    }
    int ask(int l,int r){ 
        int k=Log[r-l+1];
        return max(mx[l][k],mx[r-(1<<k)+1][k]);
    }
    void solve(int L,int R){         
        int l=L,r=R+1;
        while(l<r){ 
            int mid=l+r>>1;
            if(check(mid,L))r=mid;
            else l=mid+1;
        }
        if(r==R+1){ 
            cout<<R-L+1<<"\n";
        }else{ 
            cout<<max((r-1)-L+1,ask(r,R))<<"\n";
        }
    }
}sam;
char s[maxn],s1[maxn];
int main(){
    scanf("%s%s",s+1,s1);
    int len=strlen(s1);
    for(int i=0;i<len;++i)sam.extend(s1[i]-'a');
    sam.query(s);
    sam.RMQ();
    int m,l,r;
    scanf("%d",&m);
    for(int i=1;i<=m;++i){ 
        scanf("%d%d",&l,&r);
        sam.solve(l,r);
    }
    return 0;
}
