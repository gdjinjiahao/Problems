/*
该程序运行会出现各种奇怪的问题，典型的是会出现访问非法内存。
其原因是在for代码块中，直接利用类名或结构体名定义变量的话，每次分配的都是同一块内存。
之前一直认为每次循环会分配不同的内存块。
经过验证：
for(int i=0;i<100;i++){
	int t=10;
	printf("%d\n",&t);
}
每次显示的地址也都是同一地址。
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
		//无论该内存是否已被申请，每次temp都是同一块内存块
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