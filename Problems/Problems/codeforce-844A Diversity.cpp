/*
Calculate the minimum number of characters you need to change in the string s, so that it contains at least k different letters, or print that it is impossible.

String s consists only of lowercase Latin letters, and it is allowed to change characters only to lowercase Latin letters too.

Input
First line of input contains string s, consisting only of lowercase Latin letters (1 ≤ |s| ≤ 1000, |s| denotes the length of s).

Second line of input contains integer k (1 ≤ k ≤ 26).

Output
Print single line with a minimum number of necessary changes, or the word «impossible» (without quotes) if it is impossible.
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

string s;
int k;
bool vis[26];

int main()
{
	//freopen("in.txt","r",stdin);
	memset(vis,false,sizeof(vis));
	cin>>s>>k;
	int len=s.length();
	if(len<k){
		printf("impossible\n");
		return 0;
	}
	int cnt=0;
	for(int i=0;i<len;i++){
		if(!vis[s[i]-'a']){
			cnt++;
			vis[s[i]-'a']=true;
		}
	}

	if(cnt>=k) printf("0\n");
	else printf("%d\n",k-cnt);
    return 0;
}