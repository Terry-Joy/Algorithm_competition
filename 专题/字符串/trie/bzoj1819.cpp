#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4+5;
int n,m,tr[maxn*20][26],cnt,num[maxn*20];
unordered_map<string,bool>mp;
string s1[maxn],s2[maxn];
string alp[30]={ "a","b","c","d","e","f","g","h","i","j","k","l","m","n","o","p","q","r","s","t","u","v","w","x","y","z"};
void insert(string&x){ 
    int now=0;
    int len=x.length();
    for(int i=0;i<len;++i){ 
        int ch=x[i]-'a';
        if(!tr[now][ch])tr[now][ch]=++cnt;
        now=tr[now][ch];
    }
    num[now]++;
}
int find(string&x){ 
    int sum=0,now=0,len=x.length();
    for(int i=0;i<len;++i){ 
        int ch=x[i]-'a';
        if(!tr[now][ch])return 0;
        else now=tr[now][ch];
    }
    sum+=num[now];
    return sum;
}
int add(string&x){ 
    int len=x.length(),sum=0;
    for(int pos=0;pos<26;++pos){
        string i=alp[pos]; 
        for(int j=0;j<len;++j){ 
            string w=x;
            w.insert(j,i);
            if(mp[w])continue;
            else{ 
                mp[w]=1;
                sum+=find(w);
            }
        }
    }
    for(int pos=0;pos<26;++pos){ 
        string i=alp[pos];
        string w=x;
        w.append(i);
        if(mp[w])continue;
        else{ 
            mp[w]=1;
            sum+=find(w);
        }   
    }
    return sum;
}
int del(string&x){ 
    int len=x.length(),sum=0;
    for(int i=0;i<len;++i){ 
        string w=x;
        w.erase(w.begin()+i);
        if(mp[w])continue;
        else{ 
            mp[w]=1;
            sum+=find(w);
        }   
    }
    return sum;
}
int update(string&x){ 
    int len=x.length(),sum=0;
    for(int i=0;i<len;++i){ 
        for(int pos=0;pos<26;++pos){ 
            string r=alp[pos];
            string w=x;
            w.replace(i,1,r);
            if(mp[w])continue;
            else{ 
                mp[w]=1;
                sum+=find(w);
            }
        }
    }
    return sum;
}
int main(){ 
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;++i)cin>>s1[i],insert(s1[i]);
    for(int i=1;i<=m;++i)cin>>s2[i];
    for(int i=1;i<=m;++i){ 
        if(find(s2[i]))cout<<-1<<"\n";
        else{ 
            mp.clear();
            cout<<add(s2[i])+del(s2[i])+update(s2[i])<<"\n";
        }
    }
    return 0;
}
