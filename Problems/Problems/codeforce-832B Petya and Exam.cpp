/*
题意：输入第一行给定一个小写字母集合，为好字符，其他小写字母为坏字符
第二行为一个模式串，含有0到多个'?'和至多一个'*'，'?'可以被替换成任一好字符，'*'可以被替换成任何有坏字符组成的字符串包括空串
第三行输入一个n，之后n行给定n个字符串，判断每个字符串是否能和模式串匹配。
分析：
将模式串分为含'*'和不含'*'串，分别处理，关键在含'*'串，需要从两头向中间匹配。
*/

#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <vector>
#include <queue>
#include <iostream>
#include <map>
#include <set>
#include <cmath>
#include <bitset>
using namespace std;

string s,t;
bool good[26];

bool bad(int l,int r)
{
	for(int i=l;i<=r;i++) if(good[t[i]-'a'])
		return false;
	return true;
}

bool solve1()
{
	int l1=s.length(),l2=t.length();
	if(l1!=l2) return false;
	for(int i=0;i<l1;i++){
		if(s[i]=='?'){
			if(!good[t[i]-'a']) return false;
		}
		else{
			if(s[i]!=t[i]) return false;
		}
	}
	return true;
}

bool solve2()
{
	int len1=s.length(),len2=t.length();
	int l1=0,r1=len1-1,l2=-1,r2=len2;
	while(s[l1]!='*'){
		l2++;
		if(l2>=len2) return false;
		if(s[l1]=='?'){
			if(!good[t[l2]-'a']) return false;
		}
		else{
			if(s[l1]!=t[l2]) return false;
		}
		l1++;
	}

	while(s[r1]!='*'){
		r2--;
		if(r2<0) return false;
		if(s[r1]=='?'){
			if(!good[t[r2]-'a']) return false;
		}
		else{
			if(s[r1]!=t[r2]) return false;
		}
		r1--;
	}
	if(l2>=r2) return false;
	if(l1!=r1) return false;
	

	int tl=l1,tr=len2-(len1-l1-1)-1;
	return bad(tl,tr);

	
}

int main()
{
	//freopen("in.txt","r",stdin);
	memset(good,false,sizeof(good));
	cin>>t;
	for(int i=0;i<t.length();i++) good[t[i]-'a']=true;
	cin>>s;
	bool sp=false;
	for(int i=0;i<s.length();i++) if(s[i]=='*'){
		sp=true;
		break;
	}
	int n;
	cin>>n;
	while(n--){
		cin>>t;
		if(sp) printf("%s\n",solve2()?"YES":"NO");
		else printf("%s\n",solve1()?"YES":"NO");
	}
    return 0;
}