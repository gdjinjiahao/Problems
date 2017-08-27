/*
You are given two strings s and t consisting of small Latin letters, string s can also contain '?' characters.

Suitability of string s is calculated by following metric:

Any two letters can be swapped positions, these operations can be performed arbitrary number of times over any pair of positions. Among all resulting strings s, you choose the one with the largest number of non-intersecting occurrences of string t. Suitability is this number of occurrences.

You should replace all '?' characters with small Latin letters in such a way that the suitability of string s is maximal.

Input
The first line contains string s (1 ≤ |s| ≤ 106).

The second line contains string t (1 ≤ |t| ≤ 106).

Output
Print string s with '?' replaced with small Latin letters in such a way that suitability of that string is maximal.

If there are multiple strings with maximal suitability then print any of them.

Examples
input
?aa?
ab
output
baab
input
??b?
za
output
azbz
input
abcd
abacaba
output
abcd
Note
In the first example string "baab" can be transformed to "abab" with swaps, this one has suitability of 2. That means that string "baab" also has suitability of 2.

In the second example maximal suitability you can achieve is 1 and there are several dozens of such strings, "azbz" is just one of them.

In the third example there are no '?' characters and the suitability of the string is 0.
*/

#include <cstdio>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
using namespace std;
char str[1000010];
int temp1[30],temp2[30];
int ans[30];
int main()
{
	memset(temp1,0,sizeof(temp1));
	memset(temp2,0,sizeof(temp2));
	memset(ans,0,sizeof(ans));
	cin.getline(str,1000010);
	char t;
	while((t=getchar())!='\n') temp2[t-'a']++;
	int len=strlen(str);
	int tt=0;
	for(int i=0;i<len;i++)
		if(str[i]=='?') tt++;
		else temp1[str[i]-'a']++;

	while(tt){
		for(int i=0;i<26;i++){
			if(temp1[i]>=temp2[i])
				temp1[i]-=temp2[i];
			else{
				int dis=temp2[i]-temp1[i];
				temp1[i]=0;
				if(dis<=tt){
					tt-=dis;
					ans[i]+=dis;
				}
				else{
					tt=0;
					ans[i]+=tt;
				}
			}
			if(!tt) break;
		}
	}
	int pos=0;
	ans[25]=1000010;
	for(int i=0;i<len;i++){
		if(str[i]=='?'){
			while(pos<26&&ans[pos]<=0) pos++;
			ans[pos]--;
			printf("%c",'a'+pos);
		}
		else
			printf("%c",str[i]);
		
	}
	printf("\n");
	return 0;
}