/*
�ó������л���ָ�����ֵ����⣬���͵��ǻ���ַ��ʷǷ��ڴ档
��ԭ������for������У�ֱ������������ṹ������������Ļ���ÿ�η���Ķ���ͬһ���ڴ档
֮ǰһֱ��Ϊÿ��ѭ������䲻ͬ���ڴ�顣
������֤��
for(int i=0;i<100;i++){
	int t=10;
	printf("%d\n",&t);
}
ÿ����ʾ�ĵ�ַҲ����ͬһ��ַ��
*/
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <cstring>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
};

ListNode* addTwoNumbers(int a[],int len) 
{
	ListNode* l=NULL;
	ListNode* cur=NULL;

	for(int i=0;i<len;i++){
		//���۸��ڴ��Ƿ��ѱ����룬ÿ��temp����ͬһ���ڴ��
		ListNode temp;
		temp.val=a[i];
		temp.next=NULL;
		if(cur==NULL) l=&temp;
		else cur->next=&temp;
		cur=&temp;
	}
	return l;
}

int main()
{
	int a[]={1,2,3,4,5};

	ListNode* ans=addTwoNumbers(a,5);

	while(ans){
		printf("%d ",ans->val);
		ans=ans->next;
	}
	return 0;
}