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
    int val;                //ֵ�� 
    struct ListNode *next;  //ָ���� 
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *l3;       //����l3�������洢l1��l2�ĺ� 
    l3 = (struct ListNode *)malloc(sizeof(struct ListNode));    //����һ�� ListNode��С���ڴ�
    l3->val = LEN;      //��ʼ��l3��ֵΪ 0 
    l3->next = NULL;    //��ʼ��l3��ָ����Ϊ NULL
	struct ListNode *l3_back = l3;    //���� l3�ı���
	static int carry = 0;             //���ý�λ, 0Ϊû�н�λ, 1Ϊ�н�λ 
	
	if (l1 == NULL && l2 == NULL) {   //��������Ϊ�� 
		return NULL;                  //���ؿ� 
	} 
	
	if (l1 != NULL && l2 == NULL) {   // l2Ϊ�� 
		return l1;                    //���� l1 
	}
	
	if (l1 == NULL && l2 != NULL) {   // l1Ϊ�� 
		return l2;                    //���� l2
	}
    
    while (l1 != NULL & l2 != NULL) {
    	struct ListNode *p = NULL; 
		p = (struct ListNode *)malloc(sizeof(struct ListNode));	//����һ�� ListNode��С���ڴ� 
    	
    	if (l1->val+l2->val+carry >= 10) {          //���λ������ټӽ�λ���� 10 
    		p->val = (l1->val+l2->val+carry)%10;    //p->val��ֵ����λ������ټӽ�λ��10ȡģ 
			carry = 1;	                            //��λ����Ϊ 1 
		}
		
		if (l1->val+l2->val+carry < 10) {           //���λ������ټӽ�λС�� 10 
			p->val = l1->val+l2->val+carry;         //p->val��ֵ����λ������ټӽ�λ 
			carry = 0;                              //��λ�ָ�Ϊ 0 
		}
		
		p->next = l3->next;                         //ʹp��l3ָ��ͬһ����� NULL 
		l3->next = p;                               //ʹ�� l3->p->NULL 
		l3 = l3->next;                              //l3��ת����һ�����, ��P��
		
		l1 = l1->next;                              //ʹָ�� l1�����ƶ� 
		l2 = l2->next;                              //ʹָ�� l2�����ƶ� 
	}
	
	if (l1 != NULL) {			//��� l1��û��ѭ�����
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));   //����һ�� ListNode��С���ڴ�
		
		p->val = l1->val+carry;           //�� l1���Ͻ�λ��ֵ���� p
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next; 
		
		l1 = l1->next;              //ʹָ�������ƶ�
		
		return l3_back->next;                 //������Ҫ��ֵ 
	}
	
	if (l2 != NULL) {         //��� l2��û��ѭ�����  
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));   //����һ�� ListNode��С���ڴ� 
		
		p->val = l2->val+carry;           //�� l2���Ͻ�λ��ֵ���� p 
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next;
		
		l2 = l2->next;              //ʹָ�������ƶ�
		
		return l3_back->next;                 //������Ҫ��ֵ
	}
	
	if (carry == 1) {               //������λ����ͬ�Ҳ����˽�λ 
		struct ListNode *p = NULL;
		p = (struct ListNode *)malloc(sizeof(struct ListNode));    //����һ�� ListNode��С���ڴ� 
				
		p->val = 1;			//��λ 1���� p->val��ֵ����Ϊ1 
				
		p->next = l3->next;
		l3->next = p;
		l3 = l3->next;      //ʹ�� l3->p->NULL 
	}
	
	return l3_back->next;                 //������Ҫ��ֵ
}
