#include <iostream>
#include <fstream>
#include <stdlib.h>
#include <stdio.h>
#include <string>
#include <sstream>
using namespace std;

string toString(int inpt){
	stringstream sStream;
	string str;
	sStream<<inpt;
	sStream>>str;
	return str;
}

bool isLetter(char input){
	if (input <= 'Z' && input >= 'A' || input <= 'z' && input >= 'a'){
		return true;
	}
	return false;
}

bool isDigit(char input){
	if (input<= '9' && input >= '0'){
		return true;
	}
	return false;
}

//传入一整行字符串，
void split(string line,string * tmpStrSeries,const int size){
	int len=line.length();
	int sid=0;
	int eid=0;
	int cnt=0;
	string tmp;
	while(sid<len)
	{
		while (line[sid]==' '){
            sid++;
            if(sid>=len){
                break;
            }
		}
        if (sid<len){
            if (isLetter(line[sid])||isDigit(line[sid]))
            {
                for (int i = sid; i < len; i++)
                {
                    if (!isLetter(line[i])&&!isDigit(line[i]))
                    {
                        eid=i;
                        break;
                    }
                }
                tmp=line.substr(sid,eid-sid);
                tmpStrSeries[cnt++]=tmp;
                sid=eid;
                continue;
            }
        }
        if (line[sid]=='\'')
        {
            bool flag=false;
            for (int i = sid+1; i < len; i++)
            {
                if (line[i]=='\'')
                {
                    eid=i+1;
                    flag=true;
                    break;
                }
            }
            if (!flag)
            {
                eid=len-1;
            }
            // cout<<sid<<" "<<eid<<len<<endl;
            tmp=line.substr(sid,eid-sid);
            tmpStrSeries[cnt++]=tmp;
            sid=eid;
            continue;
        }
		if (sid<len-1)
		{
			if((!isLetter(line[sid]))&&(!isDigit(line[sid]))&&(isLetter(line[sid+1])||isDigit(line[sid+1])||line[sid+1]==' '))
			{
                tmp=line.substr(sid,1);
				tmpStrSeries[cnt++]=tmp;
				sid++;
                continue;
			}
            
		}
		if (sid<len-1)
		{
			if(!isLetter(line[sid])&&!isDigit(line[sid])&&!(isLetter(line[sid+1])||isDigit(line[sid+1])||line[sid+1]==' '))
			{
				tmp=line.substr(sid,2);
				tmpStrSeries[cnt++]=tmp;
				sid+=2;
                continue;
			}
		}
		if (sid==len-1&&!isLetter(line[sid])&&!isDigit(line[sid]))
		{
            tmp=line.substr(sid,1);
			tmpStrSeries[cnt++]=tmp;
			sid++;
		}
	}
}

string keyword[35]={"and" , "array" , "begin" , "bool" , "call" , "case" , "char" , "constant" , "dim" , "do" , 
"else" , "end" , "false", "for" , "if", "input", "integer" , "not" , "of" , "or" , "output" , "procedure", 
"program" , "read" , "real" , "repeat" , "set" , "stop" , "then" , "to" , "true" , "until" , "var" , "while" , "write"};
string boolConstant[2]={"true","false"};
string delimeter[22]={"(",")","*","*/","+",",","-",".","..","/","/*",":",":=",";","<","<=","<>","=",">",">=","[","]"};

struct Token{
	string word;
	int kindNum;
	int val;
	int index;
};

const int maxsize=10000;
Token tk[maxsize];

