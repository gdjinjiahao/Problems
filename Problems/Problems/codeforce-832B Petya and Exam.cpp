/*
���⣺�����һ�и���һ��Сд��ĸ���ϣ�Ϊ���ַ�������Сд��ĸΪ���ַ�
�ڶ���Ϊһ��ģʽ��������0�����'?'������һ��'*'��'?'���Ա��滻����һ���ַ���'*'���Ա��滻���κ��л��ַ���ɵ��ַ��������մ�
����������һ��n��֮��n�и���n���ַ������ж�ÿ���ַ����Ƿ��ܺ�ģʽ��ƥ�䡣
������
��ģʽ����Ϊ��'*'�Ͳ���'*'�����ֱ����ؼ��ں�'*'������Ҫ����ͷ���м�ƥ�䡣
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