#include<bits/stdc++.h>
using namespace std;
map<string,int>mp;
int t;
char s[30];
string s1,s2;
string ss[4];
int main(){ 
    scanf("%d",&t);
    ss[0]="London";
    ss[1]="Moscow";
    ss[2]="Washington";
    ss[3]="Beijing";
    mp[ss[0]]=0;
    mp[ss[1]]=3;
    mp[ss[2]]=-5;
    mp[ss[3]]=8;
    int T=0;
    while(t--){ 
        int cnt=0;
        char c;
        while(c=getchar()){ 
            if(c=='\n')break;
            s[++cnt]=c;
        }
        int h=0,f=0,st=0;
        bool f1=0;
        int i;
        for(i=1;i<=cnt;++i){ 
            if(s[i]==':'){
                i++;break;
            }
            h=h*10+s[i]-'a';
        }
        for(i;i<=cnt;++i){ 
            if(s[i]==' '){
                i++;break;
            }
            f=f*10+s[i]-'a';
        }
        if(s[i]=='P')f1=1;
        cin>>s1>>s2;
        cout<<s1<<" "<<s2<<"\n";
        cout<<mp[s2]<<" "<<mp[s1]<<"\n";
        h+=(mp[s2]-mp[s1]);
        if(h>=12){ 
            h-=12;
            if(!f1){ 
                f1=1;
            }
            else{ 
                f1=0;
                st=1;
            }
        }else if(h<=0){ 
            h+=12;
            if(!f1){ 
                f1=1;
                st=2;
            }
            else{ 
                if(h!=12)
                f1=0;
            }
        }
        cout<<"Case "<<++T<<": "<<((!st)?"Today":((st==1)?"Tomorrow":"Yesterday"))<<" "<<h<<":"<<(f<10?"0":"")<<f<<" "<<(f1?"PM":"AM")<<"\n";
    }
    return 0;
}
