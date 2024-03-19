#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct USERDATA{
	int nAge;
	char szName[16];
	char szPhone[16];
} userdata;

typedef struct NODE{
	userdata data;
	struct NODE* pNext;
} node;

void createNode(userdata *user){
	node* newNode = (node*)malloc(sizeof(node));
	newNode.data = user;
	newNode->pNext = NULL;
	
	return newNode;
}

int main(){
	node* head = (node*)malloc(sizeof(node));
	head->pNext = NULL;
	head->data.nAge = 26;
	strcpy(head->data.szName, "Daniel");
	strcpy(head->data.szPhone, "010-xxxx-xxx0");

	node* node1 = (node*)malloc(sizeof(node));
	node1->pNext = head->pNext; // node1의 pNext에 NULL을 할당
	head->pNext = node1;
	node1->data.nAge = 28;
	strcpy(node1->data.szName, "David");
	strcpy(node1->data.szPhone, "010-4xxx-xxx0");
	
	//node second = {{28, "David", "010-4xxx-xxx0"}, NULL};
	//node first = {{26, "Daniel", "010-xxxx-xxx0"}, &second};

	node* temp = head;
	while(temp != NULL){
		printf("%s, %d, %s\n", temp->data.szName, temp->data.nAge, temp->data.szPhone);
		temp = temp->pNext;
	}

	free(head);
	free(node1);

	return 1;
}
