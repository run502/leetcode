/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     struct ListNode *next;
 * };
 */
#include <stdio.h>
#include <stdlib.h>
#define LEN 0

struct ListNode {
    int val;                //值域 
    struct ListNode *next;  //指针域 
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l3;       //申请l3，用来存储l1和l2的和 
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));    //申请一段 ListNode大小的内存
    l3->val = LEN;      //初始化l3的值为 0 
    l3->next = NULL;    //初始化l3的指针域为 NULL
	struct ListNode *l3_back = l3;    //创建 l3的备份
	static int carry = 0;             //设置进位, 0为没有进位, 1为有进位 
	
	if (l1 == NULL && l2 == NULL) {   //两个数均为空 
		return NULL;                  //返回空 
	} 
	
	if (l1 != NULL && l2 == NULL) {   // l2为空 
		return l1;                    //返回 l1 
	}
	
	if (l1 == NULL && l2 != NULL) {   // l1为空 
		return l2;                    //返回 l2
	}
    
    while (l1 != NULL & l2 != NULL) {
    	struct ListNode *p = NULL; 
		p = (struct ListNode *)malloc(sizeof(struct ListNode));	//申请一个 ListNode大小的内存 
    	
    	if (l1->val+l2->val+carry >= 10) {          //如果位数相加再加进位大于 10 
    		p->val = (l1->val+l2->val+carry)%10;    //p->val的值就是位数相加再加进位对10取模 
			carry = 1;	                            //进位设置为 1 
		}
		
		if (l1->val+l2->val+carry < 10) {           //如果位数相加再加进位小于 10 
			p->val = l1->val+l2->val+carry;         //p->val的值就是位数相加再加进位 
			carry = 0;                              //进位恢复为 0 
		}
		
		p->next = l3->next;                         //使p和l3指向同一个结点 NULL 
		l3->next = p;                               //使得 l3->p->NULL 
		l3 = l3->next;                              //l3跳转到下一个结点, 即P点
		
		l1 = l1->next;                              //使指针 l1往后移动 
		l2 = l2->next;                              //使指针 l2往后移动 
	}
	
	if (l1 != NULL) {			//如果 l1还没有循环完毕
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));   //申请一个 ListNode大小的内存
		
		p->val = l1->val+carry;           //将 l1加上进位的值赋给 p
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next; 
		
		l1 = l1->next;              //使指针往后移动
		
		return l3_back->next;                 //返回需要的值 
	}
	
	if (l2 != NULL) {         //如果 l2还没有循环完毕  
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));   //申请一个 ListNode大小的内存 
		
		p->val = l2->val+carry;           //将 l2加上进位的值赋给 p 
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next;
		
		l2 = l2->next;              //使指针往后移动
		
		return l3_back->next;                 //返回需要的值
	}
	
	if (carry == 1) {               //两个数位数相同且产生了进位 
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));    //申请一段 ListNode大小的内存 
				
		p->val = 1;			//进位 1，将 p->val的值设置为1 
				
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next;      //使得 l3->p->NULL 
	}
	
	return l3_back->next;                 //返回需要的值
}
