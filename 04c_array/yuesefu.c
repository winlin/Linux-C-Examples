/*
 *有循环链表实现约瑟夫问题
 */
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int number;
	struct Node* next;
}Node;
Node* head;
Node* p,*q;

int main()
{
	printf("请输入人数:");
	int peos;
	scanf(" %d",&peos);
	printf("请输入杀人的数字:");
	int count;
	scanf(" %d",&count);
	
	int i;
	for(i=0;i<peos;++i){
		p=(Node*)malloc(sizeof(Node));
		if(!head)
			head=p;
		p->number=i+1;
		p->next=head;

		q=head;
		while(q->next!=head){
			q=q->next;
		}
		q->next=p;
	}
	
	p=head;
	int j=peos;
	while(j--){
		for(i=1;i<count-1;++i){
			p=p->next;
		}
		Node* tmp=p->next;
		p->next=tmp->next;
		printf("num:%d  ",tmp->number);
		free(tmp);
		p=p->next;
		}

	return 0;
}