bool canBeToken(int & tkTop,string * tmpStrSeries,const int maxsize, string& err, int lineNum)
{
	int curVal=0;
	bool lannotationExist=false;
	bool rannotaionExist=false;
	bool annotaionError=false;
	for (int i = 0; i < maxsize; i++)
    {
        if (tmpStrSeries[i]=="")
        {
            break;
        }
        string tmp=tmpStrSeries[i];
		int tmpkindNum=0;
		if (isLetter(tmp[0]))
		{
			bool flag=false;
			for (int i=0;i<35;i++){
				if (tmp==keyword[i]){
					tmpkindNum=i+1;
					flag=true;
					break;
				}
			}
			if (flag){
				tk[tkTop].kindNum=tmpkindNum;
				tk[tkTop].word=tmp;
				tkTop++;
			}
			else
			{
				tk[tkTop].kindNum=36;
				tk[tkTop].word=tmp;
				
				bool appeared=false;
				for (int i = 0; i < tkTop; i++)
				{
					if(tk[i].word==tmp)
					{
						tk[tkTop].val=tk[i].val;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
						appeared=true;
						break;
					}
				}
				if (!appeared){
					curVal++;
					tk[tkTop].val=curVal;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
				}
				tkTop++;
			}
			continue;
		}
		if (isDigit(tmp[0]))
		{
			bool illegalDigit=false;
			for (int i = 0; i < tmp.length(); i++)
			{
				if (!isDigit(tmp[i]))
				{
					illegalDigit=true;
					break;
				}
			}
			if (illegalDigit)
			{
				err+="\nError: Illegal number in line"+toString(lineNum);
				return false;
			}
			else
			{
				tk[tkTop].kindNum=37;
				tk[tkTop].word=tmp;

				bool appeared=false;
				for (int i = 0; i < tkTop; i++)
				{
					if(tk[i].word==tmp)
					{
						tk[tkTop].val=tk[i].val;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
						appeared=true;
						break;
					}
				}
				if (!appeared){
					curVal++;
					tk[tkTop].val=curVal;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
				}
				tkTop++;
			}
			continue;
		}
		if (tmp[0]=='\'')
		{
			if (tmp[tmp.length()-1]=='\'')
			{
				tk[tkTop].kindNum=38;
				tk[tkTop].word=tmp;
				bool appeared=false;
				for (int i = 0; i < tkTop; i++)
				{
					if(tk[i].word==tmp)
					{
						tk[tkTop].val=tk[i].val;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
						appeared=true;
						break;
					}
				}
				if (!appeared){
					curVal++;
					tk[tkTop].val=curVal;
						cout<<tkTop<<" "<<tk[tkTop].val<<">>>>>>";
				}
				tkTop++;
				continue;
			}
			else
			{
				err+="\nError: Illegal character constant in line"+toString(lineNum);
				return false;
			}
		}
		if (!isDigit(tmp[0])&&!isLetter(tmp[0]))
		{
			bool inDelimeter=false;
			for (int i=0;i<22;i++){
				if(tmp==delimeter[i]){
					tmpkindNum=i+39;
					inDelimeter=true;
					break;
				}
			}
			if (inDelimeter)
			{
				tk[tkTop].kindNum=tmpkindNum;
				tk[tkTop].word=tmp;
				tkTop++;
				if (tmp=="/*"){
					lannotationExist=true;
				}
				if (tmp=="*/")
				{
					if (!lannotationExist)
					{
						annotaionError=true;
					}
					else{
						lannotationExist=false;
					}
				}
				continue;
			}
			else
			{
				err+="\nError: Illegal delimeter in line "+toString(lineNum);
				return false;
			}
		}
    }
	if (lannotationExist&&!rannotaionExist||annotaionError){
		err+="\nError: Annotation error in line "+toString(lineNum);
		return false;
	}
	return true;
}




int main(){
    // string fileName="TEST1.txt";
    // const char* fN=fileName.c_str();
	// ifstream fin(fN);
    // fstream line;
    // char c;
    // // line.open(fileName,iso::in);
    // int lineNum=1;
    // while(fin.get(c)){
    //     if (c=='\n')
    //         lineNum++;
    // }
    // cout<<lineNum;
    // cout<<getLineNum("TEST1.txt","procedure");
    // string line="var A,B,C:integer;";
    // string line="begin  /*  this  is  an  example  */";
    string line="  X:='ABC'";
    // const int maxsize=10000;
    string st[maxsize];
    for (int i=0;i<maxsize;i++)
    {
        st[i]="";
    }
    split(line,st,maxsize);
    for (int i = 0; i < maxsize; i++)
    {
        if (st[i]=="")
        {
            break;
        }
        cout<<st[i]<<endl;
    }
    
    // Token* pt=tks;
    int tkTop=0;
    string err;
    canBeToken(tkTop,st,maxsize,err,1);
    cout<<tkTop<<endl;
	cout<<tkTop<<"hangshu>>>\n";
    for (int i = 0; i < tkTop; i++)
    {
        cout<<tk[i].word<<"\t"<<tk[i].kindNum<<"\t"<<tk[i].val<<endl;
        // cout<<pt[tkTop].word<<"\t"<<pt[tkTop].kindNum<<"\t"<<pt[tkTop].val<<endl;
    }
    

    // string ss="'happy'";
    // bool bb=(ss[0]=='\'');
    // // cout<<ss[0]<<"\n"<<bb<<endl;
    // for (int i = 0; i < 5; i++)
    // {
    //     // cout<<i;
    //     i++;
    // }



    //=======================================================
    // string programName="TEST1";
    // string fileName=programName+".txt";
    // const char* fN=fileName.c_str();
    // ifstream fin(fN);
    // string input = "";
    // string output= "";
    // const int maxnum=10000;
    // Token tks[maxnum];
    // int tkTop=0;
    // string err;
    // int cntLineNum=0;
    // string line;
    // bool canbetoken;
    // while (getline(fin,line))
    // {
    //     // cout<<cntLineNum<<endl;
    //     cntLineNum++;
    //     string tmpStrSeries[maxnum];
    //     split(line,tmpStrSeries,maxnum);
    //     canBeToken(tks,tkTop,tmpStrSeries,maxnum,err,cntLineNum);
    // }
    // for (int i = 0; i < tkTop; i++)
    // {
    //     if (i%5==0)
    //     {
    //         output+="\n";
    //     }
    //     if (tks[i].kindNum>=36 && tks[i].kindNum<=38){
    //         output+="("+toString(tks[i].kindNum)+" , "+toString(tks[i].val)+" )\t\t";
    //     }
    //     else
    //     {
    //         output+="("+toString(tks[i].kindNum)+" , - )\t\t";
    //     }
    // }
    // output+=err;
    // cout<<output<<endl;
}

